 /*//driving a robot forward 
int main (){
//circumference = pi*d ,1100 ticks/revolution
		int inches =12,ticks;
//inches: distance to travel, d= diameter of wheel
	float d=1.2;
	ticks= (inches/(3.14159*d)*1100);
//computes the distance from inches to ticks 
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,300,ticks);
		mtp(3,1000,ticks);
		bmd(0);
		bmd(3);
		mtp(0,300,0);
		mtp(3,1000,0);
		bmd(0);
		bmd(3);
		mtp(0,1000,ticks);
		mtp(3,1000,ticks);
		bmd(0);
		bmd(3);
		mtp(0,1000,0);
		mtp(3,1000,0);
		
	}
	*/

/*int main (){
set_servo_position(0, 1300);
set_servo_position(0,400);	//set a position for the servo port 
enable_servos(); //power the port and move the servo
		msleep(1000);
	set_servo_position(3, 400);
		msleep(1000);
	set_servo_position(0,1300);
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
				mtp(0,100,1000);
				mtp(3,100,1000);	
disable_servos(1); // servo no longer needed
}

// Port 0 is the arm motor 
// Port 3 is side Motor

	/*

int main() {
	
	while(1==1){
	//printf("analog value=%d\n",analog10(0));
		//between 600 and~800 my sensor sees white
		// greater than 900 my sees black
		if (analog10(0) >900) {
				printf("black color found/n");
	}
	else if(analog10(0)>600 && analog10(0)<800) { 
			printf("while found\n");
	}
	else {
		printf("default else\n");
		}
	}	
}

*/
