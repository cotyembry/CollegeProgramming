// Created on Mon Jun 13 2016

int zero = 0;
int one = 1;
int two = 2;
int three = 3;
int speed = 1000;

float getTickValue(tireToUse, distanceToTravel) {
	//distanceToTravel should be specified in inches
	
	long ticks = 0;
	long oneTick = 0;
	
	long circumference = 0;
	
	long diameter = 0;
	long examplesCircumference = 0;
	
	switch(tireToUse) {
		case 1:
			//big wheel
			diameter = 2.0;
		
			//circumference = 2 * 3.14159 * (diameter / 2);
			//examplesCircumference = 1100;
			
			//this is the example formula
			//ticks = (distanceToTravel / (3.14159 * diameter) * examplesCircumference);
		
			circumference = 2 * 3.14159 * (diameter / 2) * 150; //* 150 because of testing
		
			
		
			printf("circumference = %f\n", circumference);
		
			//one turn of the wheel
			//oneTick = circumference / 1100;
			
			//ticks = distanceToTravel / oneTick;
		
			//printf("ticks = %f\n", ticks);
		
			ticks = circumference;
		
		
			break;
		
		case 2:
			//small wheel
		
			diameter = 1.76;
		
			circumference = 2 * 3.14159 * (diameter / 2) * 200; //* 150 because of testing
			
			circumference = ticks;
			
			break;
		
		default: 
			printf("Choose a correct wheel number\n");
	}
	
	return ticks;
}

int move(ticks) {
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	
	mrp(zero, speed, ticks);
	mrp(three, speed, ticks);
	
	bmd(zero);
	bmd(three);
	
	return 0;
}

int turnLeft() {
	clear_motor_position_counter(three);
	
	//mrp(zero, speed, ticks);
	mrp(three, speed, 1100); //1100 is almost perfect for a left turn
	
	//bmd(zero);
	bmd(three);
	
	return 0;
}

void moveForwardOneTile(ticks) {
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	
	mrp(zero, speed, ticks);
	mrp(three, speed, ticks);
	
	bmd(zero);
	bmd(three);
}

int main() {
	long circumference = getTickValue(2, 36);
	
	//moveForwardOneTile(circumference * 1.57895);
	
	
	move(circumference);

	
	return 0;
}

