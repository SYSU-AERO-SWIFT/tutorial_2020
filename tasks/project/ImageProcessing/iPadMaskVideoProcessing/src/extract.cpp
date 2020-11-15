#include<opencv2/opencv.hpp>
#include<cmath>
#include<vector>

using namespace cv;

//切割二维码块并矫正
Mat cut(Mat input, std::vector<Point> contour)
{
        RotatedRect rotate = minAreaRect(contour);

        Mat mask(input.size(), CV_8UC1, Scalar(0));
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

        input.copyTo(qr, mask);

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

//单帧处理函数
void process(Mat& input, std::vector<std::vector<Mat>>& quarters, Rect& lastRect, std::vector<Mat>& quarter)
{
        Mat G;
        GaussianBlur(input, G, Size(5, 5), 0.8);
	Rect tmp;
        floodFill(G, Point(input.cols / 2, input.rows - 3), Scalar(0, 0, 0), &tmp, Scalar(8, 8, 8), Scalar(8, 8, 8));
        Mat gray;
        cvtColor(G, gray, CV_BGR2GRAY);
        Mat bin;
        threshold(gray, bin, 150, 255, CV_THRESH_BINARY);
        Mat d;
        dilate(bin, d, Mat(), Point(-1, -1), 6);

        std::vector<std::vector<Point>> contours;
        std::vector<Vec4i> hierarchy;
        findContours(d, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	
	//根据大小和形状找出二维码块，并把同一区域的二维码块放到一起
        Point2f formal((lastRect.x + lastRect.width/2), (lastRect.y + lastRect.height/2));

        for(int i = 0; i < contours.size(); i++)
        {
                float area = contourArea(contours[i], false);
                Rect r = boundingRect(contours[i]);

                if(area > 17000 && area < 18000 && std::abs(r.width - r.height) < 10)
                {
                        Point2f current((r.x + r.width/2), (r.y + r.height/2));
			if(std::abs(current.x - formal.x) + std::abs(current.y - formal.y) > 100 && lastRect.width != 0)
                        {
                                quarters.push_back(quarter);
                                quarter.clear();
                        }

                        lastRect = r;
                        quarter.push_back(cut(gray, contours[i]));
                        rectangle(input, r, Scalar(0, 0, 255), 8);
                }
        }
}
