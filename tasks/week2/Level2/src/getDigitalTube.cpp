#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;

//面积比较
struct AreaCmp
{
	AreaCmp(const std::vector<float>& _areas) : areas(&_areas) {}
	bool operator() (int a, int b) const {return (*areas)[a] > (*areas)[b];}
	const std::vector<float>* areas;
};

Mat getDigitalTube(const Mat& input)
{
	//滤波后水漫金山，将背景全部涂黑
	Rect tmp;
	Mat image;
	GaussianBlur(input, image, Size(19, 19), 3, 3);
	floodFill(image, Point(25, 25), Scalar(0, 0, 0), &tmp, Scalar(2, 2, 2), Scalar(2, 2, 2));
	//二值化
	Mat gray;
	cvtColor(image, gray, CV_BGR2GRAY);
	threshold(gray, image, 1, 255, CV_THRESH_BINARY);
	//绘制数码管的轮廓
       	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	findContours(image, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	std::vector<int> sortIdx(contours.size());
	std::vector<float> areas(contours.size());
	for(int i = 0; i < (int)contours.size(); i++)
	{
		sortIdx[i] = i;
		areas[i] = contourArea(contours[i], false);
	}
	std::sort(sortIdx.begin(), sortIdx.end(), AreaCmp(areas));
	//用最小矩形框圈出数码管
	RotatedRect rotate = minAreaRect(contours[sortIdx[0]]);
	//仿射变换，将数码管旋转到水平
	Mat mask(input.size(), CV_8UC1, Scalar(0));
	Mat digit;
	Point2f vertices[4];
	rotate.points(vertices);
	std::vector<std::vector<Point>> rectContour;
	rectContour.push_back(std::vector<Point>());
	rectContour[0].push_back(vertices[0]);
	rectContour[0].push_back(vertices[1]);
	rectContour[0].push_back(vertices[2]);
	rectContour[0].push_back(vertices[3]);
	drawContours(mask, rectContour, 0, Scalar(255), CV_FILLED, 8);

	input.copyTo(digit, mask);

	Rect r = rotate.boundingRect();
	int d = r.width / 4;
	r.x += d;
	r.width -= d;
	digit = digit(r);


	Point2f center = Point2f(digit.cols/2, digit.rows/2);
	float angle = rotate.angle;
	if(90 <= angle && angle < 45)
		angle -= 90;
	else if(-90 <= angle && angle <-45)
		angle += 90;
	Mat rotateMatrix = getRotationMatrix2D(center, angle, 1);
	warpAffine(digit, digit, rotateMatrix, digit.size(), CV_INTER_LINEAR, IPL_BORDER_CONSTANT, Scalar(0));

	cvtColor(digit, gray, CV_BGR2GRAY);

	std::vector<std::vector<Point>> contours2;
	std::vector<Vec4i> hierarchy2;
	findContours(gray, contours2, hierarchy2 ,RETR_LIST, CHAIN_APPROX_SIMPLE);
	
	Rect rect = boundingRect(contours2[0]);

	digit = digit(rect);
	
	return digit;
}
