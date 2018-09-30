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

int Communicator::recieve(const MyStepper* steppers[], size_t stepper_count){
  long command = -1;
  if(Serial.available())
    command = Serial.parseInt();
  if (command == -1)
    return -1;
  else if (command == 0){
    debug("Command Moving Arm");
    long stepper = Serial.parseInt();
    long steps = Serial.parseInt();
    debug("Moving Stepper");
    Serial.println(stepper);
    steppers[stepper]->step(steps);
    Serial.println(steppers[stepper]->left());
  }
  else{
    Serial.println("general kenobi");
  }

  return 0;
}

void Communicator::debug(const char * const message){
  Serial.print("[DEBUG]: ");
  Serial.println(message);
}

void Communicator::warn(const char* const message){
  Serial.print("[WARN]: ");
  Serial.println(message);
}


