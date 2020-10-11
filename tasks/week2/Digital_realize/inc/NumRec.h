#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>
#include<string>

using namespace std;
using namespace cv;

#define pr 2.02
#define pb 1.22
#define pg 0.25

//void filter_max(Mat src, Mat &dst);//最大值滤波


void search_red(Mat src, Mat& dst);
void search_red3(Mat src, Mat& dst);

class NumRec {
public:

	NumRec(const string); //初始化时读取1个图像
	NumRec(const string,const string);

	void numGet(); // 把图片所包含的数码管数字凸显并分割出来，然后用矩形框套上并输出数据

private:
	void numShow(); //图像处理
	void numRead(); //读取数字

private:
	Mat img1;
	Mat img2;
	Mat binary;
	bool mix;
};
