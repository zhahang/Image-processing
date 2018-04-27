//
//  TrackbarSample.cpp
//  OpenCV_test
//
//  Created by zhahang on 2018/2/24.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include "TrackbarSample.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;
using namespace std;

static Mat img;
static int threshval = 160;


static void on_trackbar(int, void*)
{
    Mat bw = threshval < 128 ? (img < threshval) : (img > threshval);
    
    //定义点和向量
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    
    //查找轮廓
    findContours( bw, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
    //初始化dst
    Mat dst = Mat::zeros(img.size(), CV_8UC3);
    //开始处理
    if( !contours.empty() && !hierarchy.empty() )
    {
        //遍历所有顶层轮廓，随机生成颜色值绘制给各连接组成部分
        int idx = 0;
        for( ; idx >= 0; idx = hierarchy[idx][0] )
        {
            Scalar color( (rand()&255), (rand()&255), (rand()&255) );
            //绘制填充轮廓
            drawContours( dst, contours, idx, color, CV_FILLED, 8, hierarchy );
        }
    }
    //显示窗口
    imshow( "Connected Components", dst );
}

int exec_color_change(const char *path){
    //    system("color 5F");
    //载入图片
    img = imread(path, 0);
    if( !img.data ) { printf("Oh，no，读取img图片文件错误~！ \n"); return -1; }
    
    //显示原图
    namedWindow( "Image", 1 );
    imshow( "Image", img );
    
    //创建处理窗口
    namedWindow( "Connected Components", 1 );
    //创建轨迹条
    createTrackbar( "Threshold", "Connected Components", &threshval, 255, on_trackbar );
    on_trackbar(threshval, 0);//轨迹条回调函数
    
    waitKey(0);
    return 0;
}


static int g_nContrastValue; //对比度值
static int g_nBrightValue;  //亮度值
static Mat g_srcImage,g_dstImage;

//-----------------------------【ContrastAndBright( )函数】------------------------------------
//     描述：改变图像对比度和亮度值的回调函数
//-----------------------------------------------------------------------------------------------
static void ContrastAndBright(int, void *)
{
    
    //创建窗口
    namedWindow("【原始图窗口】", 1);
    
    //三个for循环，执行运算 g_dstImage(i,j) =a*g_srcImage(i,j) + b
    for(int y = 0; y < g_srcImage.rows; y++ )
    {
        for(int x = 0; x < g_srcImage.cols; x++ )
        {
            for(int c = 0; c < 3; c++ )
            {
                g_dstImage.at<Vec3b>(y,x)[c]= saturate_cast<uchar>( (g_nContrastValue*0.01)*(g_srcImage.at<Vec3b>(y,x)[c] ) + g_nBrightValue );
            }
        }
    }
    cout<<"g_nContrastValue="<<g_nContrastValue<<endl;
    cout<<"g_nBrightValue="<<g_nBrightValue<<endl;
    //显示图像
    imshow("【原始图窗口】", g_srcImage);
    imshow("【效果图窗口】", g_dstImage);
}

int exec_Contrast_Bright(const char *path)
{
    //改变控制台前景色和背景色
//    system("color5F");
    
    //读入用户提供的图像
    g_srcImage= imread(path);
    if(!g_srcImage.data ) { printf("Oh，no，读取g_srcImage图片错误~！\n"); return false; }
    g_dstImage= Mat::zeros( g_srcImage.size(), g_srcImage.type() );
    
    //设定对比度和亮度的初值
    g_nContrastValue=80;
    g_nBrightValue=80;
    
    //创建窗口
    namedWindow("效果图窗口", 1);
    
    //创建轨迹条
    createTrackbar("对比度：", "效果图窗口",&g_nContrastValue,300, ContrastAndBright );
    createTrackbar("亮   度：","效果图窗口",&g_nBrightValue,200, ContrastAndBright );
    
    //调用回调函数
    ContrastAndBright(g_nContrastValue,0);
    ContrastAndBright(g_nBrightValue,0);
    
    //输出一些帮助信息
    cout<<"按下“q”键时，程序退出"<<endl;
    //按下“q”键时，程序退出
    while(char(waitKey(1)) != 'q') {}
    return 0;
}


