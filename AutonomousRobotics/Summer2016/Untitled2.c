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
	
	float circumference = 0;
	float oneWheelTurn = 0;
	
	float diameter = 0;
	float examplesCircumference = 0;
	
	switch(tireToUse) {
		case 1:
			//big wheel
			diameter = 2.0;
		
			//circumference = 2 * 3.14159 * (diameter / 2);
			//examplesCircumference = 1100;
			
			//this is the example formula
			//ticks = (distanceToTravel / (3.14159 * diameter) * examplesCircumference);
		
			//circumference = 2 * 3.14159 * (diameter / 2) * 150; //* 150 because of testing and it worked to go one rotation of the wheel - if I remember correctly
		
			
		
			//printf("circumference = %f\n", circumference);
		
			//one turn of the wheel
			//oneTick = circumference / 1100;
			
			//ticks = distanceToTravel / oneTick;
		
			//printf("ticks = %f\n", ticks);
		
			ticks = circumference;
		
		
			break;
		
		case 2:
			//small wheel
			
			diameter = 1.79;
			circumference = 3.14159 * diameter;
			oneWheelTurn = 175; //378
		
			//driving a robot forward
			//circumference = pi * d , 1100 ticks/revolution
			//int inches=12, ticks;//inches: distance to travel, d= diameter of wheel
			//diameter =  1.76;
			
		
			//ticks = (distanceToTravel/(3.14159*diameter)*1100);//computes the distance from inches to ticks
			//ticks = (distanceToTravel/(3.14159*diameter)*77);//computes the distance from inches to ticks //this is a little bit too much
		
			/*//just testing formulas
			distanceToTravel / 3.14*diameter
			'inches' / 'circumference'
		
			*/
		
			//this turns the inches passed in, into 66 'ticks'. So for 36 inches it would be: 1/66th => 1/66 * 36 = .54 repeating
			//ticks = (distanceToTravel/(3.14159*diameter)*66);//computes the distance from inches to ticks
		
		
		
			//these first two lines are just me solving the problem as an example
			//oneWheelTurn / 1 = x / distanceToTravel
			//distanceToTravel * oneWheelTurn = x
			
			ticks = distanceToTravel * oneWheelTurn;
		
		
			
			break;
		
		default: 
			printf("Choose a correct wheel number\n");
	}
	
	return ticks;
}

int move(ticks) {
	//three is the left tire motor
	
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	
	mrp(zero, speed-100, ticks);
	mrp(three, speed, ticks);
	
	bmd(zero);
	bmd(three);
	
	return 0;
}

int turnLeft() {
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	
	mrp(zero, speed, -600);
	mrp(three, speed, 600); //1200 looks like it is a solid value for a left turn if the other wheel doesn't move/turn at all
	
	bmd(zero);
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
	//this worked to take the bot 36 inches
	//long ticks = getTickValue(2, 36);
	//moveForwardOneTile(ticks);

	
	//1. move forward one yard
	//long ticks = getTickValue(2, 1);
	//move(ticks);
	
	//2. turn left 90 degrees
	//turnLeft();
	
	//3. back up two feet
	//ticks = getTickValue(2, -24);
	//move(ticks);
	
	move(1110);
	
	return 0;
}

