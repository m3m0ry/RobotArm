/*
 * Slave which communicates over serial 
 */

#pragma once

#include "MyStepper.h"


class Communicator{
 public:
  Communicator(long baud=9600);
  ~Communicator();
  int recieve(const MyStepper* steppers[], size_t stepper_count);


 private:
   void debug(const char* const message);
   void warn(const char* const message);

};

