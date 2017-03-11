int main()
{//Forward, right 90 deg, forward same distance, right 90 deg, repeat to get square, turn left 45 deg, 360 left in place
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,600,1106);//Forward 1 foot
	mtp(3,600,1106);
	msleep(2000);
	mtp(0,0,0);//Right wheel stop
	mtp(3,600,750);//Turn right 90 degrees
	bmd(0);
	bmd(3);
	
	//Repeat 1, 1/2 foot, half speed, half pause time
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,553);
	mtp(3,300,553);
	msleep(1000);
	mtp(0,0,0);
	mtp(3,300,750);
	bmd(0);
	bmd(3);
	
	//Repeat 2, full foot, speed, and pause time
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,600,1106);
	mtp(3,600,1106);
	msleep(2000);
	mtp(0,0,0);
	mtp(3,600,750);
	bmd(0);
	bmd(3);
	
	//Repeat 3, half foot,speed, and pause time
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,553);
	mtp(3,300,553);
	msleep(1000);
	mtp(0,0,0);
	mtp(3,300,750);
	bmd(0);
	bmd(3);
	
	//Turn left 45 degrees, forward 4 inches
	mtp(0,600,375);
	mtp(3,0,0);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,368);
	mtp(3,300,368);
	bmd(0);
	bmd(3);
	
	//360 left in place
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,3000);
	mtp(3,0,0);
	bmd(0);
	bmd(3);
	return(0);
}

	
	
	
	
	
	
	
	
	
	
	
