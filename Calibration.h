//
// Created by protoke on 20/11/17.
//

#ifndef RECONSTRUCTION_3D_CALIBRATION_H
#define RECONSTRUCTION_3D_CALIBRATION_H

#include "opencv2/opencv.hpp"

#include "Camera.h"

using namespace cv;
using namespace std;

bool cameraParams(const vector<Mat>& images, Camera& camera, Size boardSize, float cellSize, Mat& display);

vector<Point2f> referencePoints(const Mat& image, Size boardSize, Mat& display);


#endif //RECONSTRUCTION_3D_CALIBRATION_H
