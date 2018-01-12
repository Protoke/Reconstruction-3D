//
// Created by protoke on 20/11/17.
//

#include "Calibration.h"

#include <iostream>

using namespace std;

bool cameraParams(const vector<Mat>& images, Camera& camera, Size boardSize, float cellSize, Mat& display){
    // Compute corners positions
    vector<vector<Point2f>> corners;

    int count = 0;
    for (int i = 0; i < images.size(); ++i) {
        vector<Point2f> cornersImg = referencePoints(images[i], boardSize, display);
        if(cornersImg.size() > 0){
            corners.push_back(cornersImg);
            count++;
        }
    }

    if(count < 2)
        return false;

    // Compute real corners positions
    vector<vector<Point3f>> realCorners;

    vector<Point3f> tempCorners;
    for (int i = 0; i < boardSize.height; ++i) {
        for (int j = 0; j < boardSize.width; ++j) {
            tempCorners.push_back(Point3f(float(j)*cellSize, float(i)*cellSize, 0));
        }
    }
    realCorners.push_back(tempCorners);
    realCorners.resize(corners.size(), realCorners[0]);

    // Outputs params
    Mat cameraMatrix = Mat::eye(3, 3, CV_64F);
    Mat distCoeffs = Mat::zeros(8, 1, CV_64F);
    vector<Mat> rVecs, tVecs;

    double rms = calibrateCamera(realCorners, corners, boardSize, cameraMatrix,
                                 distCoeffs, rVecs, tVecs, CV_CALIB_FIX_K4|CV_CALIB_FIX_K5);

    camera.cameraMatrix = cameraMatrix;
    camera.distCoeffs = distCoeffs;
    camera.error = rms;

    return true;
}

vector<Point2f> referencePoints(const Mat& image, Size boardSize, Mat& display){

    vector<Point2f> corners;
    bool found = findChessboardCorners(image, boardSize, corners,
                                       CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FAST_CHECK | CV_CALIB_CB_NORMALIZE_IMAGE);

    if(!found){
        cerr << "Corners not found" << endl;
        return vector<Point2f>();
    }
    Mat imgGray;
    cvtColor(image, imgGray, COLOR_BGR2GRAY);
    cornerSubPix(imgGray, corners, Size(11,11), Size(-1,-1),
                 TermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER, 30, 0.1 ));

    /* Display */
    display = image.clone();
    drawChessboardCorners(display, boardSize, corners, found);

    return corners;
}

