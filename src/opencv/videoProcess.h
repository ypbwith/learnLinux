//
// Created by root on 5/9/19.
//

#ifndef LEARNLINUX_VIDEOPROCESS_H
#define LEARNLINUX_VIDEOPROCESS_H

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

class videoProcess
{
public:
    videoProcess ();
    videoProcess (string rtspPath);
    ~videoProcess();

public:
    Mat videoIn;
    VideoCapture * cap;
    string rtspPath;

    pthread_t videoInThreadPt;

    int videoInThreadCreat();

    int videoInThreadCreat(int capChNum);

    int videoInThreadCreat(string rtspPath);

    static void *videoInThread( void *param);

};

#endif //LEARNLINUX_VIDEOPROCESS_H

