## <h1>数码管图片识别级别一


### 作者: 林敬禹
### 修订: 林敬禹
### 日期: 2020-10-11
### 版本: 1.0.0
### 摘要: 对电脑软件仿真的数码管进行处理，识别出显示的数字



### **Funtions**

1. *binarization*   对图片进行二值化处理
2. *getNumbers*   在二值化图片中绘制数字轮廓然后用最小的矩形框圈出四个数字，返回四个大小相同的单个数字的二值化图像
3. *trainSetProcess*   导入sim_samples中所有的图像进行处理，返回一个训练集
4. *svm*   用支持向量机预测输入图片中的四个数字
5. *main*   处理输入图片输出识别结果


### **Interfaces**


///对图片进行二值化处理

*cv::Mat binarization(const cv::Mat&)*

///在二值化图片中绘制数字轮廓然后用最小的矩形框圈出四个数字，返回四个大小相同的单个数字的二值化图像

*std::vector\<cv::Mat\> getNumbers(const cv::Mat&)*

///用支持向量机预测输入图片中的四个数字

*std::vector\<int\> svm(std::vector\<cv::Mat\>, std::vector\<int\>, std::vector\<cv::Mat\>)*

///导入sim_samples中所有的图像进行处理，返回一个训练集

*std::vector\<cv::Mat\> process()*



### **Depend Libaries**
*opencv* 
