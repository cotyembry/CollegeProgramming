#include<stdio.h>
int main(void) {
    //calculates amount of ticks in degree for arm servo and claw servo
	float arm =(2047/270);
	float claw =(2047/270);
	//clears motor position or something similar to that
	clear_motor_position_counter(0);
    clear_motor_position_counter(3):
	//Moves the robot spin, then go right?
	mtp(0,1000,10000);
	mtp(3,-1000,10000);
	msleep(3000);
	mtp(0,1000,11000);
	mtp(3,1100,11000);
	bmd(0);
	bmd(3);
    enable_servo(0);
	enable_servo(2);
	set_servo_position(0,(arm*90));
    set_servo_position(2,(claw*90));
    analog10(6)	
}
