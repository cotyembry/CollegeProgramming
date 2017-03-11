/*#include <stdio.h>
int main(){
	enable_servos();
	set_servo_position(3,1400); 
	msleep(1000);
	set_servo_position(0,1200);
	msleep(1000);
	set_servo_position(3,400);
	msleep(1000);
	set_servo_position(0,300);
	msleep(1000);
	mtp(0,1000,2000);
	mtp(3,300,2000);
	bmd(0);
	bmd(3);
	mtp(0,1000,0);
	mtp(3,1000,0);
	bmd(3);
	return 0;
}



//driving a robot forward 
int main(){
	//circumference = pi * d , 1100 ticks/revolution
	int inches=12, ticks;
	//inches: distance to travel, d= diameter of wheel
	float d=1.2;
	ticks=(inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks 
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,-300,ticks);
	bmd(0);
	bmd(3);
	mtp(0,1000,0);
	mtp(3,1000,0);
	bmd(3);
	return 0;}
*/


