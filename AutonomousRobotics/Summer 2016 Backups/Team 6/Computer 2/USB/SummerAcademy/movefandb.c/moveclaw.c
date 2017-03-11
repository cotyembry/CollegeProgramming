/*int main(){
	while(1){
		//printf("analog value =%d\n",analog10(0)));
		//between 600 and ~800my sensor sees white 
		//greater than 900my sensor sees black 
		//printf("%d\n",analog);
		if(analog10(0)>=900){
		   printf("Black color found\n");
		   mrp(0,100,100);
		   mrp(3,100,100);
			bmd(0);
			bmd(3);
		}
		else{
			printf("Black NOT found\n");
			mrp(0,100,-100);
			mrp(3,100,-100);
			bmd(0);
			bmd(3);
		}
		msleep(1000);
	}
	
	
	
}
		 
	
	*/
	
