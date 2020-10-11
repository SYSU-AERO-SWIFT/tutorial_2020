#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
using namespace cv;

//获取坐标在x，y处的像素值
int getPixelValues(Mat imageFinal, int x, int y);
//判断（x1，y1）到（x2，y2）这条线的是否有像素点
bool cross(Mat imageFianl, int x1, int y1, int x2, int y2);
//读取数字
string getNum(Mat image);
//旋转图像（功能未使用）
void Rotate(Mat srcImage, Mat destImage, double angle, Point2f center);//图像旋转
//轮廓按照面积大小降序排序
bool ascendSort(vector<Point> a, vector<Point> b);
//按照x坐标对识别区域进行左右排序
bool ascendSort1(Rect a, Rect b);
//返回图像red直方图的最大值点
int histMax(Mat src);
//去除二值图当中小于area面积的像素块
void filterArea(Mat imageBinary, int area);
