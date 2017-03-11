int main()
{
	set_servo_position(0,2000);
	set_servo_position(2,2000);
	enable_servos(); //turns on all servos
	msleep(2000);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,650);
	mtp(3,-1000,650);
	bmd(0);
	bmd(3);
	mtp(0,-1000,0);
	mtp(0,1000,0);
	bmd(0);
	bmd(3);
	disable_servos();
	return(0);
}
