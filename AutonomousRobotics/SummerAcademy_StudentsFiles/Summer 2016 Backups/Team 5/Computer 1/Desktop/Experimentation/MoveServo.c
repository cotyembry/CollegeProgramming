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
	

}
