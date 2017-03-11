//driving a robot forward

int main(){
	//pi* diameter = c 1100 ticks/reveloution
	
	int inches= 36,ticks;
	//inches: distance to travel d= diameter of wheel
	float d=2.7;
	ticks = (inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,ticks);
	mtp(3,500,ticks);
	
	bmd(0);
	bmd(3);
	
		mtp(0,500,0);
	mtp(3,500,0);
	
	bmd(0);
	bmd(3);
	
	return 0;
	
	
	}
