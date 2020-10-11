#include<opencv2/opencv.hpp>
#include<vector>

using namespace cv;
using namespace cv::ml;

std::vector<int> svm(std::vector<Mat> trainSet, std::vector<int> labels, std::vector<Mat> input)
{
	Ptr<SVM> svm = SVM::create();
    	svm->setType(SVM::C_SVC);
    	svm->setKernel(SVM::LINEAR);
    	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));

	Mat dataMat, labelMat;
	auto p = trainSet.begin();
	for(; p != trainSet.end(); p++)
		dataMat.push_back((*p).reshape(0, 1));
	dataMat.convertTo(dataMat, CV_32F);
	auto q = labels.begin();
	for(; q != labels.end(); q++)
		labelMat.push_back(*q);
	svm->train(dataMat, ROW_SAMPLE, labelMat);


	std::vector<int> result;
	auto t = input.begin();
	for(; t != input.end(); t++)
	{
		Mat r = (*t).reshape(0, 1);
		r.convertTo(r, CV_32F);
		int predict = svm -> predict(r);
		result.push_back(predict);
	}

	return result;
}

