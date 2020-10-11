#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
using namespace cv;

#include"digital_opencv.h"


int main()
{
	Mat imageSource, imageBinary;
	Mat src_1 = imread("act_sample1.jpg");
	Mat src_2 = imread("2.jpg");
	if (!src_2.empty())
	{
		Mat dstImage_1, dstImage_2;
		GaussianBlur(src_1, src_1, Size(3, 3), 1, 1);
		GaussianBlur(src_2, src_2, Size(3, 3), 1, 1);
		inRange(src_1, Scalar(0, 0, 200), Scalar(150, 170, 256), dstImage_1);

		inRange(src_2, Scalar(0, 0, 200), Scalar(150, 170, 256), dstImage_2);

		if ((dstImage_1.size() == dstImage_2.size()) && (dstImage_1.type() == dstImage_2.type()))
		{
			imageBinary = dstImage_1 + dstImage_2;
			filterArea(imageBinary, 50);
			namedWindow("scr");
			imshow("scr", imageBinary);
		}
		else
		{
			cout << "无法合并";
			return 0;
		}
	}
	else
	{
		imageSource = src_1;
		if (imageSource.empty())
		{
			cout << "Can't open the image.";
			return -1;
		}
		//namedWindow("原图");
		//imshow("原图", imageSource);
		GaussianBlur(imageSource, imageSource, Size(5, 5), 1, 1);
		int histMaxValue = histMax(imageSource);
		if (histMaxValue < 80)
		{
			inRange(imageSource, Scalar(0, 0, 170), Scalar(200, 200, 254), imageBinary);
		}
		else
		{
			inRange(imageSource, Scalar(0, 0, 210), Scalar(200, 200, 254), imageBinary);
		}
		//筛选
		//namedWindow("二值化");
		//imshow("二值化", imageBinary);
	}
	
	//filterArea(imageBinary, 10);
	
	Mat imageDilate;
	Mat element = getStructuringElement(MORPH_RECT, Size(11, 17));//获取核
	dilate(imageBinary, imageDilate, element); //膨胀

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	Mat image = imageDilate.clone();
	findContours(imageDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point> > contoursPoly(contours.size());  //筛选点
	vector<Rect> boundRect(contours.size());
	vector<Rect> boundRectOrder(contours.size());

	for (unsigned int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contoursPoly[i], 3, true);//减少绘制图形所用的点
		boundRect[i] = boundingRect(Mat(contoursPoly[i]));  //包含轮廓点的最小矩形
	}
	Mat drawing = Mat::zeros(imageDilate.size(), CV_8UC3);

	int max = 0;
	for (int unsigned i = 0; i < contours.size(); i++)
	{
		drawContours(drawing, contoursPoly, i, Scalar(100), 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(imageDilate, boundRect[i].tl(), boundRect[i].br(), Scalar(100), 2, 8, 0);
	}

	//namedWindow("二值图膨胀后");
	//imshow("二值图膨胀后", imageDilate);
	sort(boundRect.begin(), boundRect.end(), ascendSort1);

	for (int unsigned i = 0; i < boundRect.size(); i++)
	{
		Mat final;
		final = image(boundRect[i]);
		

		if ((double(boundRect[i].height) / double(boundRect[i].width)) > 2.5&& (double(boundRect[i].height) / double(boundRect[i].width) <8))
		{

			string num = "1";

			cout << num;
		}
		else if ((double(boundRect[i].height) / double(boundRect[i].width)) > 1.45 && (double(boundRect[i].height) / double(boundRect[i].width)) < 2.4)
		{

			string num;
			num = getNum(final);
			cout << num;
		}
	}

	waitKey(0);

	return 0;

}

//使用穿线法
bool cross(Mat imageFianl, int x1, int y1, int x2, int y2)  //（x1，y1）（x2，y2）分别是线的起点和终点

{

	if (x1 == x2)                                         //如果该线是竖线
	{
		for (int y = y1; y < y2; y++)
		{
			if (getPixelValues(imageFianl, x1, y))return true; //只要该区域有一个像素值是255则可认为该区域有数码管
		}
		return false;
	}
	else
	{
		for (int x = x1; x < x2; x++)
		{
			if (getPixelValues(imageFianl, x, y1))return true;
		}
		return false;

	}

}




string getNum(Mat imageFinal)
{


	int h = imageFinal.rows;
	int w = imageFinal.cols;
	string result = "";

	bool a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0;



	if (cross(imageFinal, int(0.5*w), 0, int(0.5*w), int(0.25*h)))
		a1 = true;

	if (cross(imageFinal, 0, int(0.25*h), int(0.5*w), int(0.25*h)))
		a2 = true;

	if (cross(imageFinal, int(0.5*w), int(0.25*h), int(w), int(0.25*h)))
		a3 = true;

	if (cross(imageFinal, int(0.5*w), int(0.25*h), int(0.5*w), int(0.75*h)))
		a4 = true;

	if (cross(imageFinal, 0, int(0.75*h), int(0.5*w), int(0.75*h)))
		a5 = true;

	if (cross(imageFinal, int(0.5*w), int(0.75*h), int(w), int(0.75*h)))
		a6 = true;

	if (cross(imageFinal, int(0.5*w), int(0.75*h), int(0.5*w), int(h)))
		a7 = true;



	if ((!getPixelValues(imageFinal, w*0.5, h*0.25)) && (!getPixelValues(imageFinal, w*0.5, h*0.75)))  //判断中线处0.25和0.75处是否是空白的
	{
		if (a1 != 0 && a2 == 0 && a3 != 0 && a4 != 0 && a5 != 0 && a6 == 0 && a7 != 0) result = "2";
		else if (a1 != 0 && a2 == 0 && a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0 && a7 != 0) result = "3";
		else if (a1 == 0 && a2 != 0 && a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0 && a7 == 0) result = "4";
		else if (a1 != 0 && a2 != 0 && a3 == 0 && a4 != 0 && a5 == 0 && a6 != 0 && a7 != 0) result = "5";
		else if (a1 != 0 && a2 != 0 && a3 == 0 && a4 != 0 && a5 != 0 && a6 != 0 && a7 != 0) result = "6";
		else if (a1 != 0 && a2 == 0 && a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0 && a7 == 0) result = "7";
		else if (a1 != 0 && a2 == 0 && a3 != 0 && a4 == 0 && a5 == 0 && a6 != 0 && a7 != 0) result = "7";
		else if (a1 != 0 && a2 != 0 && a3 != 0 && a4 != 0 && a5 != 0 && a6 != 0 && a7 != 0) result = "8";
		else if (a1 != 0 && a2 != 0 && a3 != 0 && a4 != 0 && a5 == 0 && a6 != 0 && a7 != 0) result = "9";
		else if (a1 != 0 && a2 != 0 && a3 != 0 && a4 == 0 && a5 != 0 && a6 != 0 && a7 != 0) result = "0";
		else result = "";

	}
	return result;

}

bool ascendSort(vector<Point> a, vector<Point> b) {
	return a.size() < b.size();
}

bool ascendSort1(Rect a, Rect b) {
	return a.tl().x < b.tl().x;
}

int getPixelValues(Mat imageGray, int x, int y)
{

	int w = imageGray.cols;     //计算宽度宽度

	Mat_<uchar>::iterator it = imageGray.begin<uchar>();//使用迭代器访问每个像素的信息，it储存第一个像素地址

	Mat_<uchar>::iterator itend = imageGray.end<uchar>();
	int pixel = *(it + y * w + x);               //通过加上y*w识别第y行，加x，识别第y行第x个像素位置
	return pixel;                                 //返回该位置像素值
}

void Rotate(Mat srcImage, Mat destImage, double angle, Point2f center)
{

	Mat M = getRotationMatrix2D(center, -angle, 1);//计算旋转的仿射变换矩阵 
	warpAffine(srcImage, destImage, M, Size(srcImage.cols, srcImage.rows));//仿射变换  
}

int  histMax(Mat src)
{
	vector<Mat> bgr_planes;
	split(src, bgr_planes);
	int histSize = 256;
	float range[] = { 0,256 };
	const float *histRanges = { range };
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRanges, true, false);
	int histH = 400;
	int histW = 512;
	int bin_w = histW / histSize;
	Mat histImage(histW, histH, CV_8UC3, Scalar(0, 0, 0));

	double histMax = 0;
	double maxVal = 0;
	Point maxLoc;
	minMaxLoc(r_hist, NULL, &maxVal, NULL, &maxLoc);
	return int(maxLoc.y);
}

void filterArea(Mat imageBinary, int area)
{
	vector< vector< Point> > contours_All;  //用于保存所有轮廓信息  
	vector< vector< Point> > contours_Less; //用于保存面积不足100的轮廓  
	vector<Point> tempV;              //暂存的轮廓  

	findContours(imageBinary, contours_All, RETR_LIST, CHAIN_APPROX_NONE);
	//轮廓按照面积大小进行升序排序  
	sort(contours_All.begin(), contours_All.end(), ascendSort);//升序排序  
	vector<vector<Point> >::iterator itc = contours_All.begin();
	int i = 0;
	while (itc != contours_All.end())
	{
		//获得轮廓的矩形边界  
		Rect rect = boundingRect(*itc);
		int x = rect.x;
		int y = rect.y;
		int w = rect.width;
		int h = rect.height;


		if (itc->size() < area)
		{
			//把轮廓面积不足100的区域，放到容器contours2中，  
			tempV.push_back(Point(x, y));
			tempV.push_back(Point(x, y + h));
			tempV.push_back(Point(x + w, y + h));
			tempV.push_back(Point(x + w, y));
			contours_Less.push_back(tempV);

			//contours2.push_back(*itc);  

			//删除轮廓面积不足100的区域，即用黑色填充轮廓面积不足100的区域：  
			drawContours(imageBinary, contours_Less, -1, Scalar(0, 0, 0), FILLED);
		}
		//保存图片  
		tempV.clear();
		++itc;
	}
	namedWindow("二值化");
	imshow("二值化", imageBinary);
}
