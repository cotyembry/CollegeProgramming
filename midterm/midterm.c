#include <stdio.h>
#include <math.h>

/*	Author: Coty Embry
	Date:	03/12/2013
	Class:	Computer Programming II
	Program Comment:
		This program will allow the user to enter numbers and the operator only from the command line to solve any real number for addition, subtraction, multiplication, or division.
	Input:	stdin, command line
	Output: stdout
*/
// this is telling the program that there is input from the command line coming it, then I start to delcare my variables.
int main (int argc, char *argv[]) {
	char op;
	float num1, num2, fans;
	// this is say if the user enters three things, not including the a.out, it will convert the strings to variables and continue the program with the next criteria ahead
	if (argc == 4) {
		sscanf(argv[1], "%f", & num1);
		sscanf(argv[2], "%c", & op);
		sscanf(argv[3], "%f", & num2);
		// this is switching the program and directing it in the direction of what the user entered. If +, -, x, or /, is entered, the appropriate case will continue the program. Otherwise, an error message will appear and end the program.
		switch (op) {
			// this is if the user enters a + as the operator
			case '+':
						// this is the addition case, it is assigning the variable "fans" to equal the variables num1 + num2 then printing the answer out in two decimal point accuracy
						fans = num1 + num2;
						printf("%.2f + %.2f = %.2f\n", num1, num2, fans);
						break;
			// this is if the user enters a - as the operator
			case '-':
						// just like the addition, this is doing the same thing, but subtracting
						fans = num1 - num2;
						printf("%.2f - %.2f = %.2f\n", num1, num2, fans);
						break;
			// this is if the user enters a x as the operator
			case 'x':
						// just like the addtion and subtraction, this is doing the same thing except multiplying
						fans = num1 * num2;
						printf("%.2f x %.2f = %.2f\n", num1, num2, fans);
						break;
			// this is if the user enters a / as the operator
			case '/':
						// this is starting off the same way as the addition, subtraction, and multiplication, but then changes with an if statement. This is not allowing the user to divide by zero. If they choose that num2 equals 0, the program will display an error message, then end.
						fans = num1 / num2;
						if (num2 == 0) {
							printf("Error: cannot divide by zero!\n");
							break;
}
						// if the if statement is bypassed, then the program will continue as normal and solve the problem and printf to the screen with two decimal point accuracy
						else
							printf("%.2f / %.2f = %.2f\n", num1, num2, fans);
							break;
			default:
						// this is just the default for the switch statement that will give the user and error message if the user doesn't enter a +, -, x, or / character, then the program ends
						printf("Error: Invalid input for this form type!\n");
						break;
						
}
}
	// this if statement is going to direct the program to assume the user entered in an operator and then a number. It will use sscanf's to then convert the input and assign it to a variable.
	if (argc == 3) {
		sscanf(argv[1], "%c", & op);
		sscanf(argv[2], "%f", & num1);
		// just like above, this is switching to what the user entered into as the operator
		switch (op) {
			// this is if the user enters a 'n' as the operator
			case 'n':
						// this will just multiply the num1 varible and make the new varible fans
						fans = num1 * -1; 
						printf("-1 x %.2f = %.2f\n", num1, fans);
						break;
			// this is if the user enters a 'a' as the operator
			case 'a':
						// this will take the absolute value of the variable num1 and assign it to the new variable fans then print the answer in two decimal point accuracy
						fans = fabs (num1);
						printf("The absolute value of |%.2f| is %.2f\n", num1, fans);
						break;
			// this is if the user enters a 's' as the operator
			case 's':
						// this if statement will now allow the user to take the square root of a negative number. If num1 happens to be negative, an error message will appear then the program will end
						if(num1 < 0) {
							printf("Cannot take the square root of negative number!\n");
							break;
}
						else
							// if num1 doesn't equal 0, then the program will solve for the square root of num1, assign the new answer to the variable fans and then print out the answer using two decimal point accuracy
							fans = sqrt(num1);
							printf( "Sqrt (%.2f) = %.2f\n", num1, fans);
							break;
			default:
						// this will occur if the user doesn't enter a 'n', 'a', or 's'. It will display an error message then end the program.
						printf("Error: Invalid input for this form type!\n");
						break;
}
}
	// these two if statements are just going to display an error message to the user if they do not put in the correct number of inputs for a form type
	if (argc < 3) {
		printf("Input error!!!\n");
}
	if (argc > 4) {
		printf("Input error!!!\n");
}
}
