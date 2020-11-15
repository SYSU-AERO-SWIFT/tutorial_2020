#include "../inc/contours.h"
#include<iostream>

using namespace cv;

int main(int argc, char** argv)
{
	if(argc < 2)
		return -1;
	Mat image = imread(argv[1]);
	if(image.empty())
		return -1;


	Mat edge, edge2;
	canny(image, edge, 20, 60, 3);
/*	Canny(image, edge2, 20, 100);
	imshow("My canny", edge);
	imshow("Canny", edge2);
	waitKey(0);*/

	//Opencv的findContours和drawContours
	std::vector<std::vector<Point>> contour;
	std::vector<Vec4i> hierarchy;
	findContours(edge, contour, hierarchy, RETR_LIST, CHAIN_APPROX_SIMPLE);
	Mat r = Mat::zeros(edge.rows, edge.cols, CV_8UC1);
	drawContours(r, contour, -1, Scalar(255), 1, 8);
	imshow("Opencv", r);

	//自己写的函数
	std::vector<std::vector<Point>> mycontour;
	std::vector<Vec4i> myhierarchy;
	findcontours(edge, mycontour, myhierarchy);
	Mat result(edge.rows, edge.cols, CV_8UC1);
	drawcontours(result, mycontour, -1, 0);
	imshow("My", result);
	waitKey(0);
	return 0;
}
