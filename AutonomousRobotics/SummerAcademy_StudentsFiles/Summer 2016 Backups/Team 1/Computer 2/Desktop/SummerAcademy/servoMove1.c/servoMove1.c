//up

int main(){
	set_servo_position(0,1000);
	
	enable_servos();
	
	msleep(3000);
	
	disable_servos();
	

	//claw
	
	set_servo_position(2,2000);
	
	enable_servos();
	
	msleep(2000);
	
	disable_servos();
	}
