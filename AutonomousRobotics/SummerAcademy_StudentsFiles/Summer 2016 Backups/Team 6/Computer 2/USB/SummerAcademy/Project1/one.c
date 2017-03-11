int main()
{//driving a robot forward
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	
	//move to position
	mtp(0,500,1000);
	mtp(0,500,1000);
	bmd(0);
	bmd(3);
}
