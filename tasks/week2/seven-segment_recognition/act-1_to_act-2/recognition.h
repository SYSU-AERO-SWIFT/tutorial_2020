#ifndef RECOGNITION
#define RECOGNITION
#include<iostream>
#include<string>
#include<vector>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;
void recognition(Mat&);
Mat preprocess(Mat&);
vector<Rect> findNumbers(Mat&);
#endif