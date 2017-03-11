int main(){
	enable_servos();
	set_servo_position(2,1000);
	msleep(1000);
	set_servo_position(0,1100);
	msleep(1000);
	while(analog(2) > 600) {
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,500,50);
		mtp(3,500,50);
		msleep(50);
	}
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	set_servo_position(2,200);
	msleep(1000);
	set_servo_position(0,650);
	msleep(1000);
	mtp(0,500,775);
	mtp(3,500,-775);
	msleep(5000);
}
