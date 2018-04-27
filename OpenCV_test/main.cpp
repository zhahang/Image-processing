//
//  main.cpp
//  OpenCV_test
//
//  Created by zhahang on 2018/2/24.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include <iostream>
#include "TrackbarSample.h"
#include "CVFaceBeautiful.h"
#include "CVFilterSample.h"
#include "CVPoissonClone.h"
#include "CVEdgeDetection.h"


int main(int argc, const char * argv[]) {
    // insert code here...
//    std::cout << "Hello, World!\n";
    
////facebeautiful
//    const char *in_path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/OpenCV_test/resource/3.jpg";
//    const char *out_path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/OpenCV_test/resource/3_out_1.jpg";
//    faceBeautiful(in_path, out_path, 1.7, 80);
//    exec_Contrast_Bright(img_path);
    
////image filter
//    const char *path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/OpenCV_test/resource/1.jpg";
//    showBoxFilter(path);
//    showBlurFilter(path);
//    showGaussianFilter(path);
//    showMedianBlur(path);
//    showBilateralFilter(path);
//    showDilate(path);
//    showErode(path);
//    showMorphologyEx(path, 2);
    
////image edge detection
    const char *path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/Image-processing/resource/1.png";
//    showCannyEdge(path);
    showSobelEdge(path);
    
    
    
    
////image poisson clone
//    const char *src_path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/OpenCV_test/resource/WechatIMG61.jpeg";
//    const char *dst_path = "/Users/zhahang/Desktop/Dev/CPlus/Demo/opencv_test/OpenCV_test/resource/WechatIMG60.jpeg";
//    CVPoissonCloning(src_path, dst_path);
    
    return 0;
}
