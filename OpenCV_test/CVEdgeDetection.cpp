//
//  CVEdgeDetection.cpp
//  OpenCV_test
//
//  Created by zhahang on 2018/4/27.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include "CVEdgeDetection.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;


int showCannyEdge(const char *path){
    
    //载入原始图
    Mat src = imread(path);  //工程目录下应该有一张名为1.jpg的素材图
    Mat src1=src.clone();
    
    /*
    //显示原始图
    imshow("Canny边缘检测-src", src);
    
    //----------------------------------------------------------------------------------
    //  一、最简单的canny用法，拿到原图后直接用。
    //----------------------------------------------------------------------------------
    Canny( src, src, 150, 100, 3);
    imshow("Canny边缘检测-dst1", src);
    */
 
    //----------------------------------------------------------------------------------
    //  二、高阶的canny用法，转成灰度图，降噪，用canny，最后将得到的边缘作为掩码，拷贝原图到效果图上，得到彩色的边缘图
    //----------------------------------------------------------------------------------
    Mat dst,edge,gray;
    
    // 【1】创建与src同类型和大小的矩阵(dst)
    dst.create( src1.size(), src1.type() );
    
    // 【2】将原图像转换为灰度图像
    cvtColor( src1, gray, CV_BGR2GRAY );
    
    // 【3】先用使用 3x3内核来降噪
    blur( gray, edge, Size(3,3) );
    
    // 【4】运行Canny算子
    Canny( edge, edge, 3, 9, 3);
    
    //【5】将g_dstImage内的所有元素设置为0
    dst = Scalar::all(0);
    
    //【6】使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
    src1.copyTo( dst, edge);
    
    //【7】显示效果图
    imshow("【效果图】Canny边缘检测2", dst);
    
    
    waitKey(0);
    
    return 0;
}

int showSobelEdge(const char *path){
    //【0】创建 grad_x 和 grad_y 矩阵
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y,dst;
    
    //【1】载入原始图
    Mat src = imread(path);  //工程目录下应该有一张名为1.jpg的素材图
    
    //【2】显示原始图
    imshow("【原始图】sobel边缘检测", src);
    
    //【3】求 X方向梯度
    Sobel( src, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );
    imshow("【效果图】 X方向Sobel", abs_grad_x);
    
    //【4】求Y方向梯度
    Sobel( src, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );
    imshow("【效果图】Y方向Sobel", abs_grad_y);
    
    //【5】合并梯度(近似)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst );
    imshow("【效果图】整体方向Sobel", dst);
    
    waitKey(0);
    return 0;
}
