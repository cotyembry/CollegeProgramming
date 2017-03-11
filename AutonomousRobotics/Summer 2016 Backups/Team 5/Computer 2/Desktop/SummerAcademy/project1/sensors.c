
int main()
{
	wait_for_light(0);
	wait_for_light(3);
	// wait for light sub routine using port 0
	beep();
	void cbc_display_clear();
	printf("Running Code\n");
	beep();
	

	while(1==1){
		//printf("analog value=%d\n",analog10(0));
		//between 600 and ~800 light sensor see white
		//greater than 900 the sensor sees black
		
		
		if(analog10(0)>900){
			mtp(0, 500, 1100);
			mtp(1, 0, 1000);
		
		}
		
		if(analog10(1)>900){
	        mtp(0, 0, 1100);
			mtp(1, 500, 1100);
			
		}
	}
	
}
	
	
	


