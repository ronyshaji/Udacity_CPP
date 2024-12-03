#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) 
{ 
    if (seconds > 0)
    {
        int hour = seconds / 3600;
        double hourDouble = seconds / static_cast<double>(3600);
        float minute = hourDouble - hour;
        float minutes = minute * 60 ;
        int min_int = static_cast<int>(minutes);
        int second = (minutes - min_int) * 60;
        return std::to_string(hour) + ":" + std::to_string(min_int) + ":" + std::to_string(second);
    }
    else 
    {
        return {"00:00:00"};
    }
}