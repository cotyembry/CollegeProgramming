int main()
{//driving a robot forward
	clear_motor_position_counter(0); //(x)= motor port
	clear_motor_position_counter(3); //clear preps for instructions
	//'move to position'
	mtp(0,500,1000); // motor,speed,ticks
	mtp(3,500,1000); //ticks = distance for wheels
	bmd(0);
	bmd(3);
	return 0; //everything worked fine, no errors
}
