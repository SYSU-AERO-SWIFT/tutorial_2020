#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>
#include<vector>
#include<string>
#include"recognition.h"
using namespace std;
using namespace cv;

bool compareRect(Rect& a, Rect& b)
{
	return (a.x < b.x);
}
void recognition(Mat& src)
{
    bool a = true, b = true, c = true, d = true, e = true, f = true, g = true;
    int vertical = src.cols / 2;
	int horizonal_up = src.rows / 3;
	int horizonal_down = src.rows / 3 * 2;
	if (src.rows > 2 * src.cols)
	{
			cout << '1';
            return;
	}
	for (int i = 0; i < src.rows; i++)
	{
		uchar* row = src.ptr(i);
		if (row[vertical])
		{
			if (i < horizonal_up)
			{
				a = false;
			}
			else if (i < horizonal_down)
			{
				g = false;
			}
			else
			{
				d = false;
			}
		}
	}
	uchar* col_up = src.ptr(horizonal_up), *col_down = src.ptr(horizonal_down);
	for (int i = 0; i < src.cols; i++)
	{
		if (col_up[i])
		{
			if (i < vertical)
			{
				f = false;
			}
			else
			{
				b = false;
			}
		}
		if (col_down[i])
		{
			if (i < vertical)
			{
				e = false;
			}
			else
			{
				c = false;
			}
		}
	}
    if (a)
    {
        cout << '4';
    }
    else if (c)
    {
        cout << '2';
    }
    else if (d)
    {
        cout << '7';
    }
    else if (g)
    {
        cout << '0';
    }
    else if (f)
    {
        cout << '3';
    }
    else if (b && e)
    {
        cout << '5';
    }
    else if (b)
    {
        cout << '6';
    }
    else if (e)
    {
        cout << '9';
    }
    else
    {
        cout << '8';
    }
}
Mat preprocess(Mat& src)
{
	Mat& imgInput = src;
	vector<Mat> channelsInput;
	split(imgInput, channelsInput);
	Mat r_channelInput = channelsInput.at(2).clone();
	imshow("Red Channel of Input Image", r_channelInput);
	waitKey(0);
	destroyWindow("Red Channel of Input Image");
	Mat r_channelGauss;
	GaussianBlur(r_channelInput, r_channelGauss, Size(11, 11), 0);
	imshow("Red Channel after Gauss Blur", r_channelGauss);
	waitKey(0);
	destroyWindow("Red Channel after Gauss Blur");
	Mat r_channelBinary;
	threshold(r_channelGauss, r_channelBinary, 200, 255, THRESH_BINARY);
	imshow("Red Channel after Threshold", r_channelBinary);
	waitKey(0);
	destroyWindow("Red Channel after Threshold");
	Mat morphology;
	Mat kernelOpen = getStructuringElement(MORPH_RECT, Size(7, 7));
	morphologyEx(r_channelBinary, morphology, MORPH_OPEN, kernelOpen);
	imshow("Morphology Opening", morphology);
	waitKey(0);
	destroyWindow("Morphology Opening");
	Mat kernelDilate = getStructuringElement(MORPH_RECT, Size(20, 20));
	//Mat kernelErode = getStructuringElement(MORPH_RECT, Size(15, 15));
	dilate(morphology, morphology, kernelDilate);
	//erode(morphology, morphology, kernelErode);
	imshow("Morphology Closing", morphology);
	waitKey(0);
	destroyWindow("Morphology Closing");
	return morphology;
}
vector<Rect> findNumbers(Mat& src)
{
	Mat& morphology = src;
	vector<vector<Point>> contours;
	vector<Rect> numbers;
	findContours(morphology, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	double point_average = 0.0;
	for (vector<vector<Point>>::iterator iter = contours.begin(); iter != contours.end(); ++iter)
	{
		if ((*iter).size() > 30)
		{
			numbers.push_back(boundingRect(*iter));
		}
	}
	sort(numbers.begin(), numbers.end(), compareRect);
	return numbers;
}