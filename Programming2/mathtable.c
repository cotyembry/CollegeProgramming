#include<stdio.h>
#include<math.h>
/*
	Author: Coty Embry
	Course: CMPSC 1133, Computer Programming II
	Program Summary: this program will create a multiplication table. It will ask the user for the number ranging from 0 to 10 for the amount of rows and columns and make that number range from its negative form all the way to its positive form. The program will also prompt the user to enter the increments to increase by also.
	Input: command line, stdin
	Output: stdout
*/

int main(int argc, char *argv[]) {
	int N, inc, col, row, ans;

/*
	this if statement is saying if the enters two values from the command line, the program will scan and assing the first input to N and the second 		to inc. If there is only one integer or more than 3 the program will proceed with the else statement asking the user how many rows and columns 		they want.
*/
	if(argc==3) {
		sscanf(argv[1],"%d",& N);
		sscanf(argv[2],"%d",& inc);
}
	else {

		printf("How many columns and rows do you want? (Up to and including 0 through 10 is accceptable\n");
		scanf("%d",& N);
/*
		this while statement is putting in the criteria that while the number of rows and columns exceeds 10 or is less than 0, it will force the 			user to re-enter their values with error messages until the users selections satisfys the while loop. The program the re-scams and 			assigns the input to N. The program will then promnt the user to enter the increments that the table will increase by.
*/
		while((N>10) || (N<0)) {
			printf("Error: You can only enter between and including the integers 0 through 10 for the number of columns and rows\n");
			printf("How many columns and rows do you want? (Up to and including 10 is acceptable)\n");
			scanf("%d",& N);
}

		printf("What do you want the increments of the columns and rows to be? (Increments from, and including, 0 through 10 are acceptable)\n");
		scanf("%d",& inc);
}
/*
		this while loop is forcing the user to enter the numbers to satisfy it with error messages. It is setting the conditions that while inc 		is greater than 10 or less than 0 it will print an error message, re-ask the user for input, then scan and re-assign the input until the 			while loop is satisfied.
*/
		while((inc>10) || (inc<0)) {
			printf("Error: You can only make your increments go from and including 0 through 10\n");
			printf("What do you want the increments of the columns and rows to be?(Increments from, and including, 1 through 10 are 				acceptable)\n");
				scanf("%d",& inc);
}
	
/*
	this for loop is going to start the input for N the user entered in its negative number form and it is going to end at the positive form of the 	number and increase the numbers by the inc that the user input previously. The program will then print the rows of the numbers while formatting 	the table with 4 placeholders spaces and a tab after the number.
*/
	for(col=-N; col<=N; col=col+inc) {
		printf("\t%4d", col);
}
	printf("\n");		
	printf("\n");
/*
	this for loop is printing the rows out in the same form as the previous for loop except the variable is for the row.
*/
	for(row=-N; row<=N; row=row+inc) {
		printf("%4d\t", row);
/*		this for loop has to be inside of the row for loop to be able to allow the program to print the rest of the columns and rows with the 			calculation of the row times the column. The program will the print the answer with four placeholder spaces and a tab after that to 			format the table.
*/
		for(col=-N; col<=N; col=col+inc)
			printf("%4d\t", row*col);
		printf("\n");
}
/*
the program the enters a new line and exits the program
*/
printf("\n");
}
	


