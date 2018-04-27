//
//  CVPoissonClone.hpp
//  ChangeFaceLoacl
//
//  Created by zhahang on 2018/1/17.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#ifndef CVPoissonClone_hpp
#define CVPoissonClone_hpp

#include <stdio.h>
#include <string>
#include <opencv2/core/types.hpp>


int CVPoissonCloning(std::string &src_path, std::string &dst_path, std::string &mask_path, std::string &out_path,
                     cv::Point templet_face_center);

int CVPoissonCloning(const char *src_path, const char *dst_path);

#endif /* CVPoissonClone_hpp */
