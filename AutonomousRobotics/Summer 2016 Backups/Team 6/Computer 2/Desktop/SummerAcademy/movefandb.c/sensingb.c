int main(){
	while(1){
		//printf("analog value =%d\n",analog10(0)));
		//between 600 and ~800my sensor sees white 
		//greater than 900my sensor sees black 
		//printf("%d\n",analog);
		if ((analog10(0)>=900) && (analog10(3) >= 900)){
           printf("Black color found\n");
		   mrp(0,100,100);
		   mrp(3,100,100);
			bmd(0);
			bmd(3);
	      
		  }
	      if((analog10(0) <900) && (analog10(3) >=900)) {
		     printf("Sensor 0 is not seeing Black\n");
			 mrp(0,100,10);
		     bmd(0);
		  }  
		  if ((analog10(3) <900) && (analog10(0)>=900)) {
			 printf("Sensor 3 is not seeing Black\n");
			 mrp(3,100,10);
		     bmd(3);
		  }  
			 
		     
			if((analog10(0)<900) && (analog10(3)<900)){
			 printf("I'm lost\n");
				msleep(2000);
			 
				
			}
		msleep(1000);
	}
		 
}

