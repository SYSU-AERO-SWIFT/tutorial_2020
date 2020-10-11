## 数码管数字识别项目 readme

- Author: zhouyu
- Revised: zhouyu
- Date: 2020-10-10
- Version: 1.0.0
- Abstract:识别图片中数码管上的数字

### Functions:
	int cross(Mat image,int x1,int y1,int x2,int y2);
	//识别该直线上是否有像素点。

	int get_num(Mat image);
	//识别对应图像中的元素。

	int check_point(Mat image,int x,int y)；
	//检查对应点是否为白色。

### Interfaces:
	int cross(Mat image,int x1,int y1,int x2,int y2);
	//image为图片，其余四个参数为坐标

	int get_num(Mat image)；
	//image为图片

	int check_point(Mat image,int x,int y)；
	//image为图片，其余参数为坐标
### Depend Libraries:
	无


