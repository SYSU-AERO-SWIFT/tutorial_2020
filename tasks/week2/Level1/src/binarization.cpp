#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;

//最小值滤波器
void minFilter(Mat&, Mat&, int, int);

Mat binarization(const Mat& input)
{
	//转换到hsv色彩空间，根据饱和度通道的均值分别采用两种处理方式
	Mat hsv;
	cvtColor(input, hsv, CV_BGR2HSV);
	std::vector<Mat> channels;
	split(hsv, channels);
	Mat s = channels[1];
	Scalar m;
	Scalar v;
	meanStdDev(s, m, v);
	Mat result;

	if(v.val[0] > 55)
	{
		s.convertTo(s, CV_8U, 1, 0);
                Mat a;
		equalizeHist(s, a);
		Mat b;
		minFilter(a, b, 1, 3);
		morphologyEx(b, a, CV_MOP_OPEN, Mat(), Point(-1, -1), 1);
		threshold(a, b, 110, 255, CV_THRESH_BINARY);
		dilate(b, a, Mat(), Point(-1, -1), 4);
		morphologyEx(a, result, CV_MOP_OPEN, Mat(), Point(-1, -1), 6);
	}
	else
	{
		std::vector<Mat> channels;
		split(input, channels);
		Mat r = channels[2];
		threshold(r, r, 180, 255, CV_THRESH_BINARY);
		dilate(r, result, Mat(), Point(-1, -1), 3);
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
