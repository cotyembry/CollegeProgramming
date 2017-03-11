int main()
{//driving a robot forward 
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,1000);
	mtp(3,500,1000);
	bmd(0);
	bmd(3);
	return 0;

}
}
/*int main (){
set_servo_position(0, 1300);
set_servo_position(3,1000);	//set a position for the servo port 
enable_servos(); //power the port and move the servo
		msleep(1000);
	set_servo_position(3, 573);
		msleep(1000);
	set_servo_position(0,400);
		msleep(1000);
	set_servo_position(3,950);
		msleep(1000);
		mtp(0,100,1000);	

disable_servos(1); // servo no longer needed
}
*/

/*int main (){
	set_each_analog_state(1,0,0,0,0,0,0,0,);
	//set port 0 to floating 
	sleep(0.02);		  //wait for state to change
	while(1)(						//loop forever
		if(analog10)(0)>512){		//if too close
			  bk(0);				//back up 
			  bk(3);
		}
		if (analog10(0)<=512){			//if too far away 
			  fd(0);						//get closer
			  fd(3);
		}
	}
}	*/
