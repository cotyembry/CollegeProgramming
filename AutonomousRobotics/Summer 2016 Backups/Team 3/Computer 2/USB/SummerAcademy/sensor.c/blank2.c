                  
int main(){
	while(1){
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		//keep moving forward
		mtp(0,400,70);
		mtp(3,400,70);
		msleep(500);
		
		/*while(analog10(0) + analog10(1) < 900){
			clear_motor_position_counter(0);
			clear_motor_position_counter(3);
			
			mtp(0,450,100);
			mtp(3,450,100);
			msleep(100);
		}
		
		//black == 916 - 917
		//white < 916
		
		//deal with the left sensor first (port 1)
		*/
		
		
		if(analog10(0)>400) {/* found black */ //black === 956
			printf("port 0 found Black\n");
            clear_motor_position_counter(0);
		
				 
					mtp(0,300,50);
				 msleep(100);
				//white === 32
			//turn right
			//mtp(1,300,100);
			//mtp(3,300,100);
			

		}
		/*
		else {
			mtp(0,200,-100);
			mtp(3,200,100);
			msleep(100);
		}
		*/
		
		
		//now deal with the right sensor (port 1)
		if(analog10(3)>400){
			//turn left 
			printf("port 3 found black\n");
			clear_motor_position_counter(3);
					mtp(3,300,50);
				 msleep(100);
			
			//mtp(0,300,100);
			//mtp(3,300,100);
			//msleep(100);
		
		}
	}
		
		
		
	  
 }
		
	  
