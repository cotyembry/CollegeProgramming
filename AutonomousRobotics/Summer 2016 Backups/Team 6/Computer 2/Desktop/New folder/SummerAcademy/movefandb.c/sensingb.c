
int main(){
	
	int numberOfTimesThroughWhileLoop = 0;
	int sensor0foundBlack = 0;
	int tickInc = 5;
	
	while(1){
		//printf("analog value =%d\n",analog10(0)));
		//between 600 and ~800my sensor sees white 
		//greater than 900my sensor sees black 
		//printf("%d\n",analog);
		if ((analog10(0)<=600) && (analog10(3) <= 400)){
           printf("White color found\n");
		   mrp(0,300,100);
		   mrp(3,300,100);
			bmd(0);
			bmd(3);
	      
		  }
		if ((analog10(0)>=900)){
             printf("Sensor 0 is seeing Black\n");
			 while(analog10(0) >600) { //while it doesnt see white
				 //keep turning until it sees white
				 mrp(3,100, tickInc);
				 bmd(3);
			 }
		  }  
		  if ((analog10(3) >=900)){
			 printf("Sensor 3 is seeing Black\n");
			 while(analog10(3) >= 400) { //while it doesnt see white
				 //keep turning until it sees white
				 mrp(0,100, tickInc);
				 bmd(0);
			 }
		  }  
			 
		     	
		//msleep(1000);
		numberOfTimesThroughWhileLoop++;
		if(numberOfTimesThroughWhileLoop > 7) {
			numberOfTimesThroughWhileLoop = 0;
		}
		
		
	}
		 
}

