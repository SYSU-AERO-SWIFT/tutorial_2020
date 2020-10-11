## 数码管数字识别项目

- 作者: 张博韬
- 修订人: 张博韬
- Date: 2020-10-11
- Version: 2.0.0
- Abstract: 你好，这是我的数码官识别项目，以下是对我的这个项目的简单介绍

* * *
> 源代码介绍
> Digital_realize
> > test/demo.cpp
> > inc/NumRec.h
> > src/NUmRec.cpp
> > opencv --version 3.4.1.1
> > >Functions:
	NumRec::numShow();
	NumRec::numRead();
	NumRec::numGet();
	search_red(Mat src, Mat& dst);
	search_red3(Mat src, Mat& dst);
> > >Interfaces:
	NumRec digit("name.jpg")
> > >Depend Libraries:
	opencv string iostream vector
> 编译
$ mkdir build
$ cd build
$ cmake .. 
$ make

> 测试
##### how to run:
cd bin
./Digital_realize name1.jpg

##### the result if it is running well:
>> 1234

* * *

> 程序实现内容：
> > 对数码管图片的数字进行识别
> > > 使用了判断数字图像的7个像素点，来判断目标数字的值
> > 有一定的对图片模糊，反光，噪声的适应能力
> > > 使用中值滤波，双边滤波，形态学滤波，以及色差法来凸显数字。
> > 可以对不完整的图片进行合成，得到准确数字
> > > 使用图片像素权重合成的方法

> 程序使用方法：
> > 在命令行下输入：./Digital_realise name1.xxx ,可以识别一张数码管中的数字
> > 输入 ./Digital_realise name1.xxx name2.xxx 可以识别将2张图片合成后的数字

> 图片演示：
n1.png
n2.png
n3.png


> 缺陷
> > 对于图片过于倾斜的情况，数字识别会不准确
> > 图片处理时间可以优化 

