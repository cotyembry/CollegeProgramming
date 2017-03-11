int main(){
	while(1==1){
		
		clear_motor_position_counter(0);
		clear_motor_position_counter(1);
		printf("about to move forward 500 ticks\n");
		mtp(0, 300, -13);
		mtp(1, 300, -13);
		
		msleep(500);
		
		//bmd(0);
		//bmd(1);
		
		//mav(0, 300);
		//mav(1, 300);
		
		//printf("analog value=%d\n",analog10(0));
		//between 10 and ~800 my sensor sees white
		//greater than 900-1100 my sensor sees black
		
		
		/*
		
		if(analog10(3)>10&&analog10(3)<400){
			clear_motor_position_counter(0);
		    clear_motor_position_counter(1);
			mrp(0, 200, 50 );
			mrp(1, 200, 50);
			printf("White found in port zero\n");
			
		}	
		
		
		if(analog10(5)>10&&analog10(5)<400){
			clear_motor_position_counter(0);
		    clear_motor_position_counter(1);
			mrp(0, 200, 50 );
			mrp(1, 200, 50);
			printf("White found in port one\n");
		}
		*/
	
		if(analog10(3)>401){ 	
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 300, -13 );
				mtp(1, 0, 0);
				printf("Black color is found in zero\n");
				
				msleep(1000);
		    
	    }
	 		
		if(analog10(5)>401){ 		
				clear_motor_position_counter(0);
				clear_motor_position_counter(1);
				mtp(0, 0, 0 );
				mtp(1, 300, -13);
				printf("Black color is found in one\n");
				
				msleep(1000);
		   
	    }
		
    }
}


    
	
	
	
	
