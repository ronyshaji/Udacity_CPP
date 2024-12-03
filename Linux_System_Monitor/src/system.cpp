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

// TODO: Return the system's CPU
Processor& System::Cpu() { 
    return cpu_;
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    
    processes_.clear();
    std::vector<int> pids = LinuxParser::Pids();

    for (int i = 0; i < pids.size(); i++)
    //for (const auto& pid : pids)
    {
        Process p;

        //std::cout << "Setting PID: " << pids[i] << std::endl;

        p.setPid(pids[i]);
        p.CpuUtilization();
        p.Command();
        p.Ram();
        p.User();
        p.UpTime();
        //p.operator<(p);
        processes_.push_back(p);
    }
    
    return processes_; }


// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() 
{ 
    kernel_ = LinuxParser::Kernel();
    return kernel_; 
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() 
{ 
    memUtlisation_ = LinuxParser::MemoryUtilization();
    return memUtlisation_; 
}

// TODO: Return the operating system name
std::string System::OperatingSystem() 
{ 
    os_ = LinuxParser::OperatingSystem();
    return os_; 
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() 
{ 
    runProcess_ = LinuxParser::RunningProcesses();
    return runProcess_; }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { 

    totalProcess_ = LinuxParser::TotalProcesses();
    return totalProcess_; }

// TODO: Return the number of seconds since the system started running
long System::UpTime() { 
    
    upTime_ = static_cast<long>(LinuxParser::UpTime());
    return upTime_; }