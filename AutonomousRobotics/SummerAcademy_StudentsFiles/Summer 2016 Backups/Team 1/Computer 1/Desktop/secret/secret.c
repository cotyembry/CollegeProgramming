/*int move(int speed, int ticks) {
	clear_motor_position_counter(0);
    clear_motor_position_counter(2);
	mtp(0,speed,ticks);
	mtp(2,speed,ticks);
	msleep(1000);
	 
	//ao();*/
	 
 }
 
 
// int main(){
  //  clear_motor_position_counter(0);
    //clear_motor_position_counter(2);
 
	 
	 
	//while(analog10(0)+analog10(1)<=700);{
	 int keepRunning = 1;
	 while(keepRunning == 1) {
		printf("in while loop\n");
		
		 if(analog10(0) >986 &&analog10(0)<1001) { //analog10(0) > 986
			 //turn left
		 }
		 
		 if(analog10(1) >986 &&analog10(1)<1001)  {//analog10(0)<520
			 //turn right
		 }
		 
		/*
		move(875, -982);
	
		move(964, 356);
		
	 
		move(765, -987);
	
		move(789, 987);
		
		
		
		clear_motor_position_counter(0);
		clear_motor_position_counter(2);
		msleep(123);
		 
	}
}
