/*
 * Drives an unipolar four phase stepper motor.
 *
 * Sequence of control signals for 4 control wires are full_step, wave_drive or half_step
 *
 */
#pragma once

class MyStepper {
 public:
  MyStepper(int motor_pin_1, int motor_pin_2,
            int motor_pin_3, int motor_pin_4, int steps_per_round=32);

  void setSpeed(long whatSpeed);

  void step(int steps_to_move);
	void move(unsigned int steps=1, const int* lookup = full_step);
  int left() const;

 private:
  void stepMotor(unsigned int this_step, const int* lookup = full_step);

  unsigned long step_delay = 10;
  int steps_per_round;
  int position = 0;
  int steps_left = 0;
  unsigned long last_step_time = 0;


	int motor_pin[4];
	const static int full_step[4];
	const static int wave_drive[4];
	const static int half_step[8];
};
