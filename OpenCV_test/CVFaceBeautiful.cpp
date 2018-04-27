//
//  CVFaceBeautiful.cpp
//  ChangeFaceLoacl
//
//  Created by zhahang on 2018/2/7.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include "CVFaceBeautiful.h"
#include <opencv2/photo.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

using namespace cv;


void whiteFace(Mat& matSelfPhoto, double alpha, int beta){
    for (int y = 0; y < matSelfPhoto.rows; y++)
    {
        for (int x = 0; x < matSelfPhoto.cols; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                matSelfPhoto.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha*(matSelfPhoto.at<Vec3b>(y, x)[c]) + beta);
            }
        }
    }
}

int faceBeautiful(const char *in_img_path, const char* out_img_path, double alpha, int beta){
    cv::Mat image = cv::imread(in_img_path);
    
    cv::Mat whiteMat = imread(in_img_path);
    whiteFace(whiteMat, alpha, beta);
    
    Mat dst;
    
    int value1 = 3, value2 = 1;     //磨皮程度与细节程度的确定
    
    int dx = value1 * 5;    //双边滤波参数之一
    double fc = value1*12.5; //双边滤波参数之一
    int p = 50; //透明度
    Mat temp1, temp2, temp3, temp4;
    
    //双边滤波
    bilateralFilter(whiteMat, temp1, dx, fc, fc);
    
    temp2 = (temp1 - whiteMat + 128);
    
    //高斯模糊
    GaussianBlur(temp2, temp3, Size(2 * value2 - 1, 2 * value2 - 1), 0, 0);
    
    temp4 = whiteMat + 2 * temp3 - 255;
    
    dst = (image*(100 - p) + temp4*p) / 100;
    dst.copyTo(image);
    imwrite(out_img_path, dst);
    return 0;
}
