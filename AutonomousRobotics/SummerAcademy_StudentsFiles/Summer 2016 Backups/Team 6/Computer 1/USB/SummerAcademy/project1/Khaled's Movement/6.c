	int main (){
//circumference = pi*d ,1100 ticks/revolution
		int inches =12,ticks;
//inches: distance to travel, d= diameter of wheel
		float d=3.5;
		ticks= (inches/(3.14*d)*1100);
//computes the distance from inches to ticks 
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,1000,3 * ticks);
		mtp(3,1000,3* ticks);
		bmd(0);
		bmd(3);
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		msleep(5000);
		mtp(0,1000,250);
		mtp(3,1000,-250);
		bmd(0);
		bmd(3);
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,1000,-2 * ticks);
		mtp(3,1000,-2 * ticks);
		bmd(0);
		bmd(3);
}	

