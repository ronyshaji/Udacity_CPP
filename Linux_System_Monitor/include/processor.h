#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  

 private:
    long prevActive_{0};
    long preTotal_{0};
};

#endif