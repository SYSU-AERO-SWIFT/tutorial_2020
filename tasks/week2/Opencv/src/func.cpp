#include"opencv.h"

Mat img, img1, gray, binary;

Mat input1, Input1, input2, Input2, gray1, gray2;

vector<Rect>RECT(10);              //边框矩阵


unsigned int x_position[7][4]{ 0 };
unsigned int y_position[7][4]{ 0 };

void get()
{
	string A;
	cout << "请输入图片的路径:" << endl;
	cin >> A;
	img = imread(A);
	if (img.empty())
	{
		cout << "ERROR" << endl;
		return;
	}
}
void Read_to_Binary()
{
	
	imshow("input", img);
	medianBlur(img, img, 7); //中值滤波
	bilateralFilter(img, img1, -1, 45, 45);//双边滤波,突显边缘
	imshow("blur & bilaterfilter", img1);
	get_red(img1, gray); //筛选出红色
	imshow("gray", gray);
	threshold(gray, gray, 120, 255, THRESH_TOZERO);       //自动阈值化
	threshold(gray, gray, 0, 255, THRESH_OTSU);           //自动阈值化
	Mat element2 = getStructuringElement(MORPH_RECT, Size(11, 11));
	morphologyEx(gray, binary, CV_MOP_CLOSE, element2);                           //形态学操作
	imshow("kaibi", binary);
}

void get3()
{
	string A;
	cout << "请输入第一张图片的路径:" << endl;
	cin >> A;
	string B;
	cout << "请输入第二张图的路径:" << endl;
	cin >> B;
	input1 = imread(A);
	input2 = imread(B);
	if (input1.empty() || input2.empty())
	{
		cout << "can't read two photos,error" << endl;
		return;
	}
}
void Read_to_Bianry3()
{
	//滤波
	imshow("input1", input1);
	imshow("input2", input2);
	medianBlur(input1, input1, 7);
	medianBlur(input2, input2, 7);//进行中值滤波
	bilateralFilter(input1, Input1, -1, 45, 45);
	bilateralFilter(input2, Input2, -1, 45, 45);//进行双边滤波,突显边缘
	imshow("bilateralFilter1", Input1);
	imshow("bilateralFilter2", Input2);

	//筛选出红色
	get_red3(Input1, gray1);
	get_red3(Input2, gray2);
	imshow("gray1", gray1);
	imshow("gray2", gray2);


	if (!gray1.data | !gray2.data)
	{
		cout << "ERROR" << endl;
		return;
	}


	//自动阈值处理
	threshold(gray1, gray1, 0, 255, THRESH_OTSU);
	threshold(gray2, gray2, 0, 255, THRESH_OTSU);
	imshow("threshold1", gray1);
	imshow("threshold2", gray2);


	//合并图像
	addWeighted(gray1, 0.5, gray2, 0.5, 0, gray);
	imshow("mixed", gray);
	



	//二值化
	threshold(gray, gray, 0, 255, THRESH_OTSU);
	Mat element1 = getStructuringElement(MORPH_RECT, Size(5, 5));
	Mat element2 = getStructuringElement(MORPH_RECT, Size(13, 13));
	morphologyEx(gray, binary, CV_MOP_OPEN, element1);
	morphologyEx(binary, binary, CV_MOP_CLOSE, element2);
	imshow("binary", binary);//显示图像
}


void get_Rectangle()
{
	//识别轮廓
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	int size_rect = contours.size();

	vector<vector<Point> > contoursRect(size_rect);
	vector<Rect> boundRect(size_rect);


	//逼近指定点集
	for (unsigned int i = 0; i < size_rect; i++)
	{
		approxPolyDP(Mat(contours[i]), contoursRect[i], 3, true);
		boundRect[i] = boundingRect(Mat(contoursRect[i]));
	}


    //将数字框出
	Mat drawing = Mat::zeros(binary.size(), CV_8UC3);
	for (int unsigned i = 0; i < size_rect; i++)
	{
		Scalar color = Scalar(255, 125, 90);
		drawContours(drawing, contoursRect, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(binary, boundRect[i].tl(), boundRect[i].br(), color, 5, 8, 0);
	}
	imshow("get", binary);//获得图像


	int* length = new int[size_rect];
	int* width = new int[size_rect];

	int j = 0;


	//识别正确的数字矩形框
	for (int i = 0; i < size_rect; i++)
	{
		length[i] = boundRect[i].br().y - boundRect[i].tl().y;
		width[i] = boundRect[i].br().x - boundRect[i].tl().x;

		if ((1.0 * length[i] / width[i] > 1.4 && 1.0 * length[i] / width[i] < 3.2) || (1.0 * length[i] / width[i] > 4 && 1.0 * length[i] / width[i] < 8.0))
		{
			RECT[j] = boundRect[i];
			j++;
			if (i + 1 == size_rect)break;
			if ((boundRect[i].tl().x - boundRect[i + 1].tl().x) * (boundRect[i].br().x - boundRect[i + 1].br().x) < 0)
				i++;
		}
		else;
	}


	//将获得的数字矩形框按照坐标排序
	Rect rect2;           
	for (int j = 0; j < 4; j++)
	{
		for (int i = j; i < 4; i++)
		{
			if (RECT[j].br().x > RECT[i].br().x)
			{
				rect2 = RECT[i];
				RECT[i] = RECT[j];
				RECT[j] = rect2;
			}
			else;
		}
	}
}


//获得数据点的坐标
void position()
{
	for (int j = 0; j < 4; j++)
	{
		x_position[0][j] = 0.5 * (1.0 * RECT[j].br().x + RECT[j].tl().x);
		y_position[0][j] = RECT[j].tl().y + 1.0 / 16 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[1][j] = RECT[j].br().x - 1.0 / 8 * (1.0 * RECT[j].br().x - RECT[j].tl().x);
		y_position[1][j] = RECT[j].tl().y + 1.0 / 4 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[2][j] = RECT[j].br().x - 1.0 / 8 * (1.0 * RECT[j].br().x - RECT[j].tl().x);
		y_position[2][j] = RECT[j].tl().y + 3.0 / 4 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[3][j] = x_position[0][j];
		y_position[3][j] = RECT[j].br().y - 1.0 / 16 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[4][j] = RECT[j].tl().x + 1.0 / 8 * (1.0 * RECT[j].br().x - RECT[j].tl().x);
		y_position[4][j] = RECT[j].tl().y + 3.0 / 4 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[5][j] = RECT[j].tl().x + 1.0 / 8 * (1.0 * RECT[j].br().x - RECT[j].tl().x);
		y_position[5][j] = RECT[j].tl().y + 1.0 / 4 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

		x_position[6][j] = RECT[j].tl().x + 0.5 * (1.0 * RECT[j].br().x - RECT[j].tl().x);
		y_position[6][j] = RECT[j].tl().y + 0.5 * (1.0 * RECT[j].br().y - RECT[j].tl().y);

	}
}

//判断数字
void realise()
{
	//识别
	int realise[7][4]{ 0 };
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < 7; i++)
		{
			if (binary.at<uchar>(unsigned(y_position[i][k]), unsigned(x_position[i][k])) > 0)
			{
				realise[i][k] = 1;
			}
			else;
		}
	}
	cout << "读取图片数字如下：" << endl;

	for (int k = 0; k < 4; k++)
	{
		if ((1.0 * RECT[k].br().y - RECT[k].tl().y) / (1.0 * RECT[k].br().x - RECT[k].tl().x) > 4.0)
			cout << 1;
		else if (realise[0][k] * realise[1][k] * realise[2][k] * realise[3][k] * realise[4][k] * realise[5][k] * realise[6][k] == 1)
			cout << 8;
		else if (realise[0][k] * realise[2][k] * realise[3][k] * realise[4][k] * realise[5][k] * realise[6][k] == 1)
			cout << 6;
		else if (realise[0][k] * realise[1][k] * realise[2][k] * realise[3][k] * realise[5][k] * realise[6][k] == 1)
			cout << 9;
		else if (realise[0][k] * realise[1][k] * realise[2][k] * realise[3][k] * realise[4][k] * realise[5][k] == 1)
			cout << 0;
		else if (realise[0][k] * realise[1][k] * realise[3][k] * realise[4][k] * realise[6][k] == 1)
			cout << 2;
		else if (realise[0][k] * realise[2][k] * realise[3][k] * realise[5][k] * realise[6][k] == 1)
			cout << 5;
		//else if (realise[1][k] * realise[2][k] * realise[3][k] * realise[4][k] * realise[5][k] == 1)
		//	cout << "";
		else if (realise[1][k] * realise[2][k] * realise[5][k] * realise[6][k] == 1)
			cout << 4;
		else if (realise[0][k] * realise[1][k] * realise[2][k] * realise[3][k] * realise[6][k] == 1)
			cout << 3;
		else if (realise[0][k] * realise[1][k] * realise[2][k] == 1)
			cout << 7;
		else
			cout << -1;

	}

}

//图像处理
void get_red(Mat src, Mat& dst)
{
	int rows = src.rows;
	int cols = src.cols;
	dst = Mat::zeros(src.size(), CV_8UC1);

	for (int row = 0; row < rows; row++) {
		uchar* p = src.ptr<uchar>(row);
		for (int col = 0; col < cols; col++) {
			if (row<rows * 0.1 || row>rows * 0.9 || col<cols * 0.04 || col>cols * 0.96)  continue;
			if (!(p[col * 3] < 230) && (p[col * 3 + 1] < 50 || p[col * 3 + 1]>110) && p[col * 3] > 100)  continue;
			dst.at<uchar>(row, col) = saturate_cast<uchar>(p[col * 3 + 2] * pr - 60 - p[col * 3] * pb - p[col * 3 + 1] * pg); ///三通道权值组成灰度图像
		}
	}
}


//图像处理
void get_red3(Mat src, Mat& dst)
{
	int rows = src.rows;
	int cols = src.cols;
	dst = Mat::zeros(src.size(), CV_8UC1);

	for (int row = 0; row < rows; row++)
	{
		uchar* p = src.ptr<uchar>(row);
		for (int col = 0; col < cols; col++)
		{
			dst.at<uchar>(row, col) = saturate_cast<uchar>(p[col * 3 + 2] * pr - 60 - p[col * 3] * pb - p[col * 3 + 1] * pg); ///三通道权值组成灰度图像
		}
	}
}
