#include<iostream>
#include<string>
#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<vector>
#include"recognition.h"
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
	string dir1 = argv[1];
	string dir2 = argv[2];
	Mat img_input_1 = imread(dir1);
	Mat img_input_2 = imread(dir2);
	
	Mat morphology_1 = preprocess(img_input_1);
	Mat morphology_2 = preprocess(img_input_2);
	morphology_1.convertTo(morphology_1, CV_32FC1);
	morphology_2.convertTo(morphology_2, CV_32FC1);
	Mat morphology;
	add(morphology_1, morphology_2, morphology);
	threshold(morphology, morphology, 200.0, 255.0, THRESH_BINARY);
	morphology.convertTo(morphology, CV_8UC1);
	imshow("Add", morphology);
	waitKey(0);
	destroyWindow("Add");
	Mat result = morphology(Rect(30, 30, 980, 410));
	vector<Rect> numbers = findNumbers(result);
	Mat roi;
	for (vector<Rect>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		roi = morphology(*iter);
		rectangle(result, (*iter), Scalar(255, 0, 0), 2);
		recognition(roi);
	}
	imshow("result", result);
	waitKey(0);
	cout << endl;
	return 0;
}
