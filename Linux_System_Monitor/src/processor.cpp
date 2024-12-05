#include "processor.h"
#include "linux_parser.h"

#include <iostream>

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    
    long curActive = LinuxParser::ActiveJiffies();
    long curTotal = LinuxParser::Jiffies();

    long activeDelta = curActive - prevActive_;
    long activeTotal = curTotal - preTotal_;

    prevActive_ = curActive;
    preTotal_ = curTotal;

    if (activeTotal == 0) {
        auto utilisation = 0;
        return utilisation;
    }
    else {auto utilisation = static_cast<float>(activeDelta) / static_cast<float>(activeTotal); 
    
    return utilisation; }
    
    //return utilisation; 
}