 int main() {
		motor(0, 100);
		motor(3, 100);
		sleep(3.0);
		ao();
		mav(0,100);
		mav(3, -100);
		sleep(0.5);
		ao();
}
		
