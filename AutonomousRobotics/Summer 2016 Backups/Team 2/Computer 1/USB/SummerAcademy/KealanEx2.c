int main()
{
	int inches=12, ticks;
	float d=2.75;
	ticks= (inches/(3.14159*d)*850);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,ticks);
	msleep(100);
	mtp(3,500,ticks);
	bmd(0);
	bmd(3);
	set_servo_position(0,1000);
	set_servo_position(2,1600);
	msleep(1000);
	set_servo_position(0,1700);
	set_servo_position(3,300);
	enable_servos();
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,1000);
	msleep(100);
	mtp(0,500,1000);
	bmd(0);
	bmd(3);
	disable_servos();
}
