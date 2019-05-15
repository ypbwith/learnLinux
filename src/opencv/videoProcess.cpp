//
// Created by root on 5/9/19.
//

#include "videoProcess.h"

videoProcess::videoProcess()
{

}

videoProcess::videoProcess(string rtspPath)
{
    this->rtspPath = rtspPath;
}

videoProcess::~videoProcess()
{

}

int videoProcess::videoInThreadCreat()
{
    int temp;

    if((temp = pthread_create(&videoInThreadPt, NULL, videoInThread , this)) != 0)
    {
        printf("ffmpegRtspThread failure !\n");
    }
    else
    {
//        threadState = 1;
        printf("ffmpegRtspThread success !\n");
    }

    pthread_detach(videoInThreadPt);
}

int videoProcess::videoInThreadCreat(string rtspPath)
{
    this->cap = new VideoCapture(rtspPath.c_str());

    if (!cap->isOpened())
    {
         cerr << "ERROR! Unable to open camera\n";
         return -1;
    }

    *cap >> videoIn;
    // check if we succeeded
    if (videoIn.empty())
    {
      cerr << "ERROR! blank frame grabbed\n";
      return -1;
    }

    int temp;

    if((temp = pthread_create(&videoInThreadPt, NULL, videoInThread , this)) != 0)
    {
        printf("ffmpegRtspThread failure !\n");
    }
    else
    {
//        threadState = 1;
        printf("ffmpegRtspThread success !\n");
    }

    pthread_detach(videoInThreadPt);

    return 0;
}

void *videoProcess::videoInThread(void *param)
{
    printf("[ == I am videoInThread thread! == ]\n\n");

    videoProcess *pThis = (videoProcess*)param;

    for (;;)
    {
        *pThis->cap >> pThis->videoIn;

        // show live and wait for a key with timeout long enough to show images
        imshow("Live", pThis->videoIn);

        if (waitKey(5) >= 0)
            break;
    }
}
