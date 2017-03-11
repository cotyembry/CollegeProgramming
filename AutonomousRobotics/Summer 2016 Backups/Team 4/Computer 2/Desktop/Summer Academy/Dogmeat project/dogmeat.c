int main() {
	int inches=12, ticks;
	float d=3;
	ticks= (inches/(3.14*d)*1100);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	bmd(0);
	bmd(3);
	mtp(0,1000,0);
	mtp(3,1000,0);
	bmd(0);
	bmd(3);
	return 0;
}

