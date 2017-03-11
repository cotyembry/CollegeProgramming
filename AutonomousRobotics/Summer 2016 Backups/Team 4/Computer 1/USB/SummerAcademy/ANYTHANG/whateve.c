int main()
{
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,800,1000);	
	 mtp(3,-800,1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,-800,1000);	
	 mtp(3,800,1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0, 1500,1000);
	 mtp(3, 1500,1000);
	 msleep(1000);
	
	int i=0;
	while(i<10){
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0, 500,1000);
		 mtp(3, 500,1000);
		 msleep(500);
		
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0, -500,1000);
		 mtp(3, -500,1000);
		 msleep(500);
		 i=i+1;
		//i++;
		 enable_servo(2);
		 set_servo_position(2, 500);
		 msleep(1000);
		 set_servo_position(2, 0);
		 enable_servo(0);
		 set_servo_position(0, 500);
		 msleep(1000);
		 set_servo_position(0, 0);
	}
}

