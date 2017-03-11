int moveForward(int speed, int ticks) {
	mrp(0, speed, ticks);
	mrp(3, speed, ticks);

	printf("moveForward, ticks: %d\n", ticks);

	msleep(ticks);
	return 0;
}

int turnLeft(int speed, int ticks) {
	mrp(0, speed, ticks);
	msleep(ticks);

	printf("turnLeft, ticks: %d\n", ticks);

	return 0;
}

int turnRight(int speed, int ticks) {
	mrp(3, speed, ticks);
	msleep(ticks);

	printf("turnRight, ticks: %d\n", ticks);

	return 0;
}

int main() {
	int ticksInc = 25;
	int whileLoopInc = 7;
	int keepRunning = 1;

	int p5 = 0; //initialize variables
	int p6 = 0;
	while(keepRunning == 1) {
		p5 = analog10(5);
		if(p5 > 970 && p5 < 1020) {
			//p5 sees black: ~996
			//turn right
			while(analog10(5) > 970 || analog10(5) < 1020) {
				turnRight(450, whileLoopInc);
			}

		}

		p6 = analog10(6);
		if(p6 > 915 && p6 < 1000) {
			//p5 sees black: ~935 - ~980
			//turn left
			while(analog10(6) > 915 || analog10(6) < 1000) {
				turnLeft(450, whileLoopInc);
			}
		}

		printf("p5: %d, p6: %d\n", p5, p6);

		moveForward(450, ticksInc);

		msleep(500);
	}
}