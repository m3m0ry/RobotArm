/*
 * Slave which communicates over serial 
 */

#pragma once

#include "MyStepper.h"

class Communicator{
 public:
  Communicator(long baud=9600);
  ~Communicator();
  int recieve(MyStepper* steppers, size_t stepper_count);



};

