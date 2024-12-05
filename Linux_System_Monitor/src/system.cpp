#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Return the system's CPU
Processor& System::Cpu() { 
    return cpu_;
}

// Return a container composed of the system's processes
vector<Process>& System::Processes() { 

    processes_.clear();
    std::vector<int> pids = LinuxParser::Pids();

    for (auto& pid : pids)
    {
        Process current = Process(pid);
        processes_.push_back(current);
    }
    std::sort(processes_.begin(), processes_.end(), [](Process const& p, Process const& q) { return p < q;});
    return processes_; }

// Return the system's kernel identifier (string)
std::string System::Kernel() 
{ 
    kernel_ = LinuxParser::Kernel();
    return kernel_; 
}

// Return the system's memory utilization
float System::MemoryUtilization() 
{ 
    memUtlisation_ = LinuxParser::MemoryUtilization();
    return memUtlisation_; 
}

// Return the operating system name
std::string System::OperatingSystem() 
{ 
    os_ = LinuxParser::OperatingSystem();
    return os_; 
}

// Return the number of processes actively running on the system
int System::RunningProcesses() 
{ 
    runProcess_ = LinuxParser::RunningProcesses();
    return runProcess_; }

// Return the total number of processes on the system
int System::TotalProcesses() { 

    totalProcess_ = LinuxParser::TotalProcesses();
    return totalProcess_; }

// Return the number of seconds since the system started running
long System::UpTime() { 
    
    upTime_ = static_cast<long>(LinuxParser::UpTime());
    return upTime_; }