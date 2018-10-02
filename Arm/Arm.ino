#include <Arduino.h>
#include "MyStepper.h"
#include "Communicator.h"


#define STEPS  32   // Number of steps for one revolution of Internal shaft
                    // 2038 steps for one revolution of External shaft

MyStepper stepper1(22,24,26,28);
MyStepper stepper2(30,32,34,36);
MyStepper stepper3(38,40,42,44);
MyStepper stepper4(46,48,50,52);
const MyStepper* steppers[4] = {&stepper1, &stepper2, &stepper3, &stepper4};

Communicator* comm;

void setup ()  {
  comm = new Communicator(115200);
    for(int i = 0; i < 4; i++)
    steppers[i]->setSpeed(700);
}

void loop ()  {
//  //TODO why this? the stupid stepper library should do it for me???
//   digitalWrite(8, LOW);
//   digitalWrite(9, LOW);
//   digitalWrite(10, LOW);
//   digitalWrite(11, LOW);
  comm->recieve(steppers, 4);
  for(int i = 0; i < 4; i++)
    steppers[i]->move(500);
}

//int main(){
//  setup();
//  while(true)
//    loop();
//  return 0;
//}
