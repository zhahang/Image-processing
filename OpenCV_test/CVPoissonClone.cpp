//
//  CVPoissonClone.cpp
//  ChangeFaceLoacl
//
//  Created by zhahang on 2018/1/17.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#include "CVPoissonClone.h"

#include "opencv2/core/core.hpp"
#include <opencv2/photo.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

int CVPoissonCloning(string &src_path, string &dst_path, string &mask_path, string &out_path,
                     Point templet_face_center){
    // Read images : src image will be cloned into dst
    Mat src = imread(src_path);
    Mat dst = imread(dst_path);
    if(src.empty() || dst.empty()){
        return -1;
    }
    
//    // Create a rough mask around the airplane.
//    Mat src_mask = Mat::zeros(src.rows, src.cols, src.depth());
//
//    // Define the mask as a closed polygon
//    Point poly[1][7];
//    poly[0][0] = Point(4, 80);
//    poly[0][1] = Point(30, 54);
//    poly[0][2] = Point(151,63);
//    poly[0][3] = Point(254,37);
//    poly[0][4] = Point(298,90);
//    poly[0][5] = Point(272,134);
//    poly[0][6] = Point(43,122);
//
//    const Point* polygons[1] = { poly[0] };
//    int num_points[] = { 7 };
//
//    // Create mask by filling the polygon
//
//    fillPoly(src_mask, polygons, num_points, 1, Scalar(255,255,255));
    
    // The location of the center of the src in the dst
    //Point center(228, 317);
    
    
    Mat mask = 255 * Mat::ones(src.rows, src.cols, src.depth());
    Point center(dst.cols / 2, dst.rows / 2);
    // Seamlessly clone src into dst and put the results in output
    Mat output;
    seamlessClone(src, dst, mask, center, output, NORMAL_CLONE);
    
//    vector<int> compression_params;
//    compression_params.push_back(IMWRITE_PNG_COMPRESSION);
//    compression_params.push_back(0);
    // Save result
//    imwrite(out_path, output);
    imshow("normal_clone", output);
    waitKey(0);
    return 0;
}

int CVPoissonCloning(const char *src_path, const char *dst_path){
    string srcPath = src_path;
    string dstPath = dst_path;
    string maskPath = "";
    string outpath = "";
    cv::Point point(0.0);
    return CVPoissonCloning(srcPath, dstPath, maskPath, outpath, point);
}
