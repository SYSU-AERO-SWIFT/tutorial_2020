#include "../inc/qr.h"
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	if(argc < 5)
	{
		cout << "请输入四幅图片！" << endl;
		return -1;
	}
	
	double t = (double)cv::getTickCount();

	vector<cv::Mat> quarters;
	for(int i = 1; i < 5; i++)
	{
		cv::Mat input = cv::imread(argv[i]);
		if(input.empty())
		{
			cout << "图片" << i << "导入失败！" << endl;
			return -1;
		}
		cv::Mat qr = extractQRcode(input);
		quarters.push_back(qr);
	}

	cv::Mat qr = spliceQRcode(quarters);
	identifyQRcode(qr);

	t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
	cout << "Processing_time : " << t << " s" << endl << endl;

	cv::imshow("QR code", qr);
	cv::waitKey(0);

	return 0;
}

