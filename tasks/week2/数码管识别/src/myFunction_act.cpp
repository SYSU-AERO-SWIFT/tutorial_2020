
#include"myFunction_act.hpp"

// void myExtract( Mat &src, Mat &ret ){
//     cvtColor(src, ret, COLOR_BGR2GRAY);
//     inRange(ret, 175, 230, ret);
//     Mat element_erode=getStructuringElement(MORPH_RECT,Size(4,4));//获取核
//     dilate( ret, ret, element_erode);

//     Mat binary_image;
//     threshold(ret, binary_image, 10, 255, THRESH_BINARY_INV);
//     namedWindow("割取", WINDOW_AUTOSIZE);
// 	   imshow("割取", binary_image);


// //     // vector<vector<Point>> contours;
// //     // findContours(binary_image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );
// //     // vector<Rect> t_rect;
// //     // Mat t_binaryImage=binary_image.clone();

// //     // for(auto It = contours.begin(); It < contours.end(); It++){
// //     //     //画出可包围数字的最小矩形
// //     //     Rect rect = boundingRect(*It);
// //     //     rectangle(t_binaryImage, rect, Scalar(120, 255, 0), 2);
// //     //     t_rect.push_back(rect);
// //     // }
// //     // namedWindow("边缘检测", WINDOW_AUTOSIZE);
// // 	// imshow("边缘检测", t_rect.at(1));
// }



// void myPreprocess( Mat &image ){
//     Mat gray_image;
//     cvtColor(image, gray_image, COLOR_BGR2GRAY);
//     // adaptiveThreshold(gray_image, gray_image, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 0);
//     Mat mask;
//     threshold(gray_image, mask, 190, 30, THRESH_BINARY);
//     namedWindow("mask", WINDOW_AUTOSIZE);
//     imshow("mask", mask);
//     illuminationChange(image, mask, image, 1.0, 1.0);
//     namedWindow("预处理", WINDOW_AUTOSIZE);
//     imshow("预处理", image);
// }

void myBinarization(Mat &srcImage, Mat &ret){
    GaussianBlur(srcImage, srcImage, Size(1,1), 0.0);
    int RedL = 230;
    int RedH = 255;
    int GreenL = 0;
    int GreenH = 200;
    int BlueL = 0;
    int BlueH = 200;
    inRange(srcImage, Scalar(BlueL, GreenL, RedL), Scalar(BlueH, GreenH, RedH), ret);
    // cvtColor(srcImage, ret, COLOR_BGR2GRAY);
    // inRange(ret, 150, 255, ret);
    
    namedWindow( "二值化", WINDOW_AUTOSIZE );
    imshow("二值化", ret);
}


void myMorphology( Mat &g_binaryImage ){
    // Mat element_erode=getStructuringElement(MORPH_RECT,Size(2,2));//获取核
    Mat element_dilate=getStructuringElement(MORPH_RECT,Size(8,8));//获取核
    // erode( g_binaryImage, g_binaryImage, element_erode); //腐蚀
    dilate( g_binaryImage, g_binaryImage,element_dilate); //膨胀
    dilate( g_binaryImage, g_binaryImage,element_dilate);
    namedWindow("膨胀一波", WINDOW_AUTOSIZE);
    imshow("膨胀一波", g_binaryImage);
}



void myContours( Mat &binary_image , vector<Rect> &g_rect ){
    vector<vector<Point>> contours;
    findContours(binary_image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE );

    vector<Rect> t_rect;
    Mat t_binaryImage=binary_image.clone();

    for(auto It = contours.begin(); It < contours.end(); It++){
        //画出可包围数字的最小矩形
        Rect rect = boundingRect(*It);
        rectangle(t_binaryImage, rect, Scalar(120, 255, 0), 2);
        t_rect.push_back(rect);
    }

    namedWindow("边缘检测", WINDOW_AUTOSIZE);
	imshow("边缘检测", t_binaryImage);


    // vector<vector<Point> > contours_poly( contours.size() );
	// vector<Rect> t_rect( contours.size() );
	
	// for( unsigned int i = 0; i < contours.size(); i++ )
	// { 
	// 	approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
	// 	t_rect[i] = boundingRect( Mat(contours_poly[i]) );
	// }
	// Mat drawing = Mat::zeros( binary_image.size(), CV_8UC3 );
	// for( int unsigned i = 0; i<contours.size(); i++ ){
	// 	Scalar color = Scalar( 125,125,90 );
	// 	drawContours( drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point() );
	// 	rectangle( binary_image, t_rect[i].tl(), t_rect[i].br(), color, 2, 8, 0 );
	// }

    // namedWindow("边缘检测", WINDOW_AUTOSIZE);
    // imshow("边缘检测", binary_image);

    g_rect.assign(t_rect.begin(), t_rect.end());
}

bool comp( const Rect &a, const Rect &b ){
    return a.x<b.x;
}

// g_rect: 检测到的边缘的位置，用来分割数字
void myNumDivision( Mat &binaryImage, vector<Rect> &g_rect, vector<Mat> &divideNums ){
    if(g_rect.size()==0){
        cout << "Can't find the edge" << endl;
        return;
    }
    // cout<<"I am here!"<<endl;
    sort( g_rect.begin(), g_rect.end(), comp );

    for (int i=0; i<g_rect.size(); i++){
        Mat ROI = binaryImage( Rect(g_rect[i]));
        divideNums.push_back(ROI.clone());
    }
}

enum SegLED{a, b, c, d, e, f, g};

//用穿线法识别数字
void myDiscern( Mat &m ){
    //先识别“1”
    if( 3*m.cols<m.rows){
        cout << "The num is " << 1 << endl;
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
        cout << "The num is " << 0 << endl;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==0 && LED[d]==1 && LED[e]==1 && LED[f]==0 && LED[g]==1){
        cout << "The num is " << 2 << endl;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==0 && LED[g]==1){
        cout << "The num is " << 3 << endl;
    }else if(LED[a]==0 && LED[b]==1 && LED[c]==1 && LED[d]==0 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << "The num is " << 4 << endl;
    }else if(LED[a]==1 && LED[b]==0 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << "The num is " << 5 << endl;
    }else if(LED[a]==1 && LED[b]==0 && LED[c]==1 && LED[d]==1 && LED[e]==1 && LED[f]==1 && LED[g]==1){
        cout << "The num is " << 6 << endl;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==0 && LED[e]==0 && LED[f]==0 && LED[g]==0){
        cout << "The num is " << 7 << endl;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==1 && LED[f]==1 && LED[g]==1){
        cout << "The num is " << 8 << endl;
    }else if(LED[a]==1 && LED[b]==1 && LED[c]==1 && LED[d]==1 && LED[e]==0 && LED[f]==1 && LED[g]==1){
        cout << "The num is " << 9 << endl;
    }else{
        cout << "Can't distinguish the num" << endl;
    }
}


