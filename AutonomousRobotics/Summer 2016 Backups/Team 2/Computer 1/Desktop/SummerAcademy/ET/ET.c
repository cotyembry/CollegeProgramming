int main(){
	while(1==1){
	if (analog10(0)&&analog10(3)>=960){
		printf("Found\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mrp(0,300,250);
		mrp(3,300,250);
		bmd(0);
		bmd(3);
	}
	else if(analog10(0)<960) {
		printf("Not Found Right\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mrp(0,250,400);
		mrp(3,0,400);
		bmd(0);
		bmd(3);
	}
	else if(analog10(0)<960) {
		printf("Not Found Left\n");
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mrp(0,0,400);
		mrp(3,250,400);
		bmd(0);
		bmd(3);
	}
}
}
