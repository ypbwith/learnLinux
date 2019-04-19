#include <iostream>
#include <unistd.h>
#include <memory.h>
#include "easylogging++.h"

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

    for(;;)
    {
        sleep(1);
        LOG(INFO) << "hello world !";
    }

	return 0;
}






