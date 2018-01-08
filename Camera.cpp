//
// Created by protoke on 20/11/17.
//

#include "Camera.h"

void Camera::correctImage(const Mat& img, Mat& result){
    undistort(result, img, cameraMatrix, distCoeffs);
}
