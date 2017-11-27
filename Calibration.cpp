//
// Created by protoke on 20/11/17.
//

#include "Calibration.h"


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
    image.copyTo(display);
    drawChessboardCorners(display, boardSize, corners, found);

    return corners;
}

