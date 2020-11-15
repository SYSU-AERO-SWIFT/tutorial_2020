#include "../inc/qr.h"
#include<iostream>
#include<fstream>

using namespace cv;
using namespace std;

vector<Mat> processVideo(string video)
{
	VideoCapture gCap;
        gCap.open(video);

	vector<vector<Mat>> quarters;
        Rect lastRect(0, 0, 0, 0);
        vector<Mat> quarter;

	namedWindow("Play", WINDOW_AUTOSIZE); 
	Mat frame;
	for(;;)
	{
		gCap >> frame;
		if (frame.empty())
		{
			quarters.push_back(quarter);
			break;
		}

		process(frame, quarters, lastRect, quarter);
		imshow("Play", frame);
		waitKey(10);
	}

	//选出合适的二维码块图片，准备进行拼接处理	
	vector<Mat> result;
	for(int i = 0; i < quarters.size(); i++)
	{
		int n = int(quarters[i].size() / 2);
		while(quarters[i][n].cols * quarters[i][n].rows < 400)
			n++;
		result.push_back(quarters[i][n]);
	}
	
	return result;
}	
