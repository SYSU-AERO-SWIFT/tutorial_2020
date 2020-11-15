#include<opencv2/opencv.hpp>
#include<cmath>

using namespace cv;

//绘制轮廓
void drawcontours(Mat& output, std::vector<std::vector<Point>>& contours, int number, int lineWidth)
{
	if(contours.empty())
		return;
	output.create(output.rows, output.cols, CV_8UC1);
	output.setTo(Scalar(0));
	
	//如果序号值等于-1，绘制出所有轮廓
	if(number == -1)
	{
		for(int i = 1; i < contours.size(); i++)
		{
			for(int j = 0; j < contours[i].size(); j++)
			{
				output.at<uchar>(contours[i][j].x, contours[i][j].y) = 255;
				for(int k = 1; k <= lineWidth; k++)
				{
					output.at<uchar>(contours[i][j].y + k, 
							contours[i][j].x) = 255;
					output.at<uchar>(contours[i][j].y - k, 
							contours[i][j].x) = 255;
					output.at<uchar>(contours[i][j].y, 
							contours[i][j].x + k) = 255;
					output.at<uchar>(contours[i][j].y, 
							contours[i][j].x - k) = 255;
				}
			}
		}
	}
	//如果序号值大于或等于0，绘制出对应序号的轮廓
	else
	{
		for(int j = 0; j < contours[number].size(); j++)
		{
			output.at<uchar>(contours[number][j].x, contours[number][j].y) = 255;
			for(int k = 1; k <= lineWidth; k++)
			{
				output.at<uchar>(contours[number][j].y + k, 
						contours[number][j].x) = 255;
				output.at<uchar>(contours[number][j].y - k, 
						contours[number][j].x) = 255;
				output.at<uchar>(contours[number][j].y, 
						contours[number][j].x + k) = 255;
				output.at<uchar>(contours[number][j].y, 
						contours[number][j].x - k) = 255;
			}
		}
	}
}
