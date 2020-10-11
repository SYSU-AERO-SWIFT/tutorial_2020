#include<opencv2/opencv.hpp>
#include<vector>
#include "../inc/digit.h"

using namespace cv;

std::vector<Mat> process()
{
	std::vector<Mat> trainSet;

	for(int i = 1; i < 9; i++)
	{
		std::stringstream s;
		s << "../act_samples/act_sample" << i << ".jpg";
		std::string fname = s.str();
		Mat input = imread(fname);
		if(input.empty())
		{
			trainSet.clear();
			return trainSet;
		}

		Mat digit = getDigitalTube(input);
		Mat binary = binarization(digit);
		std::vector<Mat> result = getNumbers(binary);
		for(int j = 0; j < (int)result.size(); j++)
		{
			trainSet.push_back(result[j]);
			/*std::stringstream s;
			s << "../act_result/act_sample" << i << "_" << j + 1 << ".jpg";
			std::string fname = s.str();
			imwrite(fname, result[j]);*/
		}
	}

	return trainSet;
}
