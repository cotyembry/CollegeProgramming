int main(){
	while(1==1){
		//printf("analog value=%d\n",analog10(0));
		//between 600 and ~800 my sensor sees white
		//greater than 900 my sensor sees black
		if(analog10(0)>900){
			printf("black color found\n");
		}
		else if(analog10(0)>600&& analog10(0)<800){
			printf("WHITE found\n");
		}
		else{
			printf("default else\n");
		}
	}
}
