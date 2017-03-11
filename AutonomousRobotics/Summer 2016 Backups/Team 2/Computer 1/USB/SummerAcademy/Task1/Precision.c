int main(void)
{//Task:Move forward 1 yd, stop 5 secs, turn left 90 degrees in place, then back up 2 feet and stop
	
	//move forward 1 yard
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,3320); //3320 ticks ~ 36 in
	mtp(3,500,3320);
	bmd(0);
	bmd(3);

		//stop 5 seconds
	msleep(5000);//m stands for milliseconds

	//Turn left 90 degrees
	// Circumpherence w/ distance from wheels(r)=5.25 in, C=32.98 in., 1/4=8.25 in.
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,0,0);
	mtp(3,500,760);//761 ticks ~ 8.25 in
	bmd(0);
	bmd(3);
	
	//move backward
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,-2400);//2400 ticks ~ 24 in
	msleep(100);
	mtp(3,500,-2400);
	bmd(0);
	bmd(3);
	return(0);

}

	
