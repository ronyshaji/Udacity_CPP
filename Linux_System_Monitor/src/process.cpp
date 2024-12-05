#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;


int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization() const{ 

    long activeJiff = LinuxParser::ActiveJiffies(pid_);
    long upTimeProcess = LinuxParser::UpTime(pid_);
    float systemUpTime = LinuxParser::UpTime();

    // CPU Utilisation of a process = (stime + utime) / (system up time  - process start time)
    float elapsedTime = systemUpTime - static_cast<float>(upTimeProcess);

    return static_cast<float>(activeJiff) / elapsedTime;
}

// Return the command that generated this process
string Process::Command() 
{ 
    command_ = LinuxParser::Command(pid_);
    return command_;   
}

// Return this process's memory utilization
string Process::Ram() 
{ 
    ram_ = LinuxParser::Ram(pid_);
    return ram_;
}

// Return the user (name) that generated this process
string Process::User() 
{ 
    uid_ = std::stol(LinuxParser::Uid(pid_));
    user_ = LinuxParser::User(uid_);
    return user_; 
}

// Return the age of this process (in seconds)
long int Process::UpTime() 
{ 
    uptime_ = LinuxParser::UpTime(pid_);
    return uptime_; 
}

// Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const
{   
    return this->CpuUtilization() > a.CpuUtilization();
}
