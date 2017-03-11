//driving a robot forward
int main (){
//circumference = pi * d, 1100 ticks/revolution
	int inches = 12, ticks;
	//inches: distance to travel, d = diameter of wheel
	float d = 1.2;
	ticks= (inches/(3.14159*d)*1100);
	//computes the distance from inches to ticks
	
	printf("Clear motor position\n");
	clear_motor_position_counter(0);
	clear_motor_position_counter(1);
	
	printf("Sleep for one second\n");
	msleep(1000);
	
	printf("Move Forward three feet\n");
	mtp(0, 500, -ticks);
	mtp(1, 500, -ticks);

    printf("Sleep for five seconds\n");
	msleep(10000);
	
	printf("Turn left ninety degrees\n");
	clear_motor_position_counter(0);
	clear_motor_position_counter(1);
	mtp(0,0,0);
	mtp(1,500,760);
	
	printf("Sleep for two second\n");
	msleep(2000);
	
	printf("Move backwards two feet\n");
	mtp(0, 500, ticks-185);
	mtp(1, 500, ticks-185);
	bmd(0);
	bmd(1);
	return 0;
}
