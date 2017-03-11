int main() {
	//circumference = pi * d , 1100 ticks/revolution
	int inches = 36, ticks;
	//inches: distance to travel, d= diameter of wheel
	float d=2.5;
	ticks= (inches/(3.14159*d)*1100);
clear_motor_position_counter(0);
clear_motor_position_counter(1);
	msleep(2000);
	//moves forward 36 inches
    mtp(0,650,ticks);
	mtp(1,650,ticks);
	
	
	msleep(5000); 
	//turn to the left at a 90 degree angle
	//motor 0 controls the left wheel
	mtp(0,0,0);
	mtp(1,500,760);
	
	msleep(2000);
	//move backwards 24 inches
	mtp(0,500,0);
	mtp(1,500,0);
	bmd(0);
	bmd(1);
	//come to a stop before returning to 0
	msleep(3000);
	return 0;
}
