int main() {
	int ticksInc = 25;
	int keepRunning = 1;

	while(keepRunning == 1) {
		if(analog10(5) > 150) {
			//turn left
			mrp(0, 450, ticksInc);
		}

		if(analog10(6) > 550) {
			//turn right
			mrp(3, 450, ticksInc);
		}

		mrp(0, 450, ticksInc);
		mrp(3, 450, ticksInc);

		msleep(500);
	}
}