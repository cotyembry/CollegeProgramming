#include <stdio.h>

/*
	AUTHOR:
		John Embry
		CMPSC 1113 - Computer Programming I

	
		PROGRAMMING COMMENT: This program will generate how ever many numbers the user wants between the quantity of 2 numbers through 10,000 numbers.
			
		INPUT: stdin


		OUTPUT:stdout
*/

/*	The randu, bubble, and swap are being declared into the program. In the main program, i, num, and x[10000] <-- that's an array- , are being declared.
*/
int randu(void);
void bubble(int*, int);
void swap(int*, int*);
/*	The printf is asking the user to enter how many random numbers they want, and the scanf statement is assingning the users input to num. The while statement is declaring that while num is less than 2 or greater than 10000, to display an error message prompting the user to enter how many random numbers they want again.
*/
int main (void) {
	int i, num, x[10000];
	printf("Enter how many random numbers do you want: ");
	scanf("%d",& num);
		while((num < 2) || (num > 10000)) {
			printf("Error: Enter a number between 2 and 10,000.\n");
			printf("Enter how many random numbers do you want: ");
			scanf("%d",& num);
}
/*	The for loop is assigning random numbers into the array, then the program calls on bubble to sort the numbers from ascending order. The printf then dispays the numbers to the screen.
*/
	for (i=0; i<num; i++)
		x[i] = randu();
	bubble(x, num);
	for (i=0; i<num; i++)
		printf("%d ", x[i]);
	printf("\n");
}
/*	This subprogram is giving the program a formula allowing the program to generate "random numbers." The static int is making the subprogram re-use the same number that was just calculated rather than starting back to the 17 that was assigned to try and give a true random number feel to the program. The return is then returning the calculations back to the program.
*/
int randu() {
	static int seed = 17;
	seed = (25179*seed+13849)%65536;
	return seed;
}
/*	Bubble is bringing int x[] and int n into the program, then it is declaring the i as an integer and j as an integer. The for loops are setting conditions for i and what to do if the calculation after the loop is done allowing the numbers to be sorted in ascending order.
*/
void bubble(int x[], int n) {
	int i,j;
		for (i=0; i<n-1; i++)
			for (j=n-1;i<j;j--)
				if(x[j-1]<x[j])
					swap(&x[j-1],&x[j]);
}
/*	Swap is pointing to a and b allowing those two numbers to be switched out with eachother. The temp variable is allowing for storage while the numbers are being switched.
*/
void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
