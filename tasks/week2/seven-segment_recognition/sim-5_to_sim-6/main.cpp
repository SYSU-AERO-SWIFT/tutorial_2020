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
	string dir = argv[1];
	Mat img_input = imread(dir);
	imshow("Input Image", img_input);
	waitKey(0);
	destroyWindow("Input Image");
	Mat morphology = preprocess(img_input);
	vector<Rect> numbers = findNumbers(morphology);
	Mat roi;
	for (vector<Rect>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter)
	{
		roi = morphology(*iter);
		rectangle(img_input, (*iter), Scalar(255, 0, 0), 2);
		recognition(roi);
	}
	imshow("Output Image", img_input);
	waitKey(0);
	cout << endl;
	return 0;
}
