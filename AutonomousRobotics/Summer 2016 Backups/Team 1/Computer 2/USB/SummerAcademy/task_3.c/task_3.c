int turnLeft() {
	printf("left found BLACK\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0, 800, -1000);
		mtp(3, 800, -1000);
		msleep(50);
		mtp(0,0,0);
		mtp(3,200,2000);
		//bmd(0);
		//bmd(3);
		
		msleep(50);
}
int turnRight(){
	printf("right found BLACK\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0, 800, -1000);
		mtp(3, 800, -1000);
		msleep(50);
		mtp(0,100,2000);
		mtp(3,0,0);
		//bmd(0);
		//bmd(3);
	
		msleep(50);
		

return 0;
}

int main() {
	
	while (1){
		if((analog10(0)<800)&&(analog10(1)<800)){
			printf("WHITE found\n");
	
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mav(0,100);
		mav(3,100);
		//bmd(0);
		//bmd(3);
			
		msleep(50);
		}
		
	else if (analog10(0)>910){
		
	int turnLeft();
		printf("left found BLACK\n");
}
	else if (analog10(1)>910){
		printf("right found BLACK\n");
		
	int turnRight();
			}
		}
	}int turnLeft() {
	printf("left found BLACK\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0, 800, -1000);
		mtp(3, 800, -1000);
		msleep(50);
		mtp(0,0,0);
		mtp(3,200,2000);
		//bmd(0);
		//bmd(3);
		
		msleep(50);
}
int turnRight(){
	printf("right found BLACK\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0, 800, -1000);
		mtp(3, 800, -1000);
		msleep(50);
		mtp(0,100,2000);
		mtp(3,0,0);
		//bmd(0);
		//bmd(3);
	
		msleep(50);
		

return 0;
}

int main() {
	
	while (1){
		if((analog10(0)<800)&&(analog10(1)<800)){
			printf("WHITE found\n");
	
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mav(0,100);
		mav(3,100);
		//bmd(0);
		//bmd(3);
			
		msleep(50);
		}
		
	else if (analog10(0)>910){
		
	int turnLeft();
		printf("left found BLACK\n");
}
	else if (analog10(1)>910){
		printf("right found BLACK\n");
		
	int turnRight();
			}
		}
	}
	
		
		
