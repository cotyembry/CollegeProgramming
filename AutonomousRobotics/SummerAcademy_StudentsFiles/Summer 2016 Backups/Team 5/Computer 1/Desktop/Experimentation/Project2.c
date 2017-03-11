/*
//driving a robot forward
int main(){
//circumference = pi * d , 1100 ticks/revolution
	int inches = 12, ticks;
	//inches: distance to travel, d= diameter of wheel
	float d=1.2;
	ticks= (inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks
clear_motor_position_counter(0);
clear_motor_position_counter(3);
mtp(0,800,ticks);
	mtp(3,800, ticks);
	bmd(0);
	bmd(3);
	mtp(0,800,0);
	mtp(3,800,0);
	bmd(0);
	bmd(3);
	return 0;
}
	*/
