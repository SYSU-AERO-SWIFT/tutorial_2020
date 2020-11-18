#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/calib3d.hpp" 
#include <opencv2/imgproc.hpp>
#include <zbar.h>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
using namespace zbar;
typedef struct          // 定义重叠区域的坐标
{
	Point2f left_top;
	Point2f left_bottom;
	Point2f right_top;
	Point2f right_bottom;
}four_corners_t;

four_corners_t corners;
int lengths = 200;
Size dsize = Size(lengths, lengths);


Mat QRcodeArea(Mat &src)           //寻找QR所在区域
{
	Mat dstImage, imageBinary;
	GaussianBlur(src, dstImage, Size(3, 3), 1, 1);


	inRange(dstImage, Scalar(230, 230, 230), Scalar(256, 256, 256), imageBinary);//基于二值化的方法

	Mat imageDilate;
	Mat element = getStructuringElement(MORPH_RECT, Size(11, 17));//获取核
	dilate(imageBinary, imageDilate, element); //膨胀

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	Mat image = imageDilate.clone();
	findContours(imageDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));

	vector<vector<Point> > contoursPoly(contours.size());  //筛选点
	vector<Rect> boundRect(contours.size());
	vector<Rect> boundRectOrder(contours.size());

	for (unsigned int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contoursPoly[i], 3, true);//减少绘制图形所用的点
		boundRect[i] = boundingRect(Mat(contoursPoly[i]));  //包含轮廓点的最小矩形
	}
	Mat drawing = Mat::zeros(imageDilate.size(), CV_8UC3);

	int max = 0;
	for (int unsigned i = 0; i < contours.size(); i++)
	{
		drawContours(drawing, contoursPoly, i, Scalar(100), 1, 8, vector<Vec4i>(), 0, Point());
		rectangle(imageDilate, boundRect[i].tl(), boundRect[i].br(), Scalar(100), 2, 8, 0);
	}
	Mat BGRimage = src(boundRect[0]);

	resize(BGRimage, BGRimage, dsize);
	
	return  BGRimage;
}
void mergeImg(Mat& img1, Mat& trans, Mat& dst)
{
	int start = MIN(corners.left_top.x, corners.left_bottom.x);//开始位置，即重叠区域的左边界  

	double processWidth = img1.cols - start;//重叠区域的宽度  
	int rows = dst.rows;
	int cols = img1.cols; //注意，是列数*通道数
	 

	for (int i = 0; i < rows; i++)
	{
		uchar* p = img1.ptr<uchar>(i);  //获取第i行的首地址
		uchar* t = trans.ptr<uchar>(i);
		uchar* d = dst.ptr<uchar>(i);
		for (int j = start; j < cols; j++)
		{
			

			d[j * 3] = max(p[j * 3], t[j * 3]);
			d[j * 3+1] = max(p[j * 3+1], t[j * 3+1]);
			d[j * 3+2] = max(p[j * 3+2], t[j * 3+2]);


		}
	}

}
void CalcCorners(const Mat& H, const Mat& src)
{
	double v2[] = { 0, 0, 1 };//左上角
	double v1[3];//变换后的坐标值
	Mat V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	Mat V1 = Mat(3, 1, CV_64FC1, v1);  //列向量

	V1 = H * V2;
	//左上角(0,0,1)
	cout << "V2: " << V2 << endl;
	cout << "V1: " << V1 << endl;
	corners.left_top.x = v1[0] / v1[2];
	corners.left_top.y = v1[1] / v1[2];

	//左下角(0,src.rows,1)
	v2[0] = 0;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.left_bottom.x = v1[0] / v1[2];
	corners.left_bottom.y = v1[1] / v1[2];

	//右上角(src.cols,0,1)
	v2[0] = src.cols;
	v2[1] = 0;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.right_top.x = v1[0] / v1[2];
	corners.right_top.y = v1[1] / v1[2];

	//右下角(src.cols,src.rows,1)
	v2[0] = src.cols;
	v2[1] = src.rows;
	v2[2] = 1;
	V2 = Mat(3, 1, CV_64FC1, v2);  //列向量
	V1 = Mat(3, 1, CV_64FC1, v1);  //列向量
	V1 = H * V2;
	corners.right_bottom.x = v1[0] / v1[2];
	corners.right_bottom.y = v1[1] / v1[2];

}
Mat SpliceQR(Mat img_1, Mat img_2,float mdistence)
{
	
	//首先创建两个关键点数组，用于存放两张图像的关键点，数组元素是KeyPoint类型
	std::vector<KeyPoint> keypoints_1, keypoints_2;

	//创建两张图像的描述子，类型是Mat类型
	Mat descriptors_1, descriptors_2;

	Ptr<ORB> orb = ORB::create();


	//第一步：检测Orb角点位置.

	orb->detect(img_1, keypoints_1);
	orb->detect(img_2, keypoints_2);


	//第二步：根据角点位置计算BRIEF描述子


	orb->compute(img_1, keypoints_1, descriptors_1);
	orb->compute(img_2, keypoints_2, descriptors_2);

	//定义输出检测特征点的图片。
	Mat outimg1;

	drawKeypoints(img_1, keypoints_1, outimg1, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	imshow("ORB特征点", outimg1);


	//第三步：对两幅图像中的BRIEF描述子进行匹配，使用 Hamming 距离

	//创建一个匹配点数组，用于承接匹配出的DMatch.
	vector<DMatch> matches;

	BFMatcher matcher(NORM_HAMMING);
	//匹配出来的结果写入上方定义的matches[]数组中
	matcher.match(descriptors_1, descriptors_2, matches);

	//第四步：遍历matches[]数组，找出匹配点的最大距离和最小距离，用于后面的匹配点筛选。
	
	double min_dist = 100, max_dist = 0;//定义距离
	for (int i = 0; i < descriptors_1.rows; i++)//遍历
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}

	printf("Min dist: %f\n", min_dist);

	//第五步：根据最小距离，对匹配点进行筛选，
	std::vector<DMatch> good_matches;
	//if (mdistence < min_dist)
	//{
		//min_dist = mdistence+ min_dist;
	//}

	//while (!good_matches.size()||(good_matches.size() <= 10 || good_matches.size() >= 20))
	//{
		//min_dist++;
		for (int j = 0; j < descriptors_1.rows; ++j)
		{
			if (matches[j].distance <= mdistence)
				good_matches.push_back(matches[j]);
		}
	//}

	Mat first_match;//筛选后的匹配点图
	drawMatches(img_1, keypoints_1, img_2, keypoints_2, good_matches, first_match);
	imshow("good_matches", first_match);

	vector<Point2f> imagePoints1, imagePoints2;

	for (int i = 0; i < good_matches.size(); i++)
	{
		imagePoints2.push_back(keypoints_2[good_matches[i].queryIdx].pt);
		imagePoints1.push_back(keypoints_1[good_matches[i].trainIdx].pt);
	}

	//获取图像1到图像2的投影映射矩阵 尺寸为3*3  
	Mat homo = findHomography(imagePoints1, imagePoints2, CV_RANSAC);
    //计算配准图的四个顶点坐标
	CalcCorners(homo, img_1);
	//图像匹配  
	Mat imageTransform1, imageTransform2;
	warpPerspective(img_1, imageTransform1, homo, Size(MAX(corners.right_top.x, corners.right_bottom.x), img_2.rows));

	//创建拼接后的图的大小
	int dst_width = img_1.cols ;
	int dst_height = img_1.rows ;
	Mat dst(dst_height, dst_width, CV_8UC3);
	dst.setTo(0);
	imageTransform1.copyTo(dst(Rect(0, 0, imageTransform1.cols, imageTransform1.rows)));
	img_1.copyTo(dst(Rect(0, 0, img_1.cols, img_1.rows)));
	//img_2.copyTo(dst(Rect(0, 0, img_2.cols, img_2.rows)));
	imshow("1", dst);
	mergeImg(img_2, img_1, dst);
	return dst;
}
void idenQR(Mat &img)
{
	ImageScanner scanner;

	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);

	cv::Mat imgGray;

	imgGray.create(img.size(), CV_8UC1);

	cvtColor(img, imgGray, CV_BGR2GRAY);

	int width = imgGray.cols;

	int height = imgGray.rows;

	Image image(width, height, "Y800", imgGray.data, width *height);

	int n = scanner.scan(image);

	for (Image::SymbolIterator symbol = image.symbol_begin();

		symbol != image.symbol_end();

		++symbol) {

		cout << "decoded:" << symbol->get_type_name();
		cout<< " symbol :" << symbol->get_data() << endl;

	}

	image.set_data(NULL, 0);
}

int main(int argc, char** argv)
{
	
	Mat img_1 = imread("/home/sae/opencvtast/project1/src/6666_1.jpg");
	Mat img_2 = imread("/home/sae/opencvtast/project1/src/6666_2.jpg");
	Mat img_3 = imread("/home/sae/opencvtast/project1/src/6666_3.jpg");
	Mat img_4 = imread("/home/sae/opencvtast/project1/src/6666_4.jpg");
	
	img_1= QRcodeArea(img_1);         //寻找QR所在区域
	img_2 = QRcodeArea(img_2);
	img_3 = QRcodeArea(img_3);
	img_4 = QRcodeArea(img_4);
	
	copyMakeBorder(img_1, img_1, 0, lengths, 0, lengths, BORDER_CONSTANT, Scalar(0, 0, 0));
	copyMakeBorder(img_2, img_2, 0, lengths, lengths, 0, BORDER_CONSTANT, Scalar(0, 0, 0));
	copyMakeBorder(img_3, img_3, lengths, 0, 0, lengths, BORDER_CONSTANT, Scalar(0, 0, 0));
	copyMakeBorder(img_4, img_4, lengths, 0, lengths, 0, BORDER_CONSTANT, Scalar(0, 0, 0));
	
	Mat img_12,img_34,fImg;
	img_12 = SpliceQR(img_1, img_2,2);
	img_34 = SpliceQR(img_3, img_4,2);
	fImg = SpliceQR(img_12, img_34,5);
	idenQR(fImg);
	imshow("12", img_12);
	imshow("34", img_34);
	imshow("final", fImg);
	waitKey();

	return 0;
}

