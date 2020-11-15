## <h1>拼接残缺二维码并识别
 

### 作者: 林敬禹
### 修订: 林敬禹
### 日期: 2020-11-15
### 版本: 1.0.0
### 摘要: 实时提取视频中的残缺二维码，拼接后进行识别


### **Funtions**
 

1. *extract.cpp* 处理有信息的帧，提取残缺二维码
2. *processVideo.cpp* 调用函数处理视频，显示出提取到的二维码区域，获得二维码的四个部分
3. *splice.cpp*   拼接残缺二维码
4. *identify.cpp*   识别拼接出来的二维码
5. *main.cpp*   调用函数处理视频


### **Interfaces**
   
/// 提取残缺二维码

*void process(cv::Mat&, std::vector\<std::vector\<cv::Mat\>\>&, cv::Rect&, std::vector\<cv::Mat\>&)*

/// 处理视频

*std::vector\<cv::Mat\> processVideo(std::string)*

/// 拼接残缺二维码

*cv::Mat spliceQRcode(std::vector\<cv::Mat\>)*

/// 识别二维码

*void identifyQRcode(cv::Mat)*

/// 剪切二维码块并矫正

*void cut(cv::Mat, std::vector\<cv::Point\>)*


### **Depend Libaries**
*opencv*  

*zbar*
