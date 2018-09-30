#include "Arduino.h"
#include "MyStepper.h"


const int MyStepper::full_step[4] = {B1100, B0110, B0011, B1001};
const int MyStepper::wave_drive[4] = {B1000, B0100, B0010, B0001};
const int MyStepper::half_step[8] = {B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001};

MyStepper::MyStepper(int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4, int steps_per_round)
{
	this->steps_per_round = steps_per_round; // total number of steps for this motor

	// Arduino pins for the motor control connection:
	motor_pin[0] = motor_pin_1;
	motor_pin[1] = motor_pin_2;
	motor_pin[2] = motor_pin_3;
	motor_pin[3] = motor_pin_4;

	// setup the pins on the microcontroller:
	for (int i = 0; i < 4; ++i){
		pinMode(motor_pin[i], OUTPUT);
	}
}

// Sets the speed in revs per minute
void MyStepper::setSpeed(long whatSpeed)
{
  step_delay = 60L * 1000L * 1000L / steps_per_round / whatSpeed;
}

void MyStepper::step(int steps_to_move)
{
	steps_left += steps_to_move;
}

void MyStepper::move(unsigned int steps, const int * lookup){
  // decrement the number of steps, moving one step each time:
  //Serial.println(abs(steps_left));
  for(; steps > 0 && abs(steps_left) > 0; --steps)
    {
      unsigned long now = micros();
      // move only if the appropriate delay has passed:
      if (now - last_step_time >= step_delay)
        {
          last_step_time = now;
          // increment or decrement the step number, depending on direction:
          steps_left > 0 ? position++ : position--;
          position = position % steps_per_round;
          position = position < 0 ? steps_per_round : position;
          // decrement the steps left:
          steps_left >= 0 ? --steps_left : ++steps_left;
          // step the motor to step number 0, 1, ..., {3 or 10}
          stepMotor(position, lookup);
        }
    }
}

int MyStepper::left() const{
  return steps_left;
}

/*
 * Moves the motor forward or backwards.
 */
void MyStepper::stepMotor(unsigned int thisStep, const int* lookup){
  size_t n = sizeof(lookup)/sizeof(lookup[0]);
  for(size_t i = 0; i < 4; ++i)
    digitalWrite(motor_pin[i], bitRead(lookup[thisStep%4],i));
}

