int main() {
	while(1) {
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		if (analog10(0) + analog10(1) < 800) {
			mtp(0,300,100);
			mtp(3,300,100);
			msleep(50);
		}
		else if (analog(0) > 800) {
			mtp(0,400,-50);
			mtp(3,400,50);
			msleep(50);
		}
		else {
			mtp(0,400,50);
			mtp(3,400,-50);
			msleep(50);
		}
	}
}
