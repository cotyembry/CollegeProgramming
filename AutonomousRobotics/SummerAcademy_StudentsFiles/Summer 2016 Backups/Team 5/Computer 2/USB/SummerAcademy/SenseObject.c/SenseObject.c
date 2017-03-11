int main(){
while(1){
	if(analog_et(0)>100){
	clear_motor_position_counter(0);
	      clear_motor_position_counter(1);
			mrp(0, 400, -200 );                      
			mrp(1, 400, -200);
	}
	
	    int distance;
	
		distance = analog_et(0);
		printf("ET: %d\n", distance);
	
	msleep(1000);  	//wait for state to change
	
	    if(analog_et(0)<100){                       //if to far
			
			printf("FOUND IT\n");
			
			clear_motor_position_counter(0);
	        clear_motor_position_counter(1);
			mrp(0, 400, 200);                         //get closer
			mrp(1, 400, 200);
				
				
		}
	}
}
