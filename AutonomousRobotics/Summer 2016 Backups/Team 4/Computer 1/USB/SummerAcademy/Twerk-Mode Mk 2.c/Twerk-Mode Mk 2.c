int main(void)
{	 printf("Twerk-Mode: Initiated	");	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,1000,5000);	
	 mtp(3,-1000,5000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,-1000,5000);	
	 mtp(3,1000,5000);
	 msleep(2000);
	//Startup Donuts
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0, 1500,1000);
	 mtp(3, 1500,1000);
	 msleep(1000);
	//Forward Motion
		
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	printf("Twerkin' It");
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	msleep(500);
	//Twerk One

	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Two
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Three
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Four
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Five
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Six
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Seven
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Eight
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -500,1000);
	mtp(3, -500,1000);
	//Twerk Nine
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, 500,1000);
	mtp(3, 500,1000);
	msleep(500);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0, -1000,1000);
	mtp(3, -1000,1000);
	//Twerk Ten
{
	enable_servos();
	set_servo_position(2, 500);
	msleep(1000);
	set_servo_position(2, 0);
	enable_servo(0);
	set_servo_position(0, 500);
	msleep(1000);
	set_servo_position(0, 0);
	disable_servos();
}
		printf("Twerk-Mode: Concluded");
		
		printf("FOR NOW...	");
		
		printf("XD");
}
