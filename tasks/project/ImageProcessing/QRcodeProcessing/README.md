## <h1>拼接残缺二维码并识别
 

### 作者: 林敬禹
### 修订: 林敬禹
### 日期: 2020-11-15
### 版本: 1.0.0
### 摘要: 提取图片中的残缺二维码，拼接后进行识别

### 说明：三个级别的程序分别在文件夹level1、level2、level3中，文件夹incomplete_QR_code_pics中是测试图片

### **Funtions**


1. *extract.cpp* 提取残缺二维码
2. *splice.cpp*   拼接残缺二维码
3. *identify.cpp*   识别拼接出来的二维码
4. *main.cpp*   调用函数处理输入的图片，输出运行时间


### **Interfaces**
  
/// 提取残缺二维码

*cv::Mat extractQRcode(cv::Mat&)*

/// 拼接残缺二维码

*cv::Mat spliceQRcode(std::vector\<cv::Mat\>)*

/// 识别二维码

*void identifyQRcode(cv::Mat)*


### **Depend Libaries**
*opencv*  

*zbar*
