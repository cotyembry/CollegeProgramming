int main() {
	enable_servos();
	set_servo_position(2,1200);
	set_servo_position(0,1100);
	msleep(1000);
	while(1==1) {
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		if (analog10(2) > 900) {
			mtp(0,500,100);
			mtp(3,500,100);
			msleep(100);
		}
		else if (analog10(2) < 300){
			mtp(0,500,-100);
			mtp(3,500,-100);
			msleep(100);
		}
		else {
		freeze(0);
		freeze(3);
		}
	}
}
