int main() {
	clear_motor_position_counter(0);
  clear_motor_position_counter(1); 
	printf("Team Atomatons!, Im Bot-Bot");
	mav(0,-1000);
	mav(1,1000);
	bmd(0);
	bmd(1);
		msleep (2000);
	
	
	printf("Bot-Bot OUT!");

	return 0;
}
	
