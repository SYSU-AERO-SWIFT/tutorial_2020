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

//提取二维码
Mat extractQRcode(Mat& input)
{
	//二值化，使用了两个不同的阈值
	Mat gray;
	cvtColor(input, gray, CV_BGR2GRAY);
  
	Mat G;
	GaussianBlur(gray, G, Size(5, 5), 0.8);

	Scalar m;
	Scalar v;
	meanStdDev(G, m, v);
	int th;
	if(m.val[0] < 5)
		th = 100;
	else
		th = 200;
	Mat bin;
	threshold(G, bin, th, 255, CV_THRESH_BINARY);

	//提取二维码块
	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	
	std::vector<int> sortIdx(contours.size());
	std::vector<float> areas(contours.size());
	for(int i = 0; i < (int)contours.size(); i++)
	{
		sortIdx[i] = i;
		areas[i] = contourArea(contours[i], false);
	}
	std::sort(sortIdx.begin(), sortIdx.end(), AreaCmp(areas));

	//矫正二维码块
	RotatedRect rotate = minAreaRect(contours[sortIdx[0]]);

	Mat mask(gray.size(), CV_8UC1, Scalar(0));
	Mat qr;
	Point2f vertices[4];
	rotate.points(vertices);
	std::vector<std::vector<Point>> rectContour;
	rectContour.push_back(std::vector<Point>());
	rectContour[0].push_back(vertices[0]);
	rectContour[0].push_back(vertices[1]);
	rectContour[0].push_back(vertices[2]);
	rectContour[0].push_back(vertices[3]);
	drawContours(mask, rectContour, 0, Scalar(255), CV_FILLED, 8);

	gray.copyTo(qr, mask);
	
	Rect r = rotate.boundingRect();
	qr = qr(r);

	Point2f center = Point2f(qr.cols/2, qr.rows/2);
	float angle = rotate.angle;
	if(90 <= angle && angle < 45)
		angle -= 90;
	else if(-90 <= angle && angle <-45)
		angle += 90;
	Mat rotateMatrix = getRotationMatrix2D(center, angle, 1);
	warpAffine(qr, qr, rotateMatrix, qr.size(), CV_INTER_LINEAR, IPL_BORDER_CONSTANT, Scalar(0));

	std::vector<std::vector<Point>> contours2;
	std::vector<Vec4i> hierarchy2;
	findContours(qr, contours2, hierarchy2 ,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Rect rect = boundingRect(contours2[0]);

	qr = qr(rect);

	return qr;
}

