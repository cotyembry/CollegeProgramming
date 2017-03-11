int main(){
	//Task: Follow a black line across a white board
	while(1==1){
		if((analog10(0)<960)&(analog10(1)<960))//When both sensors see only white
			{ //Values for black and white are variant, error around 10-20
			//analog 0=left, analog 1=right
			printf("Both White");//Tells when both see white
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mav(0,350);//right moves forward with left
			mav(3,350);//left moves forward with right
				msleep(50);
		}
		else if(analog10(0)>960)
			{//When left sees black
			printf("Left Black");
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,0,0);//Left stop
			mtp(3,350,570);//Right turn about 45 degrees
				msleep(50);
		}
		else if(analog10(1)>960)
			{//When right sees black
			printf("Right Black");
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,350,570);//Left turn about 45 degrees
			mtp(3,0,0);//Right stop
				msleep(50);
		
		}
	}
}
