//
// Created by protoke on 20/11/17.
//

#include "opencv2/opencv.hpp"

#include "Calibration.h"

using namespace std;
using namespace cv;

int main(){

    Mat image = imread("../data/20171120_111832.jpg");

    Mat display;
    vector<Point2f> corners = referencePoints(image, Size(9, 6), display);


    if(corners.size() > 0){
        namedWindow("chessboard", WINDOW_FREERATIO);
        resizeWindow("chessboard", 600, 800);
        imshow("chessboard", display);
    }

    waitKey();

    return 0;
}

/*
 ****** Notes ******
 *
 * Fonctions utiles : https://docs.opencv.org/2.4/modules/calib3d/doc/camera_calibration_and_3d_reconstruction.html
 *
 *
 */