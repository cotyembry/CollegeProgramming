//driving a robot forward
int main ()
{
	//circumpherence = pi*d, 1100 ticks/revolutions
	int inches=12, ticks; //inches: distance to travel,d=wheel diameter
		float d=2.75;
	ticks= (inches/(3.14159*d)*1100); //computes the distance from in. to ticks
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,ticks); //speed max is 1000
	mtp(3,500,ticks); //mtp= move to position, mav=move at velocity(continues moving)
	mtp(0,500,0); // 0 makes it go backwards b/c counter of forwards
	mtp(3,500,0);
	bmd(0); //bmd= block motor done, aka done with motor
	bmd(3);
	return (0);
}
