int main() {
	
	while (1){
		if((analog10(0)>950)&(analog10(3))){
			printf("WHITE found\n");
	
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mav(0,1000);
		mav(3,1000);
	}
	else if (analog10(0)<950){
		printf("left found BLACK\n");
	
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,0,0);
		mtp(3,1000,380);
}
	else if (analog10(1)<950){
		printf("right found BLACK\n");
	
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,1000,380);
		mtp(3,0,0);
			}
		}
	}
	
