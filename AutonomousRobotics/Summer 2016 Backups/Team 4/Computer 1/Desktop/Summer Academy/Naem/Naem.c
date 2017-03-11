//driving a robot forward
int main()
{//circumference = pi*d, 1100 ticks/revolution
		int inches=42, ticks;
//inches: distance to travel, d= diameter of wheel
	float d=4.2;
	ticks= (inches/(3.14*d)*1100);
//computes the distance from inches to ticks
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,342,ticks);
	mtp(3,340,ticks);
	bmd(0);
	bmd(3);
	mtp(0,342,0);
	mtp(3,342,0);
	bmd(0);
	bmd(3);
}












	
	







//DOGMEAT, EXCELSIOR!
//I'm The Final Line
