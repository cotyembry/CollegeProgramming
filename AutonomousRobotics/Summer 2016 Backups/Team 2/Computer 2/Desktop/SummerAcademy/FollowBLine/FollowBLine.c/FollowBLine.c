int main (){
	
while(1)
{
	 if(analog10(0)>900){
    clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,150);
	mav(3,150);
	bmd(0);
	bmd(3);
	 }
		 else(analog10(1)>900);{
			printf("sensor 1 found black\n");
    clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,150);
	mav(3,0);
	bmd(0);
	bmd(3);

	}	
	
	 }
	 if(analog10(1)>900){
    clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,150);
	mav(3,150);
	bmd(0);
	bmd(3); 
	 }
	 
	else(analog10(0)>900);{
		printf("sensor 0 found black\n");
    clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,0);
	mav(3,150);
	bmd(0);
	bmd(3);
		
}
	//else{
		//printf("sensor 0 else statement\n");

	}
	
	
	
	
	
	
	
	
	
	

		
	//else {
		//printf("sensor 1 else statement\n");
	


	
	
	
