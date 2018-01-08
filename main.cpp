//
// Created by protoke on 20/11/17.
//

#include "opencv2/opencv.hpp"

#include "Calibration.h"
#include "Camera.h"

#include <string>

using namespace std;
using namespace cv;

int main(){
    vector<Mat> images;
    for (int i = 1; i <= 11; ++i) {
        string filename = "../data/chessboard" + to_string(i) + ".jpg";
//        cout << filename << endl;
        images.push_back(imread(filename));
    }


    Mat display;
    Camera c;
    bool found = cameraParams(images, c, Size(9, 6), 0.02, display);

    if(found){
        namedWindow("chessboard", WINDOW_FREERATIO);
        resizeWindow("chessboard", 600, 800);
        imshow("chessboard", display);

        Mat result;
        images[10].copyTo(result);
        c.correctImage(images[10], result);

        namedWindow("result", WINDOW_FREERATIO);
        resizeWindow("result", 600, 800);
        imshow("result", result);
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