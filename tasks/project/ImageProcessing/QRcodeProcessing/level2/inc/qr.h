#include<opencv2/opencv.hpp>
#include<vector>

cv::Mat extractQRcode(cv::Mat&);
cv::Mat spliceQRcode(std::vector<cv::Mat>);
void identifyQRcode(cv::Mat);
