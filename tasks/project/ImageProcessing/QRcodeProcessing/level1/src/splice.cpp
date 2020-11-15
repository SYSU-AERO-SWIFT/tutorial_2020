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

//拼接二维码
Mat spliceQRcode(std::vector<Mat> quarters)
{
	//根据定位点的位置确定拼接顺序
	std::vector<int> sortIdx(4);
	std::vector<int> position(4);
        for(int k = 0; k < 4; k++)
        {
                sortIdx[k] = k;
                Mat bin;
                threshold(quarters[k], bin, 200, 255, CV_THRESH_BINARY);

                for(int i = 0; i < 5; i++)
                {
                        for(int j = 0; j < bin.rows; j++)
                        {
                                bin.at<uchar>(i, j) = 255;
                                bin.at<uchar>(bin.cols - i, j) = 255;
                        }
                        for(int j = 0; j < bin.cols; j++)
                        {
                                bin.at<uchar>(j, i) = 255;
                                bin.at<uchar>(j, bin.rows - i) = 255;
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
                        if(feature.x < bin.cols/2 && feature.y < bin.rows/2)
                                position[k] = 1;
                        else if(feature.x > bin.cols/2)
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
 
	//进行拼接
        Mat dst(400, 400, CV_8UC1, Scalar(0));
        img1.copyTo(dst(Rect(0, 0, img1.cols, img1.rows)));
        img2.copyTo(dst(Rect(img1.cols - 60, 0, img2.cols, img2.rows)));
	img3.copyTo(dst(Rect(0, img1.rows - 40, img3.cols, img3.rows)));
        img4.copyTo(dst(Rect(img3.cols - 40, img2.rows - 40, img4.cols, img4.rows)));

	return dst;
}
