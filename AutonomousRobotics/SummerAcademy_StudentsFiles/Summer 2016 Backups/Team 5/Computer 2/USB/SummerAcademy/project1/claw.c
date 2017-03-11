/*
int main (){
set_servo_position(3, 1970); // set a position for the servo port and port 3 controls the opening and closing of the claw
set_servo_position(2,1350); // port 2 controls up and down on arm
enable_servos(); // power the port to move the servo
	msleep(1000);
set_servo_position(3, 34); // set a position for the servo port and port 3 controls the opening and closing of the claw
     msleep(1000);
set_servo_position(2,479);	
    msleep(1000);
disable_servos(2,3); // servo no longer needed
	msleep(1000);
	clear_motor_position_counter(2);
	clear_motor_position_counter(3);
	mtp(2,840,1300);
	mtp(3,1970,800);
	return 0;

}
*/

