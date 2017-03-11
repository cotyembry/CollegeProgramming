int main(void){
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,1000,1500);//turn 1
	mtp(3,750,1500);//turn 1
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,500);//turn 2
	mtp(3,900,500);//turn 2
	bmd(0);
	bmd(3);
	mav(0,1000);//continuous turn
	mav(3,-1000);//continuous turn
}
