int main(void) {
	printf("This should work quite nicely, all things considered.");
	
	//circumference = pi*d, 1100 ticks/revolution
	int inches=42, ticks;
	//inches: distance to travel, d= diameter of wheel
	float d=4.2;
	ticks= (inches/(3.14*d)*1100);
	
	//left sensor=1
			   //When the left sensor detects the color black, the robot
			   //makes a right turn until the sensor detects white, then the   	  robot goes forward
	while (1==1) {
		//printf("analog value=%d\n", analog10(0));
		//between 600 and ~800 my sensor sees white
		//greater than 900 my sensor sees black
		if(analog10(1)>600){
			printf("Black color found\n");
			enable_servo(2);
			set_servo_position(2, 200);
			msleep(2000);
			set_servo_position(2, 0);
			disable_servo(2);
			msleep(1000);
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,-342,ticks);
			mtp(3,-340,ticks);
		}
		else if(analog10(1)<600 && analog10(1)<999){
			printf("White color found\n");
			mtp(0, 900, ticks);
			mtp(3, 900, ticks);
		}
		else{
			msleep(1000);
		}
		
	//right sensor=0
				//When the right sensor detects the color black, the robot
			    //makes a left turn until the sensor detects white, then the robot goes forward
	while (1==1) {
		//printf("analog value=%d\n", analog10(0));
		//between 600 and ~800 my sensor sees white
		//greater than 900 my sensor sees black
		if(analog10(0)>600){
			printf("Black color found\n");
			enable_servo(2);
			set_servo_position(2, 200);
			msleep(2000);
			set_servo_position(2, 0);
			disable_servo(2);
			msleep(1000);
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,-342,ticks);
			mtp(3,-340,ticks);
		}
		else if(analog10(0)<600 && analog10(1)<999){
			printf("White color found\n");
			mtp(0, 900, ticks);
			mtp(3, 900, ticks);
		}
		else{
			msleep(1000);
		}
	}
}
} 
