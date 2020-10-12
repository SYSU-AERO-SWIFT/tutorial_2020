#include<opencv2/opencv.hpp>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
using namespace cv;

#define pr 1.98
#define pb 1.20
#define pg 0.23


void get_red(Mat src, Mat& dst);
void get_red3(Mat src, Mat& dst);

void get();
void get3();

void Read_to_Binary();
void Read_to_Bianry3();

void get_Rectangle();       //用矩形框住数码管显示的数字

void position();                //获得几个特殊点的位置，用来判断数码管的状况
void realise();                //根据识别结果判断数字并将其输出
