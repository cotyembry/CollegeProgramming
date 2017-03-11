int main () {
	int inches=36, ticks;
	float d=3;
	ticks= (inches/(3.14*d)*1100);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,-ticks);
	mtp(3,1000,-ticks);
	bmd(0);
	bmd(3);
	enable_servos();
	set_servo_position(2,1000);
	msleep(1000);
	set_servo_position(0,1300);
	msleep(1000);
	set_servo_position(2,50);
	msleep(1000);
	set_servo_position(0,300);
	msleep(1000);
	mtp(0,1000,0);
	mtp(3,1000,0);
	bmd(0);
	bmd(3);
	disable_servos();
	return 0;
}
