# include <stdio.h>
# include <math.h>
/*
		AUTHOR:
		John Embry
		CMPSC 1113 - Computer Programming I

	
		PROGRAMMING COMMENT: This program will add two numbers, subtract two numbers, multiply two numbers, divide two numbers, find the absolute value of one number, find the square root of a number, and display the power of a number. It will also give error messages when trying to divide by 0, trying to take the square root of a negative number, trying to raise 0 to the 0 power, and if the user selects a 9 or above when the subprogram is called on.
			
		
		INPUT: stdin

	

		OUTPUT: stdout
*/
int menu(void);

int main(void) {
	int select, num1, num2, ans;
	float fans;
	select = menu();
/*	This while statement will give the user 7 different choices if the user inputs an integer that is not equal to 8. the switch statement pulls up the subprogram allowing the user to enter the numbers 1 through 8 to do a function. If greater than 8 an error message will appear.
*/	
	while (select != 8) {
		switch (select) {
/*	Each case allows the user to do a different math function; this first case is addition. The printf's through out this section will display to the screen what is inside the "" marks. 
*/
			case 1: printf("Enter 1st number: ");
				scanf("%d",&num1);
				printf("Enter 2nd number: ");
				scanf("%d",&num2);
				ans = num1 + num2;
/*	The num1, num2, ans on the printf is assigning those variables to the %d function. after the printf function, the selection = menu(); calls the submenu to display for the user to select the next section. This is repeated through out the next 6 cases.
*/
				printf("%d + %d = %d\n", num1, num2, ans);
				select = menu();				
/*	The break indicates the end of this particular method of math and moves to the next.
*/
				break;
/*	This case is for subtraction.
*/
			case 2: printf("Enter 1st number: ");
				scanf("%d", &num1);
				printf("Enter 2nd number: ");
				scanf("%d", &num2);
				ans = num1 - num2;
				printf("%d - %d = %d\n", num1, num2, ans);
				select = menu();
				break;
/*	This case is for multiplication.
*/
			case 3: printf("Enter 1st number: ");
				scanf("%d", &num1);
				printf("Enter 2nd number: ");
				scanf("%d", &num2);
				ans = num1 * num2;
				printf("%d * %d = %d\n", num1, num2, ans);
				select = menu();
				break;
/*	This case is for division. on line 63 it is giving an if statement; if the user enters a "0" as the second number to divide an error message will appear because it is not possible to divide by 0. The program will then call on the subprogram to allow the user to enter another function. The else statement on line 71 will take effect and calculate the solution if num2 is not 0.
*/
			case 4: printf("Enter 1st number: ");
				scanf("%d", &num1);
				printf("Enter 2nd number: ");
				scanf("%d", &num2);
				if(num2 == 0 ) {
					printf("Error: Cannot divide by 0\n");
					select = menu();
}
				else {
				fans = (float) num1 / num2;
				printf("%d / %d = %.2f\n", num1, num2, fans);
				select = menu();
}
				break;
/*	This case is for the absolute value of a number.
*/
			case 5: printf("Enter 1st number: ");
				scanf("%d", &num1);
				ans = abs (num1);
				printf("The absolute value of %d is |%d|\n", num1,ans);
				select = menu();
				break;
/*	This case is for the square root of a number. The if statement on line 89 will printf an error message if num1 is less than 0. The else statement on line 93 will solve the problem if the if statement is not true.
*/
			case 6: printf("Enter 1st number: ");
				scanf("%d", &num1);
				if(num1 < 0) {
					printf("Cannot take the square root of negative number!\n");
					select = menu();
}
				else {
				fans = sqrt(num1);
				printf( "%.2f\n", sqrt(num1));
				select = menu();
}
				break;
/*	This case is for the power of a number. the if statement on line 105 is giving a condition; both num1 and num2 has to equal 0 for the error message to come up. If the if statement is not true the else statement on line 109 will solve the problem as normal.
*/
			case 7: printf("Enter the Base: ");
				scanf("%d", &num1);
				printf("Enter the Power: ");
				scanf("%d", &num2);
				if((num2 == 0) && (num1 == 0)) {
					printf("%d ^ %d cannot be represented\n", num1, num2);
					select = menu();
}
				else {
				fans = (float) pow (num1, num2);
				printf("%d ^ %d = %.6f\n", num1, num2, fans);
				select = menu();
}
				break;	
/*	This default is if the user does not enter an integer from 1 through 8 then displays the submenu again to ask the user for input.
*/			
	
			default:printf("%d is not a valid selection\n", select);
			select = menu();

}

}
/*	If the user enters an 8 when the subprograms choices comes up, the program will printf "Bye!" to the screen and exit the program.
*/
printf("Bye!\n");
}

/*	This is the programs subprogram; everytime it is called in the program using the "selection = menu();" the list comes to the screen. Once the user enters in a number, the subprogram will read it in and assign the number to a particular case the program will then follow as shown above.
*/
int menu(void) {
	int choice;
	printf("1 Add\n");
	printf("2 Subtract\n");
	printf("3 Multiply\n");
	printf("4 Divide\n");
	printf("5 Absolute Value\n");
	printf("6 Square Root\n");
	printf("7 Powers\n");
	printf("8 Quit\n");
	printf("Enter a Selection: ");
	scanf("%d", &choice);
	return choice;
}
