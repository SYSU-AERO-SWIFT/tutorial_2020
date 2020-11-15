#include "../inc/qr.h"

using namespace cv;

int main()
{
	std::vector<Mat> quarters = processVideo("../iPadMaskDemo.m4v");
	Mat qr = spliceQRcode(quarters);
	identifyQRcode(qr);
	imshow("QR code", qr);
	waitKey(0);

	return 0;
}
