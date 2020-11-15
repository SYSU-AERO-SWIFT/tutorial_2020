#include<opencv2/opencv.hpp>
#include<vector>

void findcontours(cv::Mat&, std::vector<std::vector<cv::Point>>&, std::vector<cv::Vec4i>&);
void drawcontours(cv::Mat&, std::vector<std::vector<cv::Point>>&, int, int);
void canny(cv::Mat&, cv::Mat&, double, double, int = 3, bool = false);
