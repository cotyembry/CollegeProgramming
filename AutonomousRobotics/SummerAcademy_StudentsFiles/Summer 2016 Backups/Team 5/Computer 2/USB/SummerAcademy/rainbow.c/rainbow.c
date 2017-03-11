int main() {
	while(1==1){
		
		clear_motor_position_counter(0);
		clear_motor_position_counter(1);
		printf("about to move forward 500 ticks\n");
		mtp(0, 300, -50);
		mtp(1, 300, -50);
		
		msleep(500);
		
		if(analog10(3)>200){ 	
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 0, 0 );
				mtp(1, 0, 0);
				printf("red color is found in zero\n");
				
				msleep(1000);
		    
	    }
	 		
		if(analog10(5)>200){ 		
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 0, 0 );
				mtp(1, 0, -);
				printf("red color is found in one\n");
				
				msleep(1000);
			
		}
				
			     if(analog10(3)>200){ 	
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 0, 0 );
				mtp(1, 0, 0);
				printf("Blue color is found in zero\n");
				
				msleep(1000);
		    
	    }
	 		
		if(analog10(5)>200){ 		
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 0, 0 );
				mtp(1, 0, 0);
				printf("Blue color is found in one\n");
				
				msleep(1000);
		   
	    }
		
    }
}
		   
	    }
		
    }
}
