#include<iostream>
#include<algorithm>
#include<iterator>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void myPreprocess( Mat &image );

void myBinarization( Mat &src, Mat &ret);

void myMorphology( Mat &src );

void myContours( Mat &src, vector<Rect> &edge);

void myNumDivision( Mat &src, vector<Rect> &edge, vector<Mat> &ret);

void myDiscern( Mat &src );