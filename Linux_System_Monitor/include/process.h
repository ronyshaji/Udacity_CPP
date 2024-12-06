#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               
  std::string User();                      
  std::string Command();                  
  float CpuUtilization() const;                
  std::string Ram();                      
  long int UpTime();                       
  bool operator<(Process const& a) const;  
  
  //Constructor 
  Process(int pid) : pid_(pid) {}

 private:
    int pid_;
    std::string command_;
    std::string ram_;
    int uid_;
    std::string user_;
    long uptime_;
    
};

#endif