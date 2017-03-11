int main(){
int distance;
	while(1){
		distance = analog_et(0);
		printf("ET: %d\n", distance);
	}
	msleep(1000);            //wait for stat to change
	while(1){                           //loop forever
		if(analog10(0)>512){            // if to close
			clear_motor_position_counter(0);
	        clear_motor_position_counter(1);
			mav(0, 200);                     //back up
			mav(0, 200);                     
			
		}
		if(analog10(0)<=512){                      //if to far
			clear_motor_position_counter(0);
	        clear_motor_position_counter(1);
			mav(0, 200);                     //get closer
			mav(1, 200);
		}
	}
}
