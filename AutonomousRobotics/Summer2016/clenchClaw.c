

int main() {
	enable_servos();

	//servos go from 0 to 2047
	set_servo_position(0, 1000); //set the position of the claw that will clench to straight out
	set_servo_position(1, 2047); //open claw all the way up

}