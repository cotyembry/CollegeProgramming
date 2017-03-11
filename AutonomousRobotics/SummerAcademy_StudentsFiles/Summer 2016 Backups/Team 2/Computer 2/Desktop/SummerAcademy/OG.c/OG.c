int main (){
while(1==1){
	if(analog10(0)>900){
		msleep(1000);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,500);
	mav(3,500);
	bmd(0);
	bmd(3);
	}
	else if (analog10(0)<900)

		
}
}
	
	
