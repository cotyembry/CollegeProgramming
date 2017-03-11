int main(){
	while(1==1){
		if((analog10(0)<900)&&(analog10(1)<900)){ //When both sensors see only white
			//analog 0=left, analog1=right
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
		mav(0,250);//right moves forward with left
		mav(3,250);//left moves forward with right
		}
		else if(analog10(0)>900){//When left sees black
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,0,0);//Left stop
			mtp(3,500,380);//Right turn about 45 degrees
		}
		else if(analog10(1)>900){//When right sees black
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,500,380);//Left turn about 45 degrees
			mtp(3,0,0);//Right stop
		
		}
	}
}
