int moveBackwards() {
	printf("in moveBackwards()\n");
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,-2400);
	mtp(3,1000,-2400);
	bmd(0);
	bmd(3);	

	return 0;
}

int main(){
	//pi* diameter = c 1100 ticks/reveloution
	
	int inches= 36,ticks;
	//inches: distance to travel d= diameter of wheel
	float d=2.7;
	ticks = (inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks
		printf("ticks=%d/n",ticks);
		printf("move forward one yard\n");
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	
	bmd(0);
	bmd(3);
	
	
	msleep(5000);
		printf("turn 90 degrees\n");

	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1100,550);
	
	//bmd(0);
	//bmd(3);
	
	msleep (1000);
	 
	 printf ("go back\n");
	 
	moveBackwards();

}
