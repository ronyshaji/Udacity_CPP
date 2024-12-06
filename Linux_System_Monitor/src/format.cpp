#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"


using std::string;

string Format::ElapsedTime(long seconds) 
{ 
   if (seconds > 0)
   {
       int hour = seconds / 3600;
       int minute = (seconds % 3600) / 60;
       int second = seconds % 60 ;

       std::stringstream formatted_time;
       formatted_time << std::setw(2) << std::setfill('0') << hour << ":"
                      << std::setw(2) << std::setfill('0') << minute << ":"
                      << std::setw(2) << std::setfill('0') << second;

       return formatted_time.str();
   }
   else 
   {
       return "00:00:00";
   }
}
