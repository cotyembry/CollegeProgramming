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
enable_servos();
set_servo_position(0,1350);
	msleep(1000);
set_servo_position(1,1625);
	msleep(1000);
clear_motor_position_counter(0);
clear_motor_position_counter(1);
	mtp(0,900,-1500);
    mtp(1,900,-1500);
	bmd(0);
	bmd(1);
	msleep(3000);
	//oPENING AND CLOSING THE CLAW
set_servo_position(0,1350);
set_servo_position(1,0);
enable_servos();
msleep(3000);
	//turn clockwise 180 degrees
clear_motor_position_counter(1);
clear_motor_position_counter(0);
	mtp(0,500,500);
   mtp(1,500,-500);
   bmd(0);
bmd(1);
msleep(3000);
set_servo_position(0,650);
set_servo_position(1 ,2000);
enable_servos();
	//stop after turning
	return 0;
}
