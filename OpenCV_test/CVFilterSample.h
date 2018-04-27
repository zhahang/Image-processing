//
//  CVFilterSample.hpp
//  OpenCV_test
//
//  Created by zhahang on 2018/4/21.
//  Copyright © 2018年 zhahang. All rights reserved.
//

#ifndef CVFilterSample_hpp
#define CVFilterSample_hpp

#include <stdio.h>


int showBoxFilter(const char *path);
int showBlurFilter(const char *path);
int showGaussianFilter(const char *path);
int showMedianBlur(const char *path);
int showBilateralFilter(const char *path);
int showDilate(const char *path);
int showErode(const char *path);


/**
 //! type of morphological operation
 enum MorphTypes{
 MORPH_ERODE    = 0, //!< see #erode
 MORPH_DILATE   = 1, //!< see #dilate
 MORPH_OPEN     = 2, //!< an opening operation
 //!< \f[\texttt{dst} = \mathrm{open} ( \texttt{src} , \texttt{element} )= \mathrm{dilate} ( \mathrm{erode} ( \texttt{src} , \texttt{element} ))\f]
 MORPH_CLOSE    = 3, //!< a closing operation
 //!< \f[\texttt{dst} = \mathrm{close} ( \texttt{src} , \texttt{element} )= \mathrm{erode} ( \mathrm{dilate} ( \texttt{src} , \texttt{element} ))\f]
 MORPH_GRADIENT = 4, //!< a morphological gradient
 //!< \f[\texttt{dst} = \mathrm{morph\_grad} ( \texttt{src} , \texttt{element} )= \mathrm{dilate} ( \texttt{src} , \texttt{element} )- \mathrm{erode} ( \texttt{src} , \texttt{element} )\f]
 MORPH_TOPHAT   = 5, //!< "top hat"
 //!< \f[\texttt{dst} = \mathrm{tophat} ( \texttt{src} , \texttt{element} )= \texttt{src} - \mathrm{open} ( \texttt{src} , \texttt{element} )\f]
 MORPH_BLACKHAT = 6, //!< "black hat"
 //!< \f[\texttt{dst} = \mathrm{blackhat} ( \texttt{src} , \texttt{element} )= \mathrm{close} ( \texttt{src} , \texttt{element} )- \texttt{src}\f]
 MORPH_HITMISS  = 7  //!< "hit or miss"
 //!<   .- Only supported for CV_8UC1 binary images. A tutorial can be found in the documentation
 };
 */
int showMorphologyEx(const char *path, int morphType);

#endif /* CVFilterSample_hpp */
