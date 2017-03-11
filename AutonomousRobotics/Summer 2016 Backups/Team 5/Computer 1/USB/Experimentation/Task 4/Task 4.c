int main() {
	/*
	int main(){
	//port 2 causes the claw to move vertically, port 3 closes and opens the claw;
	
	set_servo_position(2,700); //set a position for the servo port
	enable_servos(); //power  the port and move the servo
	mtp(2,700,1000);
	mtp(3,1000,1500);
	bmd(2);
	bmd(3);
	msleep(1000);
	mtp(2,400,800);
	mtp(3,500,1000);
	bmd(2);
	bmd(3);
	
	disable_servos(); // servo no longer needed
	*/
clear_motor_position_counter(0);
clear_motor_position_counter(1);
enable_servos();
	msleep(2000);
set_servo_position(2,1460);
	;msleep(1000);
set_servo_position(3,1625);
	;msleep(1000);
clear_motor_position_counter(0);
clear_motor_position_counter(1);
	mtp(0,900,-1500);
    mtp(1,900,-1500);
	bmd(0);
	bmd(1);
	;msleep(3000);
	//opening and the closing the claw 
set_servo_position(3,1350);
msleep(500);
set_servo_position(2,950);
msleep(1000);
	//turn clockwise 180 degrees
clear_motor_position_counter(1);
clear_motor_position_counter(0);
	mtp(1,500,500);
   mtp(0,500,-500);
   bmd(0);
bmd(1);
msleep(3000);
set_servo_position(2,950);
set_servo_position(3,1000);
enable_servos();
	//stop after turning
	return 0;
}
