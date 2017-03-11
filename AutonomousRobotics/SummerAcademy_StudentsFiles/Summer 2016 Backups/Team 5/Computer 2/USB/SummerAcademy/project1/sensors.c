
int main()
{
	wait_for_light(0);
	wait_for_light(3);
	// wait for light sub routine using port 0
	beep();
	void cbc_display_clear();
	printf("Running Code\n");
	beep();
	msleep(1000);
	//printf("analog value=%d\n",analog10(0));
		//between 600 and ~800 light sensor see white
		//greater than 900 the sensor sees black

	while(1==1){
		
		
		
		if(analog10(0)>900){
			mav(0, 300);
			mav(1, 0);
		
		}
		
		if(analog10(1)>900){
	        mav(0, 0);
			mav(1, 300);
			
		}
	}
	
}
	
	
	


