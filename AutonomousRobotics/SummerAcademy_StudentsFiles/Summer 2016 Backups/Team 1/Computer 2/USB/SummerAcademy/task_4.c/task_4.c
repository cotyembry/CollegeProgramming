int closeClaw(){
		printf("picking up object\n");
	
	set_servo_position(2,0);
	msleep(2000);
	return 0;
}
	

int main(){
	
	printf("approaching object\n");
	
	enable_servos();
	
	set_servo_position(2,2000);
	
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,3000);
	mtp(3,500,3000);
	bmd(0);
	bmd(3);	
	
	msleep(500);
	
	closeClaw();
	
	
printf("turn 180 degrees\n");

	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(3,1000,2000);
	mtp(0,0,2000);
	bmd(0);
	bmd(3);

	
	
}

	
