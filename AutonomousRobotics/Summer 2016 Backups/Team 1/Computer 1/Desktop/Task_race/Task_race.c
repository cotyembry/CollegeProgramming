int main(){
	
	while(1){
		
		if(analog10(0)>900){
			
			printf("Black found ");
			
			
			mav(0,100);
			mav(3,150);
			bmd(0);
				bmd(3);
			
			}
			else{
				printf("No black found ");
				mtp(0,0,100);
				mtp(0,100,100);
				bmd(0);
				bmd(3);
				
				
				
				}
		
		
		}
	
	
	}
