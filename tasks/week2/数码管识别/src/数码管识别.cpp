#include"myFunction_sim.hpp"
// #include"myFunction_act.hpp" // 识别act组时使用这个头文件
int main(int argc, char** argv) {
    Mat src_image;
    if ( argc != 2 ){
        cout << "Please input the path of the picture" << endl;
        return -1;
    }
    src_image = imread( argv[1], 1);
    
    namedWindow("最初", 1);
    imshow("最初", src_image);

    // GaussianBlur( src_image,src_image, Size(5,5), 0.0 );

    Mat binary_image;
    myBinarization(src_image, binary_image);

    myMorphology(binary_image);

    vector<Rect> edge;
    myContours(binary_image, edge);

    vector<Mat> images_of_num;
    myNumDivision(binary_image, edge, images_of_num);

    for(int i=0; i<images_of_num.size(); i++){
        myDiscern(images_of_num.at(i));
    }

    waitKey(0);
    return 0;
}
