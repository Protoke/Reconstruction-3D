//
// Created by protoke on 20/11/17.
//

#ifndef RECONSTRUCTION_3D_CALIBRATION_H
#define RECONSTRUCTION_3D_CALIBRATION_H

#include "opencv2/opencv.hpp"

#include "Camera.h"

using namespace cv;
using namespace std;

void cameraParams(const Mat& image, Camera& camera);

vector<Point2f> referencePoints(const Mat& image);

void computeError(const Camera& camera);


#endif //RECONSTRUCTION_3D_CALIBRATION_H
