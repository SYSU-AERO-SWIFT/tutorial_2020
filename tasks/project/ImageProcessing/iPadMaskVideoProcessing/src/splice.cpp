#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;

//位置比较
struct PositionCmp
{
        PositionCmp(const std::vector<int>& _position) : position(&_position) {}
        bool operator() (int a, int b) const {return (*position)[a] < (*position)[b];}
        const std::vector<int>* position;
};

Mat spliceQRcode(std::vector<Mat> quarters)
{
	//根据定位点的位置确定拼接的顺序
	std::vector<int> sortIdx(4);
	std::vector<int> position(4);
        for(int k = 0; k < 4; k++)
        {
                resize(quarters[k], quarters[k], Size(180, 180));
                sortIdx[k] = k;

                Mat bin;
                threshold(quarters[k], bin, 150, 255, CV_THRESH_BINARY);

                for(int i = 0; i < 5; i++)
                {
                        for(int j = 0; j < bin.rows; j++)
                        {
                                bin.at<uchar>(i, j) = 255;
                                bin.at<uchar>(179 - i, j) = 255;
                        }
                        for(int j = 0; j < bin.cols; j++)
                        {
                                bin.at<uchar>(j, i) = 255;
                                bin.at<uchar>(j, 179 - i) = 255;
                        }
                }
		
		std::vector<std::vector<Point>> econtour;
		std::vector<Vec4i> ehier;
                findContours(bin, econtour, ehier, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

                int found = -1;
                for(int i = 1; i < ehier.size(); i++)
                {
                        int k = i;
                        int count = 0;
                        while(ehier[k][2] != -1)
                        {
                                count++;
                                k = ehier[k][2];
                        }

                        if(count == 2)
                        {
                                found = i;
                                break;
                        }
                }
		
		if(found != -1)
                {
                        Rect feature = boundingRect(econtour[found]);
                        if(feature.x + feature.width/2 < 90 && feature.y + feature.height/2 < 90)
                                position[k] = 1;
                        else if(feature.x + feature.width/2 > 90)
                                position[k] = 2;
                        else
                                position[k] = 3;
                }
                else
                        position[k] = 4;
        }

	std::sort(sortIdx.begin(), sortIdx.end(), PositionCmp(position));

        Mat img1, img2, img3, img4;
        quarters[sortIdx[0]].copyTo(img1);
        quarters[sortIdx[1]].copyTo(img2);
        quarters[sortIdx[2]].copyTo(img3);
	quarters[sortIdx[3]].copyTo(img4);

	//边缘处理
        for(int i = 0; i < 2; i++)
        {
                for(int j = 0; j < img1.rows; j++)
                {
                        img2.at<uchar>(i, j) = img2.at<uchar>(2, j);
                        img3.at<uchar>(i, j) = img3.at<uchar>(2, j);
                        img4.at<uchar>(i, j) = img4.at<uchar>(2, j);
                }
        }
        for(int i = 0; i < 2; i++)
        {
                for(int j = 0; j < img1.cols; j++)
                {
                        img2.at<uchar>(j, i) = img2.at<uchar>(j, 2);
                        img3.at<uchar>(j, i) = img3.at<uchar>(j, 2);
                        img4.at<uchar>(j, i) = img4.at<uchar>(j, 2);
                }
        }

	//拼接
        Mat dst(340, 340, CV_8UC1, Scalar(0));
        img1.copyTo(dst(Rect(0, 0, 180, 180)));
        img2.copyTo(dst(Rect(160, 0, 180, 180)));
	img3.copyTo(dst(Rect(0, 160, 180, 180)));
        img4.copyTo(dst(Rect(160, 160, 180, 180)));

	return dst;
}
