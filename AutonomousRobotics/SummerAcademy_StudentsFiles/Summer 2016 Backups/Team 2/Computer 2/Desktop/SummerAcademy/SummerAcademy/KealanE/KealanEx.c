int main()
{
	int inches=45, ticks;
	float d=2.75;
	ticks=(inches/(3.14159*d)*1100);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,750,ticks);
	bmd(0);
	bmd(3);
	mtp(0,750,ticks);
	mtp(3,1000,ticks);
	bmd(0);
	bmd(3);
	enable_servos();
	set_servo_position(0,1500);
	set_servo_position(2,2047);
	msleep(2000);
	disable_servos();
	enable_servos();
	set_servo_position(0,-1500);
	set_servo_position(2,-2047);
	msleep(2000);
	disable_servos();
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(0,-1000,ticks);
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,1000);
	mav(3,-1000);

	return 0;
	}

