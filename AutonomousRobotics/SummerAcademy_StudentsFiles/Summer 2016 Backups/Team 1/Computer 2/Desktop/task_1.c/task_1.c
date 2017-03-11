
int main(){
	//pi* diameter = c 1100 ticks/reveloution
	
	int inches= 36,ticks;
	//inches: distance to travel d= diameter of wheel
	float d=2.7;
	ticks = (inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks
		printf("ticks=%d/n",ticks);
	//move forward one yard
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	
	bmd(0);
	bmd(3);
	
	//stop 5 seconds
	msleep(5000);
	
	//turn left 90 degrees
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1100,400);
	mtp(3,0,400);
	bmd(0);
	bmd(3);
	
	
	//back up two feet
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,-2000);
	mtp(3,1000,-2000);
	bmd(0);
	bmd(3);	

}
