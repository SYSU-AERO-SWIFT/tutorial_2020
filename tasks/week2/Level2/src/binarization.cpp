#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;

//最小值滤波器
void minFilter(Mat&, Mat&, int, int);

Mat binarization(const Mat& input)
{
	//转换到hsv色彩空间根据饱和度通道的的方差分别做两种处理
	Mat hsv;
	cvtColor(input, hsv, CV_BGR2HSV);
	std::vector<Mat> channels;
	split(hsv, channels);
	Mat s = channels[1];
	
	Scalar m;
	Scalar v;
	meanStdDev(s, m, v);

	//BGR红色通道	
	std::vector<Mat> bgr;
	split(input, bgr);
	Mat r = bgr[2];
	Mat result;

	if(m.val[0] < 100)
	{
		minFilter(r, result, 1, 2);
		morphologyEx(result, r, CV_MOP_OPEN, Mat(), Point(-1, -1), 2);
		threshold(r, result, 180, 255, CV_THRESH_BINARY);
		morphologyEx(result, r, CV_MOP_OPEN, Mat(), Point(-1, -1), 2);
		dilate(r, result, Mat(), Point(-1, -1), 2);
	}
	else
	{
		threshold(r, r, 210, 255, CV_THRESH_BINARY);
		dilate(r, result, Mat(), Point(-1, -1), 4);
	}

	return result;
}

void minFilter(Mat& in, Mat& out, int k, int num)
{
	Mat image;
	out = in.clone();
	for(int t = 0; t < num; t++)
	{
		copyMakeBorder(out, image, k, k, k, k, IPL_BORDER_CONSTANT, Scalar(0));
		for(int i = 0; i < in.rows; i++)
		{
			for(int j = 0; j < in.cols; j++)
			{
				uchar min = image.at<uchar>(i, j);
				for(int m = i - k; m <= i + k; m++)
				{
					for(int n = j - k; n <= j + k; n++)
					{
						if(image.at<uchar>(m, n) < min)
							min = image.at<uchar>(m, n);
					}
				}
				out.at<uchar>(i, j) = min;
			}
		}
	}
}
