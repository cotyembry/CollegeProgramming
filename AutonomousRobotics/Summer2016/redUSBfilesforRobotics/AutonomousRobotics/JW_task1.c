int main(){
	int inches = 36, ticks;
	float d = 2.5;
	ticks = (inches/(3.14159*d)*1100);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	bmd(0);
	bmd(3);
	
	sleep(5.0);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	int TurnTimes = (7/2.5);
	int TicksPerDegree = ((1100*2.5)/360);
	mrp(0,1000,TicksPerDegree*-90);
	mrp(3,1000,TicksPerDegree*90);
	bmd(0);
	bmd(3);
	
	int BackInches = 24, BackTicks;
	BackTicks = (BackInches/(3.14159*d)*1100);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,-BackTicks);
	mtp(3,1000,-BackTicks);
	bmd(0);
	bmd(3);
	
}
