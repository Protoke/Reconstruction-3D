//
// Created by protoke on 20/11/17.
//

#ifndef RECONSTRUCTION_3D_CAMERA_H
#define RECONSTRUCTION_3D_CAMERA_H

#include <string>

#include "opencv2/opencv.hpp"
#include "Plan.h"

using namespace std;
using namespace cv;

class Camera {
public:
    Camera();
    Camera(string calibrationFile);

    void correctImage(Mat& img);

private:
    Point2f center;
    Plan focalPlan;
    Size scaleFactor;
};


#endif //RECONSTRUCTION_3D_CAMERA_H
