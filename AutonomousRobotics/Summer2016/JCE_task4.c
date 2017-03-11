//approach object, grab it. turn 180 degrees and stop

int turn180(speed) {
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);

	// mtp(0, speed, -305); //this worked at the college
	// mtp(3, speed, 305);  //this worked at the college

	mtp(0, speed, -654);
	mtp(3, speed, 654);

	bmd(0);
	bmd(3);

	printf("left motor: -654, right motor: 654\n");

	return 0;
}

int main() {
	//first setup the claw to be in a good position to pick the object up
	enable_servos();

	set_servos_position(0, 1000); //position the claw to be perfectly flat/horozontal/level
	set_servos_position(1, 2047); //open the claw all the way 

	//1. approach object
	mrp(0, 450, 500);
	mrp(3, 450, 500);

	//2. grab it
	set_servos_position(1, 0);

	//3. turn 180 degrees and stop
	turn180(500);
}