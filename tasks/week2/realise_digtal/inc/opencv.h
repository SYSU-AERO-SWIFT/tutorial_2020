#include<opencv2/opencv.hpp>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
using namespace cv;

#define pr 1.98
#define pb 1.20
#define pg 0.23


void red(Mat src, Mat& dst);
void red3(Mat src, Mat& dst);

void Read_to_Binary();
void Read_to_Bianry3();

void draw_Rectangle();       //圈出要识别的数字 

void position();                //计算七个数码管的位置
void realise();                //输出识别结果 


