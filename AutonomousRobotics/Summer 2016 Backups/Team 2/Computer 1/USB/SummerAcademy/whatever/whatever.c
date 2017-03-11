
int main(void)
{//Task:Move forward 1 yd, stop 5 secs, turn left 90 degrees in place, then back up 2 feet and stop
	int inches=36, ticks; //inches: distance to travel,d=wheel diameter
		float d=2.75;
	ticks= (inches/(3.14159*d)*850);
	//move forward 1 yard
	clear_motor_position_counter(0);//left wheel
	clear_motor_position_counter(3);//right wheel
	mtp(0,500,ticks); //one engine starts before the other
	msleep(100);
	mtp(3,500,ticks);
	bmd(0);
	bmd(3);
