# include <stdio.h>
# include <math.h>
/*
		AUTHOR:
		John Embry
		CMPSC 1113 - Computer Programming I

	
		PROGRAMMING COMMENT: This program will simply add the sum of two real numbers. If the user enters only one number on the command line the program will prompt the user to enter the second number. If the user enters two numbers on the command line, the order they are in is how the calculation will be. I.e. if the user enters 3 and -4 on command line the answer will be -1. If the user enters three numbers, the program will display an error message and ask the user what their first and second number is, then do the calculation.
		
		INPUT: stdin

	

		OUTPUT: stdout
*/

/*	This is delcaring the program is taking an integer from the command line - argc is how many integers there is - and argv is what the integers are, but they are only strings at this stage in the program. The line under that, num1, num2, and ans are being delcared as real numbers.
*/
int main(int argc,char *argv[]) {
float num1, num2, ans;


/*	Throught this section of the program the if statements are telling the program which path to follow.
	
	The first if statment is saying if argc - the actual number of integers is on the command line - is greater than 3, the program will display an error message then prompt the user to enter the numbers they want added with two printf's. The first scanf is assigning the number the user enters to num1, the second scanf is assinging the number to num2; num1 + num2 is the calculation that will happen and the = ans is assigning the answer to "ans." Below that the printf is displaying the answer to the user is two decimal accuracy by using the %.2f conversion character. After the quotations, each %.2f is getting assigned which number goes to which conversion by left to right order, and they are being seperated by commas.
*/
	if(argc > 3) {
		printf("Error: Can only be two numbers!\n");
		printf("What is your first number: ");
		scanf("%f",& num1);
		printf("What is your second number: ");
		scanf("%f",& num2);	
		ans = num1 + num2;
		printf("%.2f + %.2f = %.2f", num1, num2, ans);
}
/*	The only thing different from this if statement is if argc is equal to 3 the program will convert the strings from the command line. The first sscanf is converting the first integer "argv[1]" to a real number and assigning it to num1. The second sscanf is converting the second integer "argv[2]" to a real number and assigning it to num2. 
*/
	if((argc == 3)) {
		sscanf(argv[1],"%f",& num1);
		sscanf(argv[2],"%f",& num2);
		ans = num1 + num2;
		printf("%.2f + %.2f = %.2f", num1, num2, ans);
}
/*	This if statment is going to be used if the command line only recieves one integer. It will convert the first integer it recieves using the sscanf to a real number and will assign it to num1. The program will then prompt the user to enter their second number with a printf. After the printf, the scanf is use to assign the user's input to num2 using the &. After all of that happens, the program sets the condition num1 + num2 is the calculation that will happen and the = ans is assigning the answer to "ans." Below that the printf is displaying the answer to the user is two decimal accuracy by using the %.2f conversion character. After the quotations, each %.2f is getting assigned which number goes to which conversion by left to right order, and they are being seperated by commas.
*/
	if(argc == 2) {
		sscanf(argv[1],"%f",& num1);
		printf("What is your second number: ");
		scanf("%f",& num2);
		ans = num1 + num2;
		printf("%.2f + %.2f = %.2f", num1, num2, ans);
}
/*	This if statement will be used if the program gets no input from the user. It will display two printf statements to prompt the user on what to enter. The scanf statements will assign the input to the variables. The conditon of num1 + num2 is being set and that answer will then be assigned to the variable, "ans." Then the program will display the answer in two decimal accuracy. 
*/
	if(argc == 1) {
		printf("What is your first number: ");
		scanf("%f",& num1);
		printf("What is your second number: ");
		scanf("%f",& num2);
		ans = num1 + num2;
		printf("%.2f + %.2f = %.2f", num1, num2, ans);
}
/*	This last printf is just to allow the command line to go to a new line.
*/
	printf("\n");
}	
