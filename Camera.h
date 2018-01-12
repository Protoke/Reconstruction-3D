//
// Created by protoke on 20/11/17.
//

#ifndef RECONSTRUCTION_3D_CAMERA_H
#define RECONSTRUCTION_3D_CAMERA_H

#include <string>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Camera {
public:
    void correctImage(const Mat& img, Mat& result);

    Mat cameraMatrix;
    Mat distCoeffs;
    double error;
};


#endif //RECONSTRUCTION_3D_CAMERA_H
