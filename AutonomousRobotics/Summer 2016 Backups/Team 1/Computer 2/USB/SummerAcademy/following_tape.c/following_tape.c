int turnLeft() {
	printf("left found BLACK\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		//mtp(0, 800, -500);
		//mtp(3, 800, -500);
		msleep(50);
		mrp(3,200,20);
		//bmd(0);
		//bmd(3);
		
		msleep(50);
}
int turnRight(){
	printf("right found BLACK\n");
		//clear_motor_position_counter(0);
		//clear_motor_position_counter(3);
		//mrp(0, 800, -500);
		//mrp(3, 800, -500);
		msleep(50);
		mrp(0,200,20);
		//bmd(0);
		//bmd(3);
	
		msleep(50);
		

return 0;
}

int main() {
	
	while (1){
		if((analog10(0)<=900)&&(analog10(1)<=900)){
			printf("WHITE found\n");
	
		//clear_motor_position_counter(0);
		//clear_motor_position_counter(3);
		mrp(0,200,20);
		mrp(3,200,20);
		//bmd(0);
		//bmd(3);
			
		msleep(50);
		}
		
	else if (analog10(0)>=901){
		
	int turnLeft();
		printf("left found BLACK\n");
}
	else if (analog10(1)>=901){
		printf("right found BLACK\n");
		
	int turnRight();
			}
		}
	
	}
	
