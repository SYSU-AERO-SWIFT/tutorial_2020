#include<opencv2/opencv.hpp>
#include<zbar.h>
#include<iostream>

using namespace zbar;

void identifyQRcode(cv::Mat qr)
{
	ImageScanner scanner;
        scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
        int width = qr.cols;
        int height = qr.rows;
        uchar *raw = (uchar *)qr.data;
        Image imageZbar(width, height, "Y800", raw, width * height);
        scanner.scan(imageZbar);
        Image::SymbolIterator symbol = imageZbar.symbol_begin();
        if(imageZbar.symbol_begin() == imageZbar.symbol_end())
        {
		std::cout << "查询失败，请检查图片！" << std::endl;
        }
        for(;symbol != imageZbar.symbol_end();++symbol)
        {
		std::cout << "类型：" << std::endl << symbol->get_type_name()
			<< std::endl << std::endl;
		std::cout << "条码：" << std::endl << symbol->get_data()
			<< std::endl << std::endl;
        }
}

