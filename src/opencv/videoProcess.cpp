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

int videoProcess::videoPlayThreadCreat()
{
    int temp;

    if((temp = pthread_create(&videoPlayThreadPt, NULL, videoPlayThread , this)) != 0)
    {
        printf("videoPlayThreadCreat failure !\n");
    }
    else
    {
//        threadState = 1;
        printf("videoPlayThreadCreat success !\n");
    }

    pthread_detach(videoPlayThreadPt);
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
        try
        {
            *pThis->cap >> pThis->videoIn;

             pThis->videoQueue.push(pThis->videoIn);
        }
        catch (...)
        {

        }
       
    }
}

void *videoProcess::videoPlayThread(void *param)
{
    printf("[ == I am videoPlayThread thread! == ]\n\n");

    videoProcess *pThis = (videoProcess*)param;

    for (;;)
    {
        try
        {
            if(!pThis->videoQueue.empty())
            {
                imshow("Live", pThis->videoQueue.front());
                pThis->videoQueue.pop();

                static long tmp = 0;

                cout << "==:" << tmp++ << endl ;

                if (waitKey(15) >= 0)
                break;
            }
        }
        catch (...)
        {

        }
       
    }
}
