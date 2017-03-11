
int main(void){
	while(1==1){
		//printf("analog value=%d\n", analog10(0));
		//between 600 and ~800 my sensor sees white
		//greater than 900 my sensor sees black
		if(analog10(1)>600){
			printf("Black color found\n");
			enable_servo(2);
			set_servo_position(2, 900);
			sleep(2);
			set_servo_position(2, 0);
			disable_servo(2);
			msleep(1000);
			
		}
		else if(analog10(1)<600 && analog10(1)<999){
			printf("White color found\n");
			enable_servo(0);
			set_servo_position(0, 1700);
			sleep(2);
			set_servo_position(0, 0);
			msleep(1000);
		}
		else{
			printf("default else\n");
			msleep(1000);
	}
}
}
