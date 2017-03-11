// Created on Wed Jun 8 2016

int main() {
	//enable_servos() must be called before set_servo_position() to move a servo
	//default is 1024 - unless instructed to move elsewhere before enable_servos() is called
	//enable_servos(); //powers up the servo
	
	//second param is the position. Postion ranges from 0 to 2047
	//set_servo_position(0, 1024);
	
	//mav(0, 1000);
	//mav(1, 1000);
	//mav(2, 1000);
	//mav(3, 1000);
	
	mtp(3, 300, 1000);
	
	return 0;
}
