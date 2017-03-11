#include<stdio.h>

/*
	AUTHOR:
		John Embry
		CMPSC 1113 - Computer Programming I

		PROGRAMMING COMMENT:
			This program will calculate how much change the user has in dollar, and cent amounts after the user tells it how many half dollars, quarters, dimes, nickels, and pennies the user has.

		INPUT: stdin

		OUTPUT:stdout
*/
int main (void) {
	int h,q,d,n,p, total;
	float value;
/*
	Throught this section the user will end in the prompts that are given. I.e. How many half dollars do you have? The user will put in "1" if that is all they have. However, if the user puts a negative integer in an error message will appear asking them to try again. 
*/
	printf("How many half dollars do you have?\n");
/*	All the printf function does is display that message inside the brackets for the user to see; that's what happens through out all of this section.
*/	
	scanf("%d",&h);
/*	What scanf does through out this section, is when the user enters an amount is, the  "%d" assigns the number to the letter at the end of the () mark as an integer.
*/
	while(h<0) {
		printf("Error: You can't have a negative number of coins, try again!\n");
		printf("How many half dollars do you have?\n");
		scanf("%d",&h);
}
/*	What the while function does through out this section is if the user puts an integer less than 0 an error message will appear - using the printf function - stating that they cannot have a negative number of coins, and to try again. It then asks the user the same question as before using another printf function, then scan the integer and assigns it to the letter at the end of the scanf function if the number is less that 0; if it isn't the same process as I have labeled above is repeated.
*/	
	printf("How many quarters do you have?\n");
	scanf("%d",&q);
	while(q<0) {
		printf("Error: You can't have a negative number of coins, try again!\n");
		printf("How many quarters do you have?\n");
		scanf("%d",&q);
}
	printf("How many dimes do you have?\n");
	scanf("%d",&d);
	while(d<0) {
		printf("Error: You can't have a negative number of coins, try again!\n");
		printf("How many dimes do you have?\n");
		scanf("%d",&d);
}
	printf("How many nickels do you have?\n");
	scanf("%d",&n);
	while(n<0) {
		printf("Error: You can't have a negative number of coins, try again!\n");
		printf("How many nickels do you have?\n");
		scanf("%d",&n);
}
	printf("How many pennies do you have?\n");
	scanf("%d",&p);
	while(p<0) {
		printf("Error: You can't have a negative number of coins, try again!\n");
		printf("How many pennies do you have?\n");
		scanf("%d",&p);
}
	total = h+q+d+n+p;
	value = 0.50*h+.25*q+0.10*d+0.05*n+0.01*p;
	printf("_________________________________________\n\n");	
/*
	This section displays how many half dollars, quarters, dimes, nickels, and pennies the user entered into the program. However, if the user enters a singular amount of coins, the program will printf to the screen in a singular form. If the user enters a plural amount of coins, the program will will printf in a plural form.
*/	
	printf("You entered the following amount of change:\n");	
/*	This printf function will display the message as literally; You entered the following amount of change:
	
	Below, when displaying the amount of coins the user entered, the if function gives the program two options for the printf: if the user enetered more than 1 coin, it will printf as a plural tense, if they entered equal to 1, it will printf in a singular tense. Also in the printf function, the 3 before the d in "%3d" means that it is giving the number three, "_ _ _," place holders.
*/
	if(h>1) {	
	printf("%3d half dollars\n",h);
}
	if(h==1) {
	printf("%3d half dollar\n",h);
}
	if(q>1) {
	printf("%3d quarters\n",q);
}	
	if(q==1) {
	printf("%3d quarter\n",q);
}
	if(d>1) {
	printf("%3d dimes\n",d);
}
	if(d==1) {
	printf("%3d dime\n",d);
}
	if(n>1) {
	printf("%3d nickels\n",n);
}
	if(n==1) {
	printf("%3d nickel\n",n);
}
	if(p>1) {
	printf("%3d pennies\n",p);
}
	if(p==1) {
	printf("%3d penny\n",p);
}
	printf("_________________________________________\n\n");
/*
	This displays and tells the user how many coins in singular or plural appreciation, whichever is needed, were entered as well as the total amount that they are worth.
*/	
	printf("These %d coins add up to a total of $%.2f\n", total, value);
}
/*	This printf function sums everything up assigning "total" to the %d; the amount of coins entered, and the "value" to %.2f. What the .2 in, %.2f does is it allows the program to display only two decimal places to the answer.
*/
