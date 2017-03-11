//driving a robot forward
int main ()
{
	set_servo_position(0,2000);
	msleep(500);//raise up claw
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mav(0,1000); //speed max is 1000
	mav(3,-1000); //mav=move at velocity(continues moving)
	// = backwards
	bmd(0);
	bmd(3);
	mtp(0,500,0); // 0 makes wheels go backwards b/c counter of forwards
	mtp(3,500,0);
	bmd(0);
	bmd(3);
	return (0);
}
