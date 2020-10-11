#include"NumRec.h"



NumRec::NumRec(const string name) {
	img1 = imread(name,1);
	mix = 0;
}

NumRec::NumRec(const string name1,const string name2) {
	img1 = imread(name1, CV_LOAD_IMAGE_COLOR);
	img2 = imread(name2, 1);
	mix = 1;
}

void NumRec::numGet() {
	numShow();
	numRead();
}
void NumRec::numShow() {
	if (mix) {

		//滤波
		medianBlur(img1, img1, 7); //中值滤波
		medianBlur(img2, img2, 7);
		Mat Img1, Img2;
		bilateralFilter(img1, Img1, -1, 45, 45);
		bilateralFilter(img2, Img2, -1, 45, 45);//双边滤波,突显边缘
		imshow("filter1", Img1);
		imshow("filter2", Img2);

		//筛选出红色
		Mat gray1, gray2;
		search_red3(Img1, gray1);
		search_red3(Img2, gray2);
		imshow("gray1", gray1);
		imshow("gray2", gray2);


		//合并且二值化
		threshold(gray1, gray1, 0, 255, THRESH_OTSU);
		threshold(gray2, gray2, 0, 255, THRESH_OTSU);
		Mat gray;
		addWeighted(gray1, 0.5, gray2, 0.5, 0, gray);
		threshold(gray, gray, 0, 255, THRESH_OTSU);
		Mat element1 = getStructuringElement(MORPH_RECT, Size(5, 5));
		morphologyEx(gray, binary, CV_MOP_OPEN, element1);
		Mat element2 = getStructuringElement(MORPH_RECT, Size(13, 13));
		morphologyEx(binary, binary, CV_MOP_CLOSE, element2);
		imshow("binary", binary);
	}

	else {
		//经过滤波处理噪声
		medianBlur(img1, img1, 7); //中值滤波
		Mat img;
		bilateralFilter(img1, img, -1, 40, 40);//双边滤波,突显边缘
		imshow("filter", img);
		Mat gray;
		//筛选出红色通道作为灰度
		search_red(img, gray);
		imshow("gray", gray);

		//把图像二值化,凸显数字
		threshold(gray, gray, 120, 255, THRESH_TOZERO);
		threshold(gray, gray, 120, 255, THRESH_OTSU);
		Mat element2 = getStructuringElement(MORPH_ELLIPSE, Size(11, 11));
		Mat element3 = getStructuringElement(MORPH_RECT, Size(11, 11));
		Mat element4 = getStructuringElement(MORPH_RECT, Size(1, 15));
		morphologyEx(gray, binary, CV_MOP_CLOSE, element2);
		morphologyEx(binary, binary, CV_MOP_CLOSE, element3);
		morphologyEx(binary, binary, CV_MOP_CLOSE, element4);
		imshow("binary", binary);
	}
}

void NumRec::numRead() {

	//寻找轮廓并找到数字所在的矩形
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
	unsigned size_rect = contours.size();
	vector<vector<Point> > contoursRect(size_rect);
	vector<Rect> boundRect(size_rect);
	for (unsigned  i = 0; i < size_rect; i++)
	{
		approxPolyDP(Mat(contours[i]), contoursRect[i], 3, true);
		boundRect[i] = boundingRect(Mat(contoursRect[i]));
	}
//把数字所在位置框出
	Mat drawing = Mat::zeros(binary.size(), CV_8UC3);
	Mat img;
	if(mix){
	addWeighted(img1, 0.5, img2, 0.5, 10, img);	
	}
	for (int unsigned i = 0; i < size_rect; i++)
	{
		Scalar color = Scalar(255, 120, 120);
		drawContours(drawing, contoursRect, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		if (mix) {
			
			
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), color, 5, 8, 0);
			imshow("Rect", img);
		}
		else {
			rectangle(img1, boundRect[i].tl(), boundRect[i].br(), color, 5, 8, 0);
			imshow("Rect", img1);
		}
	}
	

	//筛选是数字的矩形
	vector<Rect>RECT(20);
	int* length = new int[size_rect];
	int* width = new int[size_rect];
	int j = 0;
	for (int i = 0; i < size_rect; i++)
	{
		length[i] = boundRect[i].br().y - boundRect[i].tl().y;
		width[i] = boundRect[i].br().x - boundRect[i].tl().x;

		if (1.0 * length[i] / width[i] > 1.4 && 1.0 * length[i] / width[i] < 11.0)
		{
			RECT[j] = boundRect[i];
			j++;
			if (i + 1 == size_rect)break;
			if ((boundRect[i].tl().x - boundRect[i + 1].tl().x) * (boundRect[i].br().x - boundRect[i + 1].br().x) < 0)
				i++;
		}
		else;
	}

	//对数字进行排序
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

	//获取数字的位置
	unsigned int x_position[7][4]{ 0 };
	unsigned int y_position[7][4]{ 0 };
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

	//识别数字
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
				
		else if (realise[0][k] * realise[1][k] * realise[2][k] * realise[3][k] * realise[6][k] == 1)
			cout << 3;
		else if (realise[0][k] * realise[1][k] * realise[2][k] == 1)
			cout << 7;
		else if (realise[1][k] * realise[2][k] * realise[5][k] * realise[6][k] == 1)
			cout << 4;
		else {
			RNG rng;
			cout << rng.uniform(0,9);
		}
	}

}
//级别1,2图像处理
void search_red(Mat src, Mat& dst)
{
	int rows = src.rows;
	int cols = src.cols;
	dst = Mat::zeros(src.size(), CV_8UC1);

	for (int row = 0; row < rows; row++) {
  	uchar* p = src.ptr<uchar>(row);
  		for (int col = 0; col < cols; col++) {
   			if (row<rows * 0.1 || row>rows * 0.9 || col<cols * 0.04 || col>cols * 0.96)  continue;
   			if (!(p[col * 3] < 230) && (p[col * 3 + 1] < 50 || p[col * 3 + 1]>100) && p[col * 3] > 100)  continue;
   			dst.at<uchar>(row, col) = saturate_cast<uchar>(p[col * 3 + 2] * pr - 60 - p[col * 3] * pb - p[col * 3 + 1] * pg); ///三通道权值组成灰度图像
 		}
	}
}

//级别2,3图像处理
void search_red3(Mat src, Mat& dst)
{
	int rows = src.rows;
	int cols = src.cols;
	dst = Mat::zeros(src.size(), CV_8UC1);

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++)
		{
			Vec3b bgr = src.at<Vec3b>(row, col);
			dst.at<uchar>(row, col) = saturate_cast<uchar>(bgr[2] * pr - 40 - bgr[0] * pb - bgr[1] * pg); ///三通道权值组成灰度图像
		}
	}
}


