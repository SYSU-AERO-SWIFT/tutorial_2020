#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<vector>
#include<string>
#include<iostream>
#include"header.h"
using namespace std;
using namespace cv;
int main(int argc, char**argv)
{
	if (argc < 2 || argc>3)
	{
		cout << "请传入一或两张图片！" << endl;
		return -1;
	}
	Mat  src_image, inrange_image, dilate_image, dst_image;
	if (argc == 3)
	{
		Mat src1_image, src2_image;
		double alphaValue = 0.5, betaValue;
		src1_image = imread(argv[1]);
		src2_image = imread(argv[2]);
		if ((!src1_image.data) || (!src2_image.data))//检查输入有效性                             
		{
			cout << "不能找到图像！" << endl;
			return -1;
		}
		//显示原图
		namedWindow("原图1");
		imshow("原图1", src1_image);
		namedWindow("原图2");
		imshow("原图2", src2_image);
		//混合图像
		src_image = src1_image.clone();
		betaValue = 1 - alphaValue;
		addWeighted(src1_image, alphaValue, src2_image, betaValue, 0.0, src_image);
		//显示合并图
		namedWindow("合并图");
		imshow("合并图", src_image);
	}
	else
	{
		src_image = imread(argv[1]);
		if (!src_image.data)//检查输入有效性                             
		{
			cout << "不能打开或找到图像！" <<endl;
			return -1;
		}
		//显示原图
	     namedWindow("原图");
	     imshow("原图", src_image);
	}
	
	//中值滤波
	medianBlur(src_image, src_image,3);
	//二值化
	inRange(src_image, Scalar(0, 0, 170), Scalar(150, 150, 255), inrange_image);
	//膨胀
	Mat element = getStructuringElement(MORPH_RECT, Size(13, 13));
	dilate_image = inrange_image.clone();
	dilate(inrange_image, dilate_image, element);
	//显示关键步骤图
	namedWindow("关键步骤图");
	imshow("关键步骤图", dilate_image);
	//寻找轮廓
	vector<vector<Point>> contours;
	vector <Vec4i> hierarchy;
	findContours(dilate_image, contours, hierarchy, RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	//框出数字
	vector<int>index;
	vector<Rect> rectangle;
	for (int i = 0; i < contours.size(); i++)
	{
		rectangle.push_back(boundingRect(contours[i]));
		if (rectangle[i].height > 92 && rectangle[i].height<200)//通过高度判断框到的是数字还是干扰的白点
		{
			cout <<"第"<<i+1<< "个矩形的高为：" << rectangle[i].height << "   宽为：" << rectangle[i].width << endl;
			index.push_back(i);//存放框住数字的矩形的下标
			Point2f vertex[4];//存放矩形四个点坐标
			vertex[0] = rectangle[i].tl();
			vertex[1].x = vertex[0].x + rectangle[i].width;//右上角横坐标
			vertex[1].y = vertex[0].y;
			vertex[2] = rectangle[i].br();
			vertex[3].x = vertex[0].x;//左下角的横坐标
			vertex[3].y = vertex[2].y;

			for (int i = 0; i < 4; i++)//框出数字
			{
				line(dilate_image, vertex[i], vertex[(i + 1) % 4], Scalar(150, 0, 0), 2, 4);
			}
		}
	}
	//显示框出数字的图片
	namedWindow("框出数字");
	imshow("框出数字", dilate_image);


	//让数字能够按顺序输出，通过矩形左上角的点的横坐标的大小来判断
	for (int i = 0; i < 3; i++)//目的是使index[0]-index[3]分别存放从左到右框住数字的矩形的索引值
	{
		int j, temp;
		for (j = i + 1; j < 4; j++)
			if (rectangle[index[i]].tl().x > rectangle[index[j]].tl().x)
			{
				temp = index[i]; index[i] = index[j]; index[j] = temp;
			}
	}

	//截取图像中的四个数字，存放到四个图片中
	Mat number_image[4];
	for (int i = 0; i < 4; i++)
	{
		Mat ROI = dilate_image(rectangle[index[i]]);
		number_image[i] = ROI.clone();
	}

	//通过自定义函数findNumber()对数字进行识别并输出
	string number = "";
	for (int i = 0; i < 4; i++)
	{
		number = number + find_number(number_image[i]);
	}
	cout << "final result:" << number << endl;
	waitKey(0);
	return 0;

}
