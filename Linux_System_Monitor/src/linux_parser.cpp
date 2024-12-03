#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <filesystem>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value; 
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
/*
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}*/

//Function to count the number of PIDs using std::filesystem
vector<int> LinuxParser::Pids()
{
  string path = kProcDirectory;
  vector<int> pid;
  if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
  {
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
      auto filename = entry.path().filename().string();
      if (std::all_of(filename.begin(), filename.end(), [](char c) { return std::isdigit(c); }))
      {
        try
        {
          pid.push_back(std::stoi(filename));
        }
        catch(const std::invalid_argument& e)
        {
          std::cerr << "Invalid Filename" << '\n';
        } 
      }
    }
    return pid;
  }
  return {};
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() 
{ 
  string line;
  string key;
  float value{0};
  float totalValue{0};
  float freeValue{0};
  std::ifstream filestream(kProcDirectory + kMeminfoFilename);
  if (filestream.is_open())
  {
    while(std::getline(filestream, line))
    {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream str_stream(line);
      while(str_stream >> key >> value)
      {
        if (key == "MemTotal") { totalValue = value; }
        else if (key == "MemFree") { freeValue = value; }
      }
    }
    if ((totalValue > 0) && (freeValue >= 0)) {  return ((totalValue - freeValue)/totalValue); } 
  }
  return 0;
}

// TODO: Read and return the system uptime
float LinuxParser::UpTime() 
{ 
  float upTime{0};
  string line;
  std::ifstream fileStream(kProcDirectory + kUptimeFilename);
  if (fileStream.is_open())
  {
    std::getline(fileStream, line);
    std::istringstream stream(line);
    stream >> upTime;
    return upTime; 
  }
  return 0.0;
}


// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid)
 { 
  
  string line;
  string readField;
  int field{0};
  long uTime{0};
  long sTime{0};
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream strStream(line);
    while(strStream >> readField)
    {
      field++;
      if (field == 14) { uTime = std::stol(readField); }
      else if (field == 15) {sTime = std::stol(readField); }
    }
    return (sTime + uTime) / sysconf(_SC_CLK_TCK);
  }
  return 0; 
 }



// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() 
{ 
  string line, cpu, value;
  vector<string> jiffies;

  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream strStream(line);
      strStream>> value;
      if (value == "cpu")
      {
        while (strStream >> cpu)
        {
          jiffies.push_back(cpu);
        }
        break;
      }
    }
    return jiffies;
  }
  return {}; 
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 

  vector<string> activeJiffy = CpuUtilization();

  return std::stol(activeJiffy[CPUStates::kUser_]) + std::stol(activeJiffy[CPUStates::kNice_]) +
         std::stol(activeJiffy[CPUStates::kSystem_]) + std::stol(activeJiffy[CPUStates::kIRQ_]) +
         std::stol(activeJiffy[CPUStates::kSoftIRQ_]) + std::stol(activeJiffy[CPUStates::kSteal_]);

}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 

  vector<string> idleJiffy = CpuUtilization();
  return std::stol(idleJiffy[CPUStates::kIdle_]) + std::stol(idleJiffy[CPUStates::kIOwait_]);
}


// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() 
{ 
  return LinuxParser::ActiveJiffies() + LinuxParser::IdleJiffies();
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() {

string line;
string processes;
int totalProcessNUm{0};
std::ifstream stream(kProcDirectory + kStatFilename);

if (stream.is_open())
{
  while(std::getline(stream, line))
  {
    std::istringstream strStream(line);
    strStream >> processes >> totalProcessNUm;
    if (processes == "processes") { return totalProcessNUm; }
  }
}
  return 0; 
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {

  string line;
  string process;
  int runningProcess;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream strStream(line);
      strStream >> process >> runningProcess;
      if (process == "procs_running") { return runningProcess; }
    }
  } 
  return 0; 
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 

  string line;
  string cmdLine;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream strStream(line);
    strStream >> cmdLine;
    return cmdLine;
  }
  return string(); 
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) 
{ 
  string line;
  string ramMem;
  long ramMemUse;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream strStream(line);
      while(strStream >> ramMem >> ramMemUse)
      {
        if (ramMem == "VmSize") { return to_string(ramMemUse/1024); }
      }
    }
  }
  return string(); 
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) 
{ 
  string line;
  string uId;
  int uIdNum;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatusFilename);
  if (stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream strStream(line);
      while(strStream >> uId >> uIdNum)
      {
        if (uId == "Uid") { return to_string(uIdNum); }
      }
    }
  }
  return string(); 
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 

  string line;
  string userId;
  string passwd;
  int uId;
  std::ifstream stream(kPasswordPath);
  if (stream.is_open())
  {
    while(std::getline(stream, line))
    {
      std::istringstream strStream(line);
      std::replace(line.begin(), line.end(), ':', ' ');
      while(strStream >> userId >> passwd >> uId)
      {
        if (uId == pid) { return userId; }
      }
    }
  }
  return string(); 
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long int LinuxParser::UpTime(int pid) 
{ 
  string line;
  int field{0};
  long upTime;
  std::ifstream stream(kProcDirectory + to_string(pid) + kStatFilename);
  if (stream.is_open())
  {
    std::getline(stream, line);
    std::istringstream strStream(line);
    while(strStream >> upTime)
    {
      field++;
      if(field == 22)
      {
        auto upTimeSec = upTime / sysconf(_SC_CLK_TCK);
        return upTimeSec;
      }
    }
  }
  return 0; 
}

