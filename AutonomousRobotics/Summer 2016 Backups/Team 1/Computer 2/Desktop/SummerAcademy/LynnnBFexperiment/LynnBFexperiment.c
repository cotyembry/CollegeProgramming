int main(){
	int i;
	int inches=12, ticks;
	
	float d=2.5;
	
	ticks=(inches/(3.14*d)*1100);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	bmd(0);
	bmd(3);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,500);
	mtp(3,0,0);
	bmd(0);
	bmd(3);
	
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,ticks);
	mtp(3,1000,ticks);
	bmd(0);
	bmd(3);
	
	for( i = 0; i<500; i++){
		mav(0,1000);
	mav(3,0);
	
		}
		
		bmd(0);
	bmd(3);
	return 0;
	
	
	
	
	}
