int main(){
	enable_servos();
	set_servo_position(0,1950);
	set_servo_position(2,1400);
	sleep(1);
	clear_motor_position_counter(0);
	clear_
