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
    int nbImages = 39;
    for (int i = 1; i <= nbImages; ++i) {
        string filename = "./data/fish" + to_string(i) + ".jpg";
        images.push_back(imread(filename));
    }

    Mat display;
    Camera c;
    bool found = cameraParams(images, c, Size(7, 4), 0.02, display);

    if(found){
        cout << "error : " << c.error << endl << "cameraMatrix : " << c.cameraMatrix << endl;

        for (int i = 0; i < 39; ++i) {
            Mat result;
            images[i].copyTo(result);
            c.correctImage(images[i], result);

            namedWindow("Source", WINDOW_FREERATIO);
            resizeWindow("Source", 600, 800);
            imshow("Source", images[i]);
            namedWindow("Result", WINDOW_FREERATIO);
            resizeWindow("Result", 600, 800);
            imshow("Result", result);

            waitKey();
        }
    }

    return 0;
}