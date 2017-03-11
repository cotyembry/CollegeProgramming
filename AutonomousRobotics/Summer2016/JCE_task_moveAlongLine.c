//can using while loops be a form of functional programming? I think functional programming is composed of functions that take input and return 'the same' output every time
//but maybe not, because the while loop is just keeping a 'block' of code running. I guess you could think of that 'block' of code as a function. well sort of. idk

int main() {
	int numberOfAdjustmentsBetweenSensorAndTape = 0;

	int keepRunningWhileLoop = 1;
	int ticksInc = 25;
	int ranOnce = 0;

	int sensor0Corrections = 0;
	int sensor3Corrections = 0;

	while(1 == keepRunningWhileLoop) {
		if(analog10(0) > 920) { //400 because its a split pretty much in the middle of ~950 (for black) and ~50 (for white)
			//black found, turn left
			while(analog10(0) > 400) {
				//move the tire until the sensor no longer sees the tire
				mrp(0, 450, ticksInc);
				msleep(500);
			}
			sensor0Corrections++; //this will help me 'balance' the bot perfectly (hopefully) during a turn 

			//now I will add some code logic to check the two correction variables to make sure nothing crazy is going on with the bot as far as turning goes (i.e. getting stuck on a corner turn or something)
			int result = sensor3Corrections - sensor0Corrections;
			if(result < 0) result *= -1; //to remove the negative sign
			if(result > 10) { //I chose 10 because if a motor is going through 10 'corrections' more than the other motor, the bot is probably trying to turn a pretty 'sharp' turn. It might need to be changed to something else to be more optimal
				//apply some correction movements
				//1. get the distance - 1 and only one time - from the black tape to the sensor
				if(ranOnce == 0) {
					int inc = 0;
					while(!(analog10(3) > 920)) {
						//i.e. while its not touching black.
						//so, move until this sensor touches the black tape
						//but for the best result, I'll store the distance
						//from the black tape to the sensor so I can keep the
						//black tape perfectly centered between the two sensors
						mrp(3, 450, ticksInc);
						msleep(500);
						numberOfAdjustmentsBetweenSensorAndTape++; //keep track of this for use later
					}
					ranOnce = 1; //to make this code never run again
				}
				else {
					int inc = 0;
					while(inc < numberOfAdjustmentsBetweenSensorAndTape) {
						mrp(3, 450, ticksInc);
						msleep(500);
					}
				}
			}
		}

		if(analog10(3) > 920) {
			//black found, turn right
			while(analog10(3) > 400) {
				mrp(0, 450, ticksInc);
				msleep(500);
			}
			sensor3Corrections++;

			//TODO: add the above code in here as well
		}
	}
}