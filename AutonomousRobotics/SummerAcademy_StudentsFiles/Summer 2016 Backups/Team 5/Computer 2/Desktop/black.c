int main(){
	while(1==1){
		clear_motor_position_counter(0);
		clear_motor_position_counter(1);
		printf("about to move forward 500 ticks\n");
		mtp(0, 500, -500);
		mtp(1, 500, -500);
		
		msleep(500);
		
		//bmd(0);
		//bmd(1);
		
		//mav(0, 300);
		//mav(1, 300);
		
		//printf("analog value=%d\n",analog10(0));
		//between 600 and ~800 my sensor sees white
		//greater than 900-950 my sensor sees black
	
		
		if(analog10(3)>950){   
			clear_motor_position_counter(0);
		    clear_motor_position_counter(1);
			mtp(0, 300, 500 );
			mtp(1, 300, 500);
			printf("Black color is found\n");
			
			msleep(500);
		}

		else if(analog10(3)>600&&analog10(3)<800){
			mav(0, 300);
			mav(1, 300);
			printf("White found\n");
		}

		else{
			mav(0, 300);
			mav(1, 300);
			printf("default else\n");
			
		}
		
	}
}
	
	
	
	
