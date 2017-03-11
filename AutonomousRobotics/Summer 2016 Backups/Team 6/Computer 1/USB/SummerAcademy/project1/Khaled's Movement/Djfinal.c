int main (){	
	set_servo_position(0, 1300);
	set_servo_position(3,1000);	//set a position for the servo port 
	enable_servos(); //power the port and move the servo
		msleep(1000);
	set_servo_position(3, 573);
		msleep(1000);
		set_servo_position(0,465);
		msleep(1000);
//driving a robot forward 
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,-1000);
	mtp(3,500,-1000);
	bmd(0);
	bmd(3);
	set_servo_position(3,950);
		msleep(1000);
		mtp(0,100,1000);	 
	}

