#include <iostream>
#include <unistd.h>
#include <memory.h>
#include "easylogging++.h"
#include "videoProcess.h"

INITIALIZE_EASYLOGGINGPP

int main(int argc,char **argv)
{
    // Load configuration from file
    el::Configurations conf("log.conf");
    // Reconfigure single logger
    el::Loggers::reconfigureLogger("default", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);
    // Now all the loggers will use configuration from file

    string rtspPath = "rtmp://58.200.131.2:1935/livetv/hunantv";
    videoProcess video;

    video.videoInThreadCreat(rtspPath);

    video.videoPlayThreadCreat();

    for(;;)
    {
        sleep(1);
        LOG(INFO) << "hello world !";
    }

	return 0;
}






