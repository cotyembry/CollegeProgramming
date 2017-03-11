int main()
{
	int inches=24, ticks;
	float d=2.75;
	ticks= (inches/(3.14159*d)*885);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,ticks);
	msleep(100);
	mtp(3,500,ticks);
	bmd(0);
	bmd(3);
	set_servo_position(0,1000);
	set_servo_position(2,1600);
	msleep(2000);
	enable_servos();
	disable_servos();
	set_servo_position(0,1700);
	set_servo_position(3,300);
	msleep(2000);
	enable_servos();
	disable_servos();
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,3400);
	msleep(100);
	mtp(0,500,3400);
	bmd(0);
	bmd(3);
}
