#include "Arduino.h"
#include "Communicator.h"

Communicator::Communicator(long baud){
  Serial.begin(baud);
  Serial.write("ready\n");
}

Communicator::~Communicator(){
  Serial.end();
}


/*
  Protocoll:
  Command | Argument1 | Argument2
  -1 or nothing -> nothing to do
  0 | Arm | steps -> move arm
 */

int Communicator::recieve(MyStepper* steppers, size_t stepper_count){
  Serial.println("read something");
  return 0;

  switch(Serial.read()){
  case -1:
    return -1;

  case 0:
    int stepper = Serial.read();
    if(stepper == -1)
      return -1;

    char steps[2];
    if(Serial.readBytes(steps, 2) != 2)
      return -1;
    int steps_int = (int)steps[0] | ((int)steps[1] << 8);
    Serial.println(steps_int);


    break;
  }
  return 0;
}
