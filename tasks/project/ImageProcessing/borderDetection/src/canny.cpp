#include<opencv2/opencv.hpp>
#include<cmath>

using namespace cv;

void sobel(Mat&, Mat&, Mat&, Mat&, int, int);
void trace(Mat&, Mat&, float, int, int, int, int);

void canny(Mat& input, Mat& edges, double threshold1, double threshold2, int apertureSize, bool L2gradient)
{
	Mat gray;
	//转为灰度图像
	cvtColor(input, gray, CV_RGB2GRAY);
	//高斯滤波
	GaussianBlur(gray, gray, Size(5, 5), 0.8);

	//sobel算子计算水平和垂直方向的导数
	Mat dx, dy, dst;
	sobel(gray, dx, dy, dst, CV_32F, apertureSize);

	Mat edgeMag;
	if (L2gradient)
        	magnitude(dx, dy, edgeMag);
	else
        	edgeMag = abs(dx) + abs(dy);

	Mat edgeMag_noMaxsup = Mat::zeros(gray.rows, gray.cols, CV_32FC1);
	//非极大值抑制
	for (int r = 1; r < gray.rows - 1; r++)
	{
		for (int c = 1; c < gray.cols - 1; c++)
		{
			float x = dx.at<float>(r, c);
			float y = dy.at<float>(r, c);
			float angle = atan2f(y, x) / CV_PI * 180;
			float mag = edgeMag.at<float>(r, c);

			if (std::abs(angle) < 22.5 || std::abs(angle) > 157.5)
			{
				float left = edgeMag.at<float>(r, c - 1);
				float right = edgeMag.at<float>(r, c + 1);
				if (mag >= left && mag >= right)
				{
					edgeMag_noMaxsup.at<float>(r, c) = mag;
				}
			}

			if ((angle >= 67.5 && angle <= 112.5 ) || 
					(angle >= -112.5 && angle <= -67.5))
			{
				float top = edgeMag.at<float>(r - 1, c);
				float down = edgeMag.at<float>(r + 1, c);
				if (mag >= top && mag >= down)
					edgeMag_noMaxsup.at<float>(r, c) = mag;
			}

			if ((angle > 112.5 && angle <= 157.5) || 
					(angle > -67.5 && angle<= -22.5))
			{
				float right_top = edgeMag.at<float>(r - 1, c + 1);
				float left_down = edgeMag.at<float>(r + 1, c - 1);
				if (mag >= right_top && mag >= left_down)
					edgeMag_noMaxsup.at<float>(r, c) = mag;
			}

			if ((angle >= 22.5 && angle < 67.5) || 
					(angle >= -157.5 && angle < -112.5))
			{
				float left_top = edgeMag.at<float>(r - 1, c - 1);
				float right_down = edgeMag.at<float>(r + 1, c + 1);
				if (mag >= left_top && mag >= right_down)
					edgeMag_noMaxsup.at<float>(r, c) = mag;
			}
		}
	}
	
	convertScaleAbs(edgeMag_noMaxsup, edgeMag_noMaxsup);

	//双阈值处理及边缘连接
	edges = Mat::zeros(gray.rows, gray.cols, CV_8UC1);
	for(int r = 1; r < gray.rows - 1; r++)
	{
		for(int c = 1; c < gray.cols - 1; c++)
		{
			float mag = edgeMag_noMaxsup.at<uchar>(r, c);

			if (mag >= threshold2)
				trace(edgeMag_noMaxsup, edges, threshold1, 
						r, c, gray.rows, gray.cols);
			else if (mag < threshold1)
				edges.at<uchar>(r, c) = 0;
		}
	}
}

//阶乘
int factorial(int n)
{
	if(n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

//平滑算子
Mat getSmooth(int ksize)
{
	Mat smoother = Mat::zeros(Size(ksize, 1), CV_32FC1);
	for(int i = 0; i < ksize; i++)
		smoother.at<float>(0, i) = factorial(ksize - 1) / 
			(factorial(i)*factorial(ksize - 1 - i));
	return smoother;
}

//差分算子
Mat getDiff(int ksize)
{
	Mat differ = Mat::zeros(Size(ksize, 1), CV_32FC1);
	Mat smoother = getSmooth(ksize - 1);
	for(int i = 0; i < ksize; i++)
	{
		if(i == 0)
			differ.at<float>(0, i) = 1;
		else if(i == ksize - 1)
			differ.at<float>(0, i) = -1;
		else
			differ.at<float>(0, i) = smoother.at<float>(0, i) - 
				smoother.at<float>(0, i - 1);
	}

	return differ;
}

//卷积
void conv2D(Mat& src, Mat& dst, Mat kernel, int ddepth, Point anchor = Point(-1, -1), int delta = 0)
{
	Mat  kernelFlip;
	flip(kernel, kernelFlip, -1);
	filter2D(src, dst, ddepth, kernelFlip, anchor, delta, BORDER_DEFAULT);
}

//先Y后X
void sepConv2DYX(Mat& src, Mat& dst, Mat kernelY, Mat kernelX, int ddepth, Point anchor = Point(-1, -1), int delta = 0)
{
	cv::Mat dst_kernel_Y;
	conv2D(src, dst_kernel_Y, kernelY, ddepth, anchor, delta);
	conv2D(dst_kernel_Y, dst, kernelX, ddepth, anchor, delta);
}

//先X后Y
void sepConv2DXY(Mat& src, Mat& dst, Mat kernelX, Mat kernelY, int ddepth, Point anchor = Point(-1, -1), int delta = 0)
{
	cv::Mat dst_kernel_X;
	conv2D(src, dst_kernel_X, kernelX, ddepth, anchor, delta);
	conv2D(dst_kernel_X, dst, kernelY, ddepth, anchor, delta);
}

//sobel算子
void sobel(Mat& src, Mat& dstX, Mat& dstY, Mat& dst, int ddepth, int ksize)
{
	Mat smoother = getSmooth(ksize);
	Mat differ = getDiff(ksize);

	sepConv2DYX(src, dstX, smoother.t(), differ, ddepth);
	sepConv2DXY(src, dstY, smoother, differ.t(), ddepth);

	dst = abs(dstX) + abs(dstY);
	convertScaleAbs(dst, dst);
}

//边缘连接
void trace(Mat& edgeMag, Mat& edge, float threshold, int r, int c, int rows, int cols)
{
	if (edge.at<uchar>(r, c) == 0)
	{
		edge.at<uchar>(r, c) = 255;
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				float mag = edgeMag.at<float>(r + i, c + j);
				if (r+i >= 0 && r+i < rows && c+j >= 0 && c+j < cols && 
						mag >= threshold)
					trace(edgeMag, edge, threshold, r + i, c + j, 
							rows, cols);
			}
		}
	}
}

