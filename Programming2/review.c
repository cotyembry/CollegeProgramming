#include<stdio.h>
/*
	Author: Coty Embry
	Course: CMPSC 1133, Computer Programming II
	Program Summary: This program will calculate and display the sum of the numbers 1 through 100.
	Input: stdin
	Output: stdout
*/

int main(void) {
	int i, sum=0;
/*
	This for loop will start at 1 and with the function, "i++," in it, the program will add 1 to each additional number until it reaches less than or equal to 100. Then the program assigns sum to equal the sum of the for loop plus what I is. The program will then display the answer with a printf statement.
*/
	for(i=1;i<=100;i++)
		sum=sum+i;
	printf("The sum of the integers 1 through 100 is %d\n", sum);
/*
	This for loop will start at -1 and with the function, "i++," in it, the program will add -1 to each additional number until it reaches greater than or equal to -25. Then the program assigns sum to equal the sum of the for loop plus what "i" is. The program will then display the answer with a printf statement.
*/	
	sum=0; 
	for(i=-1; i>=-25; i--)
		sum=sum+i;
	printf("The sum of the integers -1 through -25 is %d\n", sum);
}



