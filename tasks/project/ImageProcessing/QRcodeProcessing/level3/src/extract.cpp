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
	Mat origin;
	input.copyTo(origin);

	//做floodFill处理后进行canny边缘检查，用于定位二维码块
	Rect tmp;
	floodFill(input, Point(input.cols / 2, input.rows - 3), Scalar(0, 0, 0), &tmp, Scalar(4, 4, 4), Scalar(4, 4, 4));

	Mat gray;
	cvtColor(input, gray, CV_BGR2GRAY);
	Mat G;
	GaussianBlur(gray, G, Size(5, 5), 0.8);
	Mat bin;
	threshold(G, bin, 200, 255, CV_THRESH_BINARY);
	Mat edge;
	Canny(bin, edge, 60, 80);

	//不做floodFill处理，用于切割出二维码块
	cvtColor(origin, gray, CV_BGR2GRAY);
	GaussianBlur(gray, G, Size(5, 5), 0.8);
	threshold(G, bin, 200, 255, CV_THRESH_BINARY);

	std::vector<std::vector<Point>> contours;
	std::vector<Vec4i> hierarchy;
	findContours(bin, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
	
	//轮廓层数最多的即视为定位点
	std::vector<std::vector<Point>> econtour;
	std::vector<Vec4i> ehier;
	findContours(edge, econtour, ehier, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

	int found = 0;
	int max = 0;
	for(int i = 0; i < ehier.size(); i++)
	{
		int k = i;
		int count = 0;
		while(ehier[k][2] != -1)
		{
			count++;
			k = ehier[k][2];
		}
		if(count > max)
		{
			max = count;
			found = i;
		}
	}

	//根据定位点的位置筛选二维码块
	Rect feature = boundingRect(econtour[found]);
	Point2f center1 = Point2f(feature.x + feature.width / 2, feature.y + feature.height / 2);
	
	std::vector<int> suspect;
	for(int i = 0; i < contours.size(); i++)
	{
		Rect tmp = boundingRect(contours[i]);
		if(center1.x > tmp.x && center1.x < tmp.x + tmp.width && center1.y > tmp.y && center1.y < tmp.y + tmp.height)
			suspect.push_back(i);
	}

	std::vector<int> sortIdx(suspect.size());
	std::vector<float> areas(suspect.size());
	for(int i = 0; i < (int)suspect.size(); i++)
	{
		sortIdx[i] = i;
		areas[i] = contourArea(contours[suspect[i]], false);
	}
	std::sort(sortIdx.begin(), sortIdx.end(), AreaCmp(areas));
	
	//矫正二维码块
	RotatedRect rotate = minAreaRect(contours[suspect[sortIdx[0]]]);

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

