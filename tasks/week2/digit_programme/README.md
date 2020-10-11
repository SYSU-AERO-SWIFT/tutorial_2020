# 写在最前

由于时间很短，并且之前没有怎么接触过图像识别，所以最后的效果并没有达到最好，还有很多的提升空间，比如图像的识别并旋转已经写到一半了，但是不知道中间有什么bug，最后没有实现效果，只剩下了一个写到了一半函数：
`void Rotate(Mat srcImage, Mat destImage, double angle, Point2f center);`
之后还可以继续改正，还有代码规范执行不是很好。

**最后由于一来用的Visual Studio，加载的是Opencv4.0的库，但Linux上是Opencv3.0的库，函数和参数有一些不同，但是发现之后时间不够了，所以测试和测试结果是在windows环境实现的，之后改为opencv3.0的代码形式**

***
***

# 1.测试效果

## 1.1一级（simple）
simple难度经测试均可完成

***
- 输入：
`	src_1 = imread("sim_sample1.jpg");`
输出：
`2039`
 处理好、识别之前的图：
![sim_sample1_result.png](https://i.loli.net/2020/10/11/clZNn7EaYpWFrb9.png)

- 输入：
  `	src_1 = imread("sim_sample4.jpg");`
  输出：
  `8397`
   处理好、识别之前的图：
  ![sim_sample4_result.png](https://i.loli.net/2020/10/11/YuhjAK9ZGm5QFoO.png)

- 输入：
  `	src_1 = imread("sim_sample5.jpg");`
  输出：
  `5671`
   处理好、识别之前的图：
  ![sim_sample5_result.png](https://i.loli.net/2020/10/11/iadpc1tbvg5z6ST.png)

- 输入：
  `	src_1 = imread("sim_sample6.jpg");`
  输出：
  `8276`
   处理好、识别之前的图：
  ![sim_sample6_result.png](https://i.loli.net/2020/10/11/pQg9iT3aVcXKURv.png)

- 输入：
  `	src_1 = imread("sim_sample7.jpg");`
  输出：
  `2951`
   处理好、识别之前的图：
  ![sim_sample7_result.png](https://i.loli.net/2020/10/11/LomDU6hHpeiO82V.png)

- 输入：
  `	src_1 = imread("sim_sample8.jpg");`
  输出：
  `2951`
   处理好、识别之前的图：
  ![sim_sample8_result.png](https://i.loli.net/2020/10/11/ZIcqtvnpxAO3NMD.png)

***
***

## 1.2二级（act）
经测试，二级1~4图均可完成，其他如下：

- 输入：
  `	src_1 = imread("act_sample1.jpg");`
  输出：
  `9735`
   处理好、识别之前的图：
  ![act_sample1_result.png](https://i.loli.net/2020/10/11/8VuA4bt6FCJOWUg.png)

- 输入：
  `	src_1 = imread("act_sample4.jpg");`
  输出：
  `3146`
   处理好、识别之前的图：
  ![act_sample4_result.png](https://i.loli.net/2020/10/11/v51fAzWYhcZiTSJ.png)

- 输入：
  `	src_1 = imread("act_sample5.jpg");`
  输出：
  `125`
  （7未识别出）
   处理好、识别之前的图：
  ![act_sample5_result.png](https://i.loli.net/2020/10/11/7mOzByVhdc9W5tk.png)

最后几个由于曝光过高在二值图处理时

- 输入：
  `	src_1 = imread("act_sample6.jpg");`
  输出：
  `0163`
  处理好、识别之前的图：
  ![act_sample6_result.png](https://i.loli.net/2020/10/11/6TsEFzkSOd1Zuva.png)


- 输入：
  `	src_1 = imread("act_sample7.jpg");`
  输出：
  `986`
   处理好、识别之前的图：
  ![act_sample7_result.png](https://i.loli.net/2020/10/11/jhdXWnqJOSwmolP.png)
  
  ***
  ***
## 1.2三级（hard）
经测试，三级1~4图均可完成，其他未测试


- 输入：
  `		src_1 = imread("hard_sample1_1.jpg");`
  `		src_2 = imread("hard_sample1_2.jpg");`
  输出：
  `8435`
   处理好、识别之前的图：
![hard_sample1_result.png](https://i.loli.net/2020/10/11/UztIA5ix2NT8qL3.png)


- 输入：
  `		src_1 = imread("hard_sample2_1.jpg");`
  `		src_2 = imread("hard_sample2_2.jpg");`
  输出：
  `0528`
   处理好、识别之前的图：
  ![hard_sample2_result.png](https://i.loli.net/2020/10/11/BKzhmVC9ZFP1aMd.png)
  
  
  - 输入：
  `		src_1 = imread("hard_sample3_1.jpg");`
  `		src_2 = imread("hard_sample3_2.jpg");`
  输出：
  `6701`
   处理好、识别之前的图：
  ![hard_sample3_result.png](https://i.loli.net/2020/10/11/F8ndRhMPiVTzmKS.png)
  
  
   - 输入：
  `		src_1 = imread("hard_sample4_1.jpg");`
  `		src_2 = imread("hard_sample4_2.jpg");`
  输出：
  `9245`
  处理好、识别之前的图：
  ![hard_sample4_result.png](https://i.loli.net/2020/10/11/qyr3uimL1ZaxjhY.png)
  
  
  ***
  ***
  # 2.实现思路
  
  
  ## 2.1 降噪处理
  
  由于很多照片噪声大，使用高斯滤波处理：
  `GaussianBlur(src_1, src_1, Size(3, 3), 1, 1);`
  
  ## 2.2 二值化
  
  第二步是将图片二值化，由于是红色数码管，R通道是明显的特征，我使用到了 `inrange`函数，并且通过：
  `//返回图像red直方图的最大值点`
  `int histMax(Mat src);`
  来判断整体的颜色偏暗还是亮，来选择合适的范围。
  
  ## 2.3 过滤
  
  将面积小于area的区域过滤，提高识别效率，但是这一步运算量大，一般可以省去
  `//去除二值图当中小于area面积的像素块`
  `void filterArea(Mat imageBinary, int area);`
  ## 2.4 膨胀
  
  这一波是为了后续寻找轮廓识别方便，于是膨胀：
  `Mat element = getStructuringElement(MORPH_RECT, Size(11, 17));//获取核
	dilate(imageBinary, imageDilate, element); //膨胀`
	
  ## 2.5 寻找轮廓、筛选点、画出识别矩形
  
  由于上面的图像处理后，只用查找最外面的轮廓即可：
  `findContours(imageDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));`
  `approxPolyDP(Mat(contours[i]), contoursPoly[i], 3, true);//减少绘制图形所用的点`
  `rectangle(imageDilate, boundRect[i].tl(), boundRect[i].br(), Scalar(100), 2, 8, 0);`
  ## 2.6 识别
  时间比较短，所以选择了更容易实现的穿线法来识别数字，具体的代码比较长，主要的函数有：
  
  `//获取坐标在x，y处的像素值`
  `int getPixelValues(Mat imageFinal, int x, int y);`
  `//判断（x1，y1）到（x2，y2）这条线的是否有像素点`
  `bool cross(Mat imageFianl, int x1, int y1, int x2, int y2);`
  `//读取数字,返回数字，如果识别失败，返回“”`
  `string getNum(Mat image);`
  
  ## 2.7 其他已解决问题
  首先是直方图的处理，其次是如何输出正确的数字顺序，图像的旋转（之后还可以改正），如果找到的区域不是数字所在的区域应该如何排除（通过判断几个特殊点是否有像素值、判断识别区长和宽的比例），1如何识别等等。
  
  ## 2.8 未解决问题
  图像的旋转，如何更好的过滤高光，如何更好的拼接识别区域等等。
  
  
