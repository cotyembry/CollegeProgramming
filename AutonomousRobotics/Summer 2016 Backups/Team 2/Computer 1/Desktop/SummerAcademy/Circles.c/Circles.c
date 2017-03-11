int main()
{
	//Claw on
	enable_servos();
	
	//Open claw
	set_servo_position(2,500);
	msleep(500);
	
	//Close claw
	set_servo_position(2,0);
	msleep(500);
	
	//Raise up slightly
	set_servo_position(0,1929);
	msleep(500);
	
	//Move forward specified inches
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,-5400);
	mtp(3,500,-5400);
	msleep(500);
	
	//Open claw
	set_servo_position(2,0);
	msleep(500);
	
	return(0);
}
