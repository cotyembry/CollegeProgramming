int main(void)
{
	 printf("Moon-Roll: Activated");	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,800,1000);	
	 mtp(3,800,-1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,800,-1000);	
	 mtp(3,800,1000);
	 msleep(2000);
	
	 clear_motor_position_counter(0);
	 clear_motor_position_counter(3);
	 mtp(0,1000,1000);
	 mtp(3,1000,1000);
	 msleep(1000);

	//int i = 0;
	//while(i < 15){
		
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0,500,1000);
		 mtp(3,500,-1000);
		
		 clear_motor_position_counter(0);
		 clear_motor_position_counter(3);
		 mtp(0,500,-1000);
		 mtp(3,500,1000);
		
		 //i=i+1;
		//i++;
				 
	 //int  c = 0;
	 //while(i<15) 

	 enable_servos();
	 set_servo_position(2,500);
	 
	 msleep(100);
	 set_servo_position(2,0);
	 enable_servo(0);
	 set_servo_position(0,500);
	 msleep(100);
	 set_servo_position(0,0);
	
		//c=c+1;
	   //i++;
	 
	 printf("Moon Roll: Concluded");
}
