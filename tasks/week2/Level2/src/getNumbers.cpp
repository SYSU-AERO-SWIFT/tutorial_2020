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

//矩形框水平位置比较
struct XCmp
{
	XCmp(const std::vector<int>& _x) : x(&_x) {}
	bool operator() (int a, int b) const {return (*x)[a] > (*x)[b];}
	const std::vector<int>* x;
};

std::vector<Mat> getNumbers(const Mat& image)
{
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

	std::vector<Rect> rects;
	for(int i = 0; i < 4; i++)
	{
		int id = sortIdx[i];
		Rect r = boundingRect(contours[id]);
		if(r.y < image.rows/6 || r.y > image.rows/4)
			r.y = image.rows/6;
		if(r.height < image.rows*0.4 || r.height > image.rows*0.45)
			r.height = image.rows*0.45;
		if(r.width > image.cols / 4)
		{
			r.width /= 2;
			Rect r2(r.x+r.width, r.y, r.width, r.height);
			rects.push_back(r2);
		}
		
		rects.push_back(r);
	}

	std::vector<Mat> digit;
	std::vector<int> x(4);
	std::vector<int> I(4);
	for(int i = 0; i < 4; i++)
	{
		I[i] = i;
		x[i] = rects[i].x;
	}
	std::sort(I.begin(), I.end(), XCmp(x));

	for(int i = 3; i > -1; i--)
	{
		Mat temp(image, rects[I[i]]);	
		resize(temp, temp, Size(150, 100));
		digit.push_back(temp);
	}

	return digit;
}


