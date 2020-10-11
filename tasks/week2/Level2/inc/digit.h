#include<opencv2/opencv.hpp>
#include<vector>

cv::Mat binarization(const cv::Mat&);
std::vector<cv::Mat> getNumbers(const cv::Mat&);
cv::Mat getDigitalTube(const cv::Mat&);
std::vector<int> svm(std::vector<cv::Mat>, std::vector<int>, std::vector<cv::Mat>);
std::vector<cv::Mat> process();
