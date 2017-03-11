int main(){
	enable_servos();
	set_servo_position(0,1750);
	set_servo_position(2,1500);
	msleep(1000);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,-700);
	mtp(3,500,-700);
	msleep(2000);
	enable_servos();
	set_servo_position(0,1850);
	set_servo_position(2,0);
	msleep(1000);
	set_servo_position(0,1600);
	msleep(1000);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,500,0);
	mtp(3,500,1500);
	msleep(3000);
	enable_servos();
	set_servo_position(0,1500);
	set_servo_position(2,975);
	msleep(3000);
	disable_servos();
	return 0;
}
