#include"../inc/digit.h"
#include<sstream>
#include<string>
#include<opencv2/ml.hpp>

using namespace cv;

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Please enter an image!\n";
		return -1;
	}
	Mat input = imread(argv[1]);
	if(input.empty())
	{
		std::cout << "Cannot find the image!\n";
		return -1;
	}

	std::cout << "Processing..." << std::endl;

	std::vector<Mat> trainSet = process();

	if(trainSet.empty())
	{
		std::cout << "Data loading error!\n";
		return -1;
	}
	Mat binary = binarization(input);
	std::vector<Mat> numbers = getNumbers(binary);

	std::vector<int> labels;
	int n[32] = { 2, 0, 3, 9, 0, 3, 4, 1, 5, 1, 6, 2, 8, 3, 9, 7, 5, 6, 7, 1, 8, 2, 7, 6, 2, 9, 5, 1, 8, 3, 0, 5 };
	for(int i = 0; i < 32; i++)
		labels.push_back(n[i]);

	std::vector<int> predict = svm(trainSet, labels, numbers);
	
	std::cout << "Predict value: ";
	for(int i = 0; i < (int)predict.size(); i++)
		std::cout << predict[i];
	std::cout << std::endl;

	imshow("input", input);
	imshow("binary", binary);
	waitKey(0);

	return 0;
}
