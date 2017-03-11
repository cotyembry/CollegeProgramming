int main() {
	printf("Twerk-Mode: Initiated.");	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,1000,1000);	
	 mtp(3,500,-1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,500,-1000);	
	 mtp(3,1000,1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,1000,1000);
	 mtp(3,1000,1000);
	 msleep(1000);
	
	int i = 0;
	while(i < 15){
		
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0,10000,1000);
		 mtp(3,10000,-1000);
		
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0,10000,-1000);
		 mtp(3,10000,1000);
		
		 i=i+1;
		//i++;
		
		
	}
	printf("About to move servos\n");
	 enable_servos();
	 set_servo_position(2,500);
	 msleep(1000);
	 set_servo_position(2,0);
	 enable_servo(0);
	 set_servo_position(0,500);
	 msleep(1000);
	 set_servo_position(0,0);
	
		printf("Twerk-Mode: Concluded.");
		printf("FOR NOW...");
		printf("XD");
}
