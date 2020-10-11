# 使用OpenCV识别数码管
------------------------

## 1.图片的载入和预处理
### &ensp;&ensp;(1)图片的载入
&ensp; &ensp; 利用main函数自带的形参，使用imread()函数读入图片
```
if ( argc != 2 ){// 无图片路径
        cout << "Please input the path of the picture" << endl;
        return -1;
    }
    src_image = imread( argv[1], 1);
```
###&ensp;&ensp;(2)滤波
&ensp;&ensp;使用高斯滤波处理图像

##<br>2.图片的二值化
##&ensp;&ensp;(1)观察图片颜色
&ensp;&ensp;观察图片的颜色，发现数码管的颜色偏红色，考虑是否可以通过在rgb通道上筛选合适的范围来对图片进行数字的二值化。
##&ensp;&ensp;(2)图片的二值化
&ensp;&ensp;在利用一些软件（~~PhotoShop~~）进行观察后，确定了各个通道的上下限。因为模拟软件的颜色与实际图片有所差异，所以在这里的上下限使用不同的标准。
&ensp;&ensp;由于这里使用需要同时限定上下范围，所以不用`threshole()`, 而是换用`inRange()`函数进行二值化。
```
    int RedL = 180;
    int RedH = 255;
    int GreenL = 0;
    int GreenH = 140;
    int BlueL = 0;
    int BlueH = 140;
    
    inRange(srcImage, Scalar(BlueL, GreenL, RedL), Scalar(BlueH, GreenH, RedH), ret);
```
二值化的效果如下：
![二值化](./结果截图/二值化.png)

##<br>3.图片的形态学运算
&ensp;&ensp;使用开运算来处理二值化后图片上的小白点，然后在用闭运算来连接数字间的缝隙，确保在边缘检测时识别到的是完整的数字。
&ensp;&ensp;为了防止腐蚀时将数字部分也腐蚀掉，所以腐蚀时使用的核较小，而在膨胀时使用的核会大一点。
```
    Mat element_erode=getStructuringElement(MORPH_RECT,Size(2,2));//获取核
    Mat element_dilate=getStructuringElement(MORPH_RECT,Size(12,12));
    erode( g_binaryImage, g_binaryImage, element_erode); //腐蚀(开运算)
    dilate( g_binaryImage, g_binaryImage,element_dilate); //膨胀(闭运算)
    dilate( g_binaryImage, g_binaryImage,element_dilate);
    // namedWindow("膨胀一波", WINDOW_AUTOSIZE);
    // imshow("膨胀一波", g_binaryImage); -->
```

效果图如下：
![形态学处理](./结果截图/形态学运算.png)

##<br>4.边缘检测
&ensp;&ensp;使用`findContours()`函数来检测边缘，然后将检测到的边缘信息保存在`vector<vector<Point>> contours`中。
```
vector<vector<Point>> contours;
    findContours(binary_image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

    //输出边缘检测的效果图
    vector<Rect> t_rect;
    Mat t_binaryImage=binary_image.clone();

    for(auto It = contours.begin(); It < contours.end(); It++{
    // 画出可包围数字的最小矩形
        Rect rect = boundingRect(*It);
        rectangle(t_binaryImage, rect, Scalar(120, 255, 0), 2);
        t_rect.push_back(rect);
    } 

    // namedWindow("边缘检测", WINDOW_AUTOSIZE);
    // imshow("边缘检测", t_binaryImage);
    g_rect.assign(t_rect.begin(), t_rect.end());// 返回边缘的位置
```
效果图如下：
![边缘检测](./结果截图/边缘检测.png)

##<br>5.数字的分割
&ensp;&ensp;根据边缘检测时返回的边缘位置，对图片上的数字进行提取和分割，分割出来的单独数字保存在`vector<Mat> divisionNums`里面。
```
    if(g_rect.size()==0){
        cout << "Can't find the edge" << endl;
        return;
    }
    
    // 对边缘矩形按照x坐标进行排序，保证分割后得到的数字相对位置不变
    sort( g_rect.begin(), g_rect.end(), comp );

    for (int i=0; i<g_rect.size(); i++){
        Mat ROI = binaryImage( Rect(g_rect[i]));
        divideNums.push_back(ROI.clone());
    }
```

##<br>6.数字识别(穿线法)
&ensp;&ensp;使用穿线法对每一个单独的数字图片进行识别
```
    //先识别“1”
    if( 3*m.cols<m.rows){
        cout << 1 ;
        return ;
    }

    int x_half = m.cols/2;
    int y_one_third = m.rows/3;
    int y_two_third = 2*y_one_third;

    int LED[7]={0}; // 表示a~g号数码管

    // 识别 a, g, b
    for ( int i=0; i<m.rows; i++){
        uchar* row=m.ptr<uchar>(i);
        if(row[x_half]==255){
            if(i<y_one_third){
                LED[a]=1;
            }else if(i<y_two_third){
                LED[g]=1;
            }else{
                LED[d]=1;
            }
        }
    }

    // 识别 f, b, e, c
    for( int i=0; i<m.cols; i++){
        uchar* one_third_row = m.ptr<uchar>(y_one_third);
        uchar* two_third_row = m.ptr<uchar>(y_two_third);

        if(one_third_row[i]==255){
            if(i<x_half){
                LED[f]=1;
            }else{
                LED[b]=1;
            }
        }

        if(two_third_row[i]==255){
            if(i<x_half){
                LED[e]=1;
            }else{
                LED[c]=1;
            }
        }
    }

    if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==1 && LED[f]==1 && LED[g]==0){
        cout << 0 ;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==0 && LED[d]==1 && LED[e]==1 && LED[f]==0 && LED[g]==1){
        cout << 2 ;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==0 && LED[g]==1){
        cout << 3 ;
    }else if(LED[a]==0 && LED[b]==1 && LED[c]==1 && LED[d]==0 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << 4 ;
    }else if(LED[a]==1 && LED[b]==0 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << 5 ;
    }else if(LED[a]==1 && LED[b]==0 && LED[c]==1 && LED[d]==1 && LED[e]==1 && LED[f]==1 && LED[g]==1){
        cout << 6 ;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==0 && LED[e]==0 && LED[f]==0 && LED[g]==0){
        cout << 7 ;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==1 && LED[f]==1 && LED[g]==1){
        cout << 8 ;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << 9 ;
    }else{
        cout << "Can't distinguish the num" << endl ;
    }
```

输出结果：
![识别结果](./结果截图/结果.png)
