int main(){
	
	while(1){
		
		if(analog10(0)>950){
			printf("Black found ");
			clear_motor_position_counter(0);
	        clear_motor_position_counter(3);
			
			mtp(0,100,10);
			mtp(3,100,10);
		}
			else{
				printf("No black found ");
				mtp(0,0,100);
				mtp(0,100,100);
			}
	}
	
	
}
