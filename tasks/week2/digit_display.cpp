// File Name: identify_numbers.cpp
// Author: shaaaaron
// Created Time: 11 Oct 2020 07:45:01 AM PDT
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

/*
@brief 检查（x1,y1）(x2,y2)之间是否有像素
@param image 函数应用的图像
*/
int cross(Mat image,int x1,int y1,int x2,int y2);

/*
@brief 图像中的数字
@param image 函数应用的图像
*/
int get_num(Mat image);

/*
@brief 检查对应像素点的值
@param image 函数应用的图像
@param x,y 图像对应的坐标
*/
int check_point(Mat image,int x,int y);

/*
@brief 返回a的n次方 
@param a 底数 
@param n 指数
*/
int intnum_power(int a,int n);

int main( int argc, char** argv ){
    int x;
    cin>>x;
    if(x==1){//1实现识别简单图片，2实现两张图片的数字识别，3实现识别实际图片（其中2尚未完成）
        Mat image1;
        image1=imread(argv[1], CV_LOAD_IMAGE_COLOR);//将图片存入变量
        if(!image1.data){//如果图片内容无法打开，结束程序
            cout <<"Could not open or find the image"<<endl ;
            return -1;
        }
        imshow("原图",image1);
        int redl=195;
        int redh= 255;
        int greenl= 0;
        int greenh=200;
        int bluel= 0;
        int blueh= 200;
        inRange(image1,Scalar(bluel,greenl,redl),Scalar(blueh,greenh,redh),image1);//将图片二值化，满足要求的区域置白色
        resize(image1,image1,Size(600,600*image1.rows/image1.cols));//调整图片大小
        Mat element=getStructuringElement(MORPH_RECT,Size(1,1));//获取核
        morphologyEx(image1,image1,MORPH_OPEN,element);//对图片进行开运算
        element=getStructuringElement(MORPH_RECT,Size(25,25));//调整核的大小
        dilate(image1,image1,element);//对图片进行膨胀，将每个数字内部连接起来
        vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(image1,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));//获取图像的内外轮廓
        
        
        vector<vector<Point>> contours_1(contours.size());
        vector<Rect> border_rect(contours.size());//存放所获取的内外轮廓所对应的矩形
        for(int i=0;i<contours.size();i++){ 
            approxPolyDP(Mat(contours[i]),contours_1[i],4,true);//将轮廓进行多边形拟合，获得对应矩形方便进一步处理
            border_rect[i]=boundingRect(Mat(contours_1[i]));//将多边形拟合近似的矩形存入
        }
        for(int i=0;i<contours.size( );i++){
            rectangle(image1,border_rect[i].tl(),border_rect[i].br(),Scalar(120,120,90),2,8,0);
        }
        namedWindow("效果图",WINDOW_NORMAL);
        imshow("效果图",image1);//显示处理后的数码管图像
        for(int i=0;i<border_rect.size();i++){
            for(int j=0;j<border_rect.size()-1;j++){
                if(border_rect[j].tl().x>border_rect[j+1].tl().x){
                    Rect x=border_rect[j];
                    border_rect[j]=border_rect[j+1];
                    border_rect[j+1]=x;
                }
            }
        }
        cout<<"The numeber is ";
        int j=0;
        for(int i=0;i<border_rect.size();i++){//对每个轮廓进行处理
            Mat mat_rect_i=image1(border_rect[i]);
            if((double(border_rect[i].height)/double(border_rect[i].width))>3.5&& (double(border_rect[i].height)/double(border_rect[i].width))<5){//通过矩形的长宽比判断是否为1
                cout<<"1";j++;
            }
            else if((double(border_rect[i].height)/double(border_rect[i].width))>1.35&& (double(border_rect[i].height)/double(border_rect[i].width))<2.4){
                int num=get_num(mat_rect_i);
                if(num!=-1){
                    cout<<num;j++;
                }else{
                    cout<<2;j++;
                }
            }
        }
        j=4-j;
        while(j--)cout<<"0";
        cout<<"."<<endl;
        waitKey(0);
        return 0;
    }
    
    else if(x==2){//两幅图片拼接未能完成
        Mat image1;
        image1=imread(argv[1], CV_LOAD_IMAGE_COLOR);
        Mat image2;
        image1=imread(argv[2], CV_LOAD_IMAGE_COLOR);
        addWeighted(image1, 0.5, image2, 0.5, 0, image1);
        return 0;
        
    }
    
    
    else{
        Mat image1;
        image1=imread(argv[1], CV_LOAD_IMAGE_COLOR);//将图片存入变量
        if(!image1.data){//如果图片内容无法打开，结束程序
            cout <<"Could not open or find the image"<<endl ;
            return -1;
        }
        imshow("原图",image1);
        int iLowH = 30; //   对本情况采用hsv进行处理
        int iHighH =255;    
        int iLowS = 130;     
        int iHighS = 255;    
        int iLowV = 190;    
        int iHighV = 255;
        Mat hsv;
        vector <Mat> hsvsplit;
        split(image1,hsvsplit);
        inRange(image1,Scalar(iLowH,iLowS,iLowV),Scalar(iHighH,iHighS,iHighV),image1);
        
        resize(image1,image1,Size(600,600*image1.rows/image1.cols));//调整图片大小
        Mat element=getStructuringElement(MORPH_RECT,Size(4,4));//获取核
        morphologyEx(image1,image1,MORPH_OPEN,element);//对图片进行开运算
        element=getStructuringElement(MORPH_RECT,Size(12,12));//调整核的大小
        dilate(image1,image1,element);//对图片进行膨胀，将每个数字内部连接起来
         vector<vector<Point>> contours;
        vector<Vec4i> hierarchy;
        findContours(image1,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));//获取图像的内外轮廓
       
        
        vector<vector<Point>> contours_1(contours.size());
        vector<Rect> border_rect(contours.size());//存放所获取的内外轮廓所对应的矩形
        for(int i=0;i<contours.size();i++){ 
            approxPolyDP(Mat(contours[i]),contours_1[i],4,true);//将轮廓进行多边形拟合，获得对应矩形方便进一步处理
            border_rect[i]=boundingRect(Mat(contours_1[i]));//将多边形拟合近似的矩形存入
        }
        for(int i=0;i<contours.size( );i++){
            rectangle(image1,border_rect[i].tl(),border_rect[i].br(),Scalar(120,120,90),2,8,0);
        }
        namedWindow("效果图",WINDOW_NORMAL);
        imshow("效果图",image1);//显示处理后的数码管图像
        for(int i=0;i<border_rect.size();i++){
            for(int j=0;j<border_rect.size()-1;j++){
                if(border_rect[j].tl().x>border_rect[j+1].tl().x){
                    Rect x=border_rect[j];
                    border_rect[j]=border_rect[j+1];
                    border_rect[j+1]=x;
                }
            }
        }
        for(int i=0;i<border_rect.size();i++){//对每个轮廓进行处理
            Mat mat_rect_i=image1(border_rect[i]);
            if((double(border_rect[i].height)/double(border_rect[i].width))>3&& (double(border_rect[i].height)/double(border_rect[i].width))<5){//通过矩形的长宽比判断是否为1
                cout<<"1";
            }
            else if((double(border_rect[i].height)/double(border_rect[i].width))>1.35&& (double(border_rect[i].height)/double(border_rect[i].width))<2.4){
                int num=get_num(mat_rect_i);
                if(num!=-1){
                    cout<<num;
                }
            }
        }
        cout<<endl;/**/
        waitKey(0);
        return 0;
    }
    
    
}

int intnum_power(int a,int n){
    if(n==0)return 1;
    if(n==1)return a;
    if(n%2){
        int num1=intnum_power(a,(n-1)/2);
        return a*num1*num1;
    }else{
        int num1=intnum_power(a,n/2);
        return num1*num1;
    }
}

int cross(Mat image,int x1,int y1,int x2,int y2){
    if(y1==y2){
        for(int i=x1;i<x2;i++){
            if(check_point(image,i,y1)>200)return 1;
        }
        return 0;
    }
    else{
        for(int i=y1;i<y2;i++){
            if(check_point(image,x1,i)>200)return 1;
        }
        return 0;
    }
}


int get_num(Mat image){
    bool a1,a2,a3,a4,a5,a6,a7;
    if(cross(image,int(0.5*image.cols),0,int(0.5*image.cols),int(0.25*image.rows)))a1=1;
    else a1=0;
    if(cross(image,0,int(0.25*image.rows),int(0.5*image.cols),int(0.25*image.rows)))a2=1;
    else a2=0;
    if(cross(image,int(0.5*image.cols),int(0.25*image.rows),int(image.cols),int(0.25*image.rows)))a3=1;
    else a3=0;
    if(cross(image,int(0.5*image.cols),int(0.25*image.rows),int(0.5*image.cols),int(0.75*image.rows)))a4=1;
    else a4=0;
    if(cross(image,0,int(0.75*image.rows),int(0.5*image.cols),int(0.75*image.rows)))a5=1;
    else a5=0;
    if(cross(image,int(0.5*image.cols),int(0.75*image.rows),int(image.cols),int(0.75*image.rows)))a6=1;
    else a6=0;
    if(cross(image,int(0.5*image.cols),int(0.75*image.rows),int(0.5*image.cols),int(image.rows)))a7=1;
    else a7=0;
    if(a1 !=0&&a2 ==0&&a3 !=0&&a4 !=0&&a5 !=0&&a6 ==0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 2;
    else if(a1 !=0&&a2 ==0&&a3 !=0&&a4 !=0&&a5 ==0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 3;
    else if(a1 ==0&&a2 !=0&&a3 !=0&&a4 !=0&&a5 ==0&&a6 !=0&&a7 ==0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 4;
    else if(a1 !=0&&a2 !=0&&a3 ==0&&a4 !=0&&a5 ==0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 5;
    else if(a1 !=0&&a2 !=0&&a3 ==0&&a4 !=0&&a5 !=0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 6;
    else if(a1 !=0&&a2 ==0&&a3 !=0&&a4 ==0&&a5 ==0&&a6 !=0&&a7 ==0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 7;
    else if(a1 !=0&&a2 ==0&&a3 !=0&&a4 ==0&&a5 ==0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 7;
    else if(a1 !=0&&a2 !=0&&a3 !=0&&a4 !=0&&a5 !=0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 8;
    else if(a1 !=0&&a2 !=0&&a3 !=0&&a4 !=0&&a5 ==0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 9;
    else if(a1 !=0&&a2 !=0&&a3 !=0&&a4 ==0&&a5 !=0&&a6 !=0&&a7 !=0&&(check_point(image,image.cols*0.5,image.rows*0.25) <= 150)&&(check_point(image,image.cols*0.5,image.rows*0.75) <= 150)) return 0;
    else return -1;
}

int check_point(Mat image,int x,int y){
    return *(image.begin<uchar>()+y*image.cols+x); //取出对应像素的值
}