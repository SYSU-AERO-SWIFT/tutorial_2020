# 拼接二维码


## 1 实现思路

### 1.1 寻找二维码区域

`Mat QRcodeArea(Mat &src)           //寻找QR所在区域`
首先滤波，通过图像的直方图判断二维码大概的二值化范围，膨胀后`findContours`,`boundingRect` 圈出区域，最后统一尺寸后返回该区域。

### 1.2 通过ORB寻找匹配点
    Ptr<ORB> orb = ORB::create();
    //第一步：检测Oriented FAST角点位置.
    orb->detect(img_1, keypoints_1);
    orb->detect(img_2, keypoints_2);
    //第二步：根据角点位置计算BRIEF描述子
    orb->compute(img_1, keypoints_1, descriptors_1);
    orb->compute(img_2, keypoints_2, descriptors_2);
    //得到keypoints和descriptors之后
    vector<DMatch> matches;
    //创建一个BFMatcher匹配器。使用Hamming距离对描述点进行匹配
    BFMatcher matcher(NORM_HAMMING);
    //匹配出来的结果写入上方定义的matches[]数组中
    matcher.match(descriptors_1, descriptors_2, matches);
筛选出一定数量（5到20个）的 `good _matches`，基于`Dmatch` 	当中的queryIdx，trainIdx两个索引找到相应的keypoint，另存为image_point。
### 1.3 图像变换
考虑到每个二维码分割图像可能经过变形，旋转，通过findHomography（）计算两个imagepoint对应的最优单映射变换矩阵，并且通过该矩阵计算两个图像所重叠的区域，转变后进行拼接。
### 1.4 拼接
    void mergeImg(Mat& img1, Mat& trans, Mat& dst)
    {
        int start = MIN(corners.left_top.x, corners.left_bottom.x);//开始位置，即重叠区域的左边界，corners重叠区域。
        double processWidth = img1.cols - start;//重叠区域的宽度  
        int rows = dst.rows;
    int cols = img1.cols；
    for (int i = 0; i < rows; i++)
    {
    	uchar* p = img1.ptr<uchar>(i);  //获取第i行的首地址
    	uchar* t = trans.ptr<uchar>(i);
    	uchar* d = dst.ptr<uchar>(i);
    	for (int j = start; j < cols; j++)
    	{
    		d[j * 3] = max(p[j * 3], t[j * 3]);//由于只有黑白两色，只需选取白色（255）拼接到最后的图像当中
    		d[j * 3+1] = max(p[j * 3+1], t[j * 3+1]);
    		d[j * 3+2] = max(p[j * 3+2], t[j * 3+2]);
    	}
    }
    }

### 1.5 识别
导入zbar库并识别，参考资料：https://blog.csdn.net/chenyuping333/article/details/81279433
### 1.6 主函数

    int main(int argc, char** argv)
    {
    	Mat img_1 = imread("C:/Users/zhang/Desktop/examples_and_samples/6666_1.jpg");
    	Mat img_2 = imread("C:/Users/zhang/Desktop/examples_and_samples/6666_2.jpg");
    	Mat img_3 = imread("C:/Users/zhang/Desktop/examples_and_samples/6666_3.jpg");
    	Mat img_4 = imread("C:/Users/zhang/Desktop/examples_and_samples/6666_4.jpg");
    	img_1= QRcodeArea(img_1);         //寻找QR所在区域
    	img_2 = QRcodeArea(img_2);
    	img_3 = QRcodeArea(img_3);
    	img_4 = QRcodeArea(img_4);
    	Mat img_12,img_34,fImg;
    	img_12 = SpliceQR(img_1, img_2,2);//分别合并
    	img_34 = SpliceQR(img_3, img_4,2);
    	fImg = SpliceQR(img_12, img_34,5);
    	idenQR(fImg);                     //识别二维码信息
    	waitKey();
    	return 0;
    }
## 2 很多问题
- 首先，本来想通过sift和suft寻找特征点的方法，但由于涉及专利问题，必须安装opencv modules才能使用（这一步用了一天的时间都没成功）。
- 于是寻找opencv3自带的Orb方法寻找特征点和描述子，但如果在寻找分割的二维码区域时将其转换为二值图，又会损失图像的大量信息，对于本来信息量就少的二维码在匹配描述子时就更难了。
- 如果上一步都做不好的话，之后的图像变换和拼接就更不可能了
- 所以这种方法的鲁棒性非常差，在对于普通照片拼接时有非常好的效果，但是二维码很就不好。
[![DnELjg.png](https://s3.ax1x.com/2020/11/18/DnELjg.png)](https://imgchr.com/i/DnELjg)
- 图中圆圈为keypoints，连线为满足Hamming距离的good_matchs

[![DnZkJP.png](https://s3.ax1x.com/2020/11/18/DnZkJP.png)](https://imgchr.com/i/DnZkJP)

- 由于拼接图是从左往右，所以keypoint必须要满足从最左端开始。

- 增加Hamming距离即可解决。
[![DnZFit.png](https://s3.ax1x.com/2020/11/18/DnZFit.png)](https://imgchr.com/i/DnZFit)