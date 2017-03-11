int main()//does not need void
{
	set_servo_position(2,975);
	enable_servos(); //2 is open/close
	msleep(1000); //needs to sleep
	set_servo_position(0,1900); //0 is up/down
	disable_servos();
}
//0 vertical
//2 horizontal
//0 at 1900, 600 min
//2 at 0=close, 975=open
