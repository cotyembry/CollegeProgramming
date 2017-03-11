int main()
{// drive forward
	//int inches =
clear_motor_position_counter(0);
clear_motor_position_counter(3);
mtp(0,300,1000);
mtp(3,300,1000);
bmd(0);
bmd(3);
mtp(0,300,1000);
mtp(3,300,1000);
bmd(0);
bmd(3);
return 0;
}
