//
// Created by protoke on 20/11/17.
//

#ifndef RECONSTRUCTION_3D_PLAN_H
#define RECONSTRUCTION_3D_PLAN_H

#include "opencv2/opencv.hpp"

using namespace cv;

class Plan {
public:
    Plan();
    Plan(Point3f origin_, Vec3f normal);

    Point3f intersect(Point3f p1, Point3f p2);

private:
    Point3f origin;
    Vec3f normal;
};


#endif //RECONSTRUCTION_3D_PLAN_H
