int main () {
	int inches=12, ticks;
	float d=3.5;
	ticks= (inches/(3.14*d)*1100);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,3 * ticks);
	mtp(3,1000,3 * ticks);
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	msleep(5000);
	mtp(0,1000,400);
	mtp(3,1000,-400);
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,-2 * ticks);
	mtp(3,1000,-2 * ticks);
	bmd(0);
	bmd(3);
}
