#ifndef UTILITIES_H
#define UTILITIES_H
#define __STDC_WANT_LIB_EXT1__ 1

#include <iostream>
#include <cstring>
#include <time.h>

namespace Util
{
    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string CurrentDateTime(char* buffer)
    {
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );

        strftime (buffer,strlen(buffer),"Now it's %I:%M%p.", now);
    }
}
#endif