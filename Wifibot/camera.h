#ifndef Camera_H
#define Camera_H

#include "viewergl.h"

#include "opencv2/core/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

class Camera : public QObject
{

    Q_OBJECT

public:
    Camera();
    void setVideoOutput(ViewerGl *viewer);
    void start();
    void stop();

private:
    ViewerGl *viewer;

    cv::VideoCapture mCapture;

    // Get the path to your CSV:
    string fn_haar;

    // These vectors hold the images and corresponding labels:
    vector<Mat> images;
    vector<int> labels;

    int im_width;
    int im_height;

    Ptr<cv::face::FaceRecognizer> model;

    CascadeClassifier haar_cascade;

    cv::Mat frame;
    Mat gray;
    Mat original;

    vector< Rect_<int> > faces;

    Mat face;
    Rect face_i;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // Camera_H
