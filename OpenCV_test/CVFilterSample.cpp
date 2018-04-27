//
//  CVFilterSample.cpp
//  OpenCV_test
//
//  Created by zhahang on 2018/4/21.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include "CVFilterSample.h"


#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int showBoxFilter(const char *path){
    Mat image = imread(path);
//    namedWindow("均值滤波-src");
//    namedWindow("均值滤波-dst");
    
    imshow("均值滤波-src", image);
    Mat out;
    boxFilter(image, out, -1, Size(25, 25));
    imshow("均值滤波-dst", out);
    
    waitKey(0);
    return 0;
}

int showBlurFilter(const char *path){
    Mat image = imread(path);
    //    namedWindow("均值滤波-src");
    //    namedWindow("均值滤波-dst");
    
    imshow("均值滤波-src", image);
    
    Mat out;
    blur(image, out, Size(7, 7));
    imshow("均值滤波-dst", out);
    
    waitKey(0);
    return 0;
}

int showGaussianFilter(const char *path){
    Mat image = imread(path);
    //    namedWindow("均值滤波-src");
    //    namedWindow("均值滤波-dst");
    
    imshow("均值滤波-src", image);
    
    Mat out;
    GaussianBlur(image, out, Size(3, 3), 0, 3);
    imshow("均值滤波-dst", out);
    
    waitKey(0);
    return 0;
}

int showMedianBlur(const char *path){
    Mat image = imread(path);
    imshow("中值滤波-src", image);
    
    Mat out;
    medianBlur(image, out, 7);
    imshow("中值滤波-dst", out);
    
    waitKey(0);
    return 0;
}

int showBilateralFilter(const char *path){
    Mat image = imread(path);
    imshow("双边滤波-src", image);
    
    Mat out;
    bilateralFilter(image, out, 25, 25*2, 25/2);
    imshow("双边滤波-dst", out);
    
    waitKey(0);
    return 0;
}

int showDilate(const char *path){
    Mat image = imread(path);
    imshow("膨胀操作-src", image);
    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 15));
    Mat out;
    dilate(image, out, kernel);
    imshow("膨胀操作-dst", out);
    
    waitKey(0);
    return 0;
}

int showErode(const char *path){
    Mat image = imread(path);
    imshow("腐蚀操作-src", image);
    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 15));
    Mat out;
    erode(image, out, kernel);
    imshow("腐蚀操作-dst", out);
    
    waitKey(0);
    return 0;
}

int showMorphologyEx(const char *path, int morphType){
    Mat image = imread(path);
    imshow("形态学操作-src", image);
    
    Mat kernel = getStructuringElement(MORPH_RECT, Size(15, 15));
    Mat out;
    morphologyEx(image, out, morphType, kernel);
    imshow("形态学操作-dst", out);
    waitKey(0);
    return 0;
}









