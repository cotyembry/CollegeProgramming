int main()
{
	while(1==1)//will repeat on a loop, if true, executes again, if false, will stop the loop
	{
		//printf("analog value=%d\n",analog10(0));//%d=1
		//between 600-800(~), sensor sees white
		//over 900, sensor sees black
		if(analog10(0)>900) //when it sees black, it says black found
		{ 
			printf("Black color found\n");
		}
		else if(analog10(0)>600&&analog10(0)<800) //when it sees white, it says white found
		{
			printf("White found\n");
		}
		else //if it sees neither, it says defualt
		{
			printf("Default else\n");
		}
	}
}
