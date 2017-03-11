int main()
{
	int distance;
	distance=analog_et(2);//Turns on ET
	printf("ET: %d\n", distance);
	msleep(1000); // wait for stat to change
	
	while(1)
	{
		if(analog_et(2)<=512)//512=tick value, signaled to ET through analog
		{//if too far
			printf("Object far%d\n");
			msleep(100);
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,200,100);//Move forward
			mtp(3,200,100);
			msleep(100);
		}
		if(analog_et(2)>512)//Tells ET at what value of ticks to do command
		{//if too close
			printf("See object close%d\n");
			msleep(100);
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			mtp(0,200,-100);//Move backward
			mtp(3,200,-100);
			msleep(100);
		}
	}
}

