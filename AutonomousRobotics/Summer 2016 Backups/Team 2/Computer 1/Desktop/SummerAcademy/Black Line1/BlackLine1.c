int main(){
	while(1==1){
		if((analog10(0)>950)&(analog10(3)>950)){ //When both sensors see only white
			//analog 0=left, analog1=right
			printf("Both White");
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
		mav(0,1000);//right moves forward with left
		mav(3,1000);//left moves forward with right
		}
		else if(analog10(0)<950){//When left sees black
			printf("Left Black");
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,0,0);//Left stop
			mtp(3,1000,380);//Right turn about 45 degrees
		}
		else if(analog10(1)<950){//When right sees black
			printf("Right Black");
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,1000,380);//Left turn about 45 degrees
			mtp(3,0,0);//Right stop
		
		}
	}
}
