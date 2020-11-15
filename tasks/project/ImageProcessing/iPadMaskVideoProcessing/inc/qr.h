#include<opencv2/opencv.hpp>
#include<vector>
#include<string>

void process(cv::Mat&, std::vector<std::vector<cv::Mat>>&, cv::Rect&, std::vector<cv::Mat>&);
std::vector<cv::Mat> processVideo(std::string);
cv::Mat spliceQRcode(std::vector<cv::Mat>);
void identifyQRcode(cv::Mat);
