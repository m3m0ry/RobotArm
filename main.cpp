#include <Arduino.h>
#include "MyStepper.h"
#include "Communicator.h"


#define STEPS  32   // Number of steps for one revolution of Internal shaft
                    // 2038 steps for one revolution of External shaft

MyStepper stepper1(1,2,3,4);
MyStepper stepper2(1,2,3,4);
MyStepper stepper3(1,2,3,4);
MyStepper stepper4(1,2,3,4);
const MyStepper steppers[4] = {stepper1, stepper2, stepper3, stepper4};

Communicator* comm;

void setup ()  {
  comm = new Communicator(115200);
}

void loop ()  {
  //Why in the loop???
  //small_stepper.setSpeed(700); // Max seems to be 700

//  //TODO why this? the stupid stepper library should do it for me???
//   digitalWrite(8, LOW);
//   digitalWrite(9, LOW);
//   digitalWrite(10, LOW);
//   digitalWrite(11, LOW);
  comm->recieve(steppers, 4);
}

int main(){
  setup();
  while(true)
    loop();
  return 0;
}
