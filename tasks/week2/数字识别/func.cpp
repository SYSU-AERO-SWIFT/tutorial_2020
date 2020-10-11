#include"header.h"
string find_number(Mat src)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, sum = 0;
	int y_oneThird = src.rows / 3, y_twoThirds = src.rows / 3 * 2;
	int	x_half=src.cols/2, x_twoFifths = src.cols / 5*2;
	if (src.rows > 2 * src.cols)
		return "1";
	else
	{
		//将显示一个数字的数码管分成7个部分，现在先判断三条横线是否点亮
		for (int i = 0; i < y_oneThird; i++)//判断最上面一条横线——a
		{
			uchar * data = src.ptr<uchar>(i);
			if (data[x_twoFifths] == 255)a = 1;
		}
		for (int i = y_oneThird; i < y_twoThirds; i++)//判断中间那条横线——b
		{
			uchar * data = src.ptr<uchar>(i);
			if (data[x_twoFifths] == 255)b = 1;
		}
		for (int i = y_twoThirds; i < src.rows; i++)//判断最下面一条横线——c
		{
			uchar * data = src.ptr<uchar>(i);
			if (data[x_twoFifths] == 255)c = 1;
		}
		//下面判断竖着的四条竖线是否点亮
		//先判断上面两条竖线
		for (int j = 0; j < x_half; j++)//判断左上角的竖线是否点亮——d
		{
			uchar* data = src.ptr<uchar>(y_oneThird);
			if (data[j] == 255)d = 1;
		}
		for (int j = x_half; j < src.cols; j++)//判断右上角的竖线是否点亮——e
		{
			uchar* data = src.ptr<uchar>(y_oneThird);
			if (data[j] == 255)e = 1;
		}
		//再判断下面两条竖线
		for (int j = 0; j < x_half; j++)//判断左下角的竖线是否点亮——f
		{
			uchar * data = src.ptr<uchar>(y_twoThirds);
			if (data[j] == 255)f = 1;
		}
		for (int j = x_half; j < src.cols; j++)//判断右下角的竖线是否点亮——g
		{
			uchar * data = src.ptr<uchar>(y_twoThirds);
			if (data[j] == 255)g = 1;
		}
	}
	//判断数字
	if (a == 1 && b == 0 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1)return "0";
	if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 1 && g == 0)return "2";
	if (a == 1 && b == 1 && c == 1 && d == 0 && e == 1 && f == 0 && g == 1)return "3";
	if (a == 0 && b == 1 && c == 0 && d == 1 && e == 1 && f == 0 && g == 1)return "4";
	if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 0 && g == 1)return "5";
	if (a == 1 && b == 1 && c == 1 && d == 1 && e == 0 && f == 1 && g == 1)return "6";
	if (a == 1 && b == 0 && c == 0 && d == 0 && e == 1 && f == 0 && g == 1)return "7";
	if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 1 && g == 1)return "8";
	if (a == 1 && b == 1 && c == 1 && d == 1 && e == 1 && f == 0 && g == 1)return "9";
         else return "0";//若图片识别不出具体数字则返回0
}
