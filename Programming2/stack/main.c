#include "stack.h"
#include <stdio.h>
/*	Author: 	Coty Embry
	Date: 		04/08/2013
	Class: 		Computer Programming II
	Assignment:	Stacks
	Input:		Stdin
	Output:		Stdout
	Program Comment: This program is a menu driven program that will allow the user to push, pop, and print data from a stack program. If the user wants a new number in the stack, they can use the push option. This will just shift all of the data from one stack down one to make room for the new stack with data. If the user wants to remove data (just one at a time) the will use the pop command the exact opposite as the push command would take effect.
*/

// I am declaring that there is a submenu which brings in a integer, but sends nothing out.
int menu (void);
int main (void) {
// I am declaring different integers to use here.
int numpush, selection, data_popped;
int x;

selection = menu();
stack top;
// This is initializing the stack which will set the top of the stack to NULL to avoid any errors.
init_stack(&top);
// This while loop will take in effect if the user does not enter quite (the options to use for the integers are 1, 2, 3, and 4.
while (selection != 4) {
	// This will display a menu for the user to choose from. Depending on their input (through out this section it will be the integers of 1 through 4) it will go along with the appropriate case.
	switch (selection) {
		// This case is to push a number to the stack
				// This if statement will call on another program to check to see if the program is full. If it is true, the program will display an error message and the re-display the menu.
		case 1: if 	(is_full()) {
					printf("Error: Stack is full\n");
					selection = menu();
}				// This is the else to the if; if the program is not full, the program will prompt the user to enter a number to push, then it will assignt that integer to a variable named "numpush" then it will call on the push program sending it that variable. It will then re-display the menu.
				else {
					printf("Enter a number to push \n");
					scanf("%d", & numpush);
					push(&top, numpush);
					selection = menu();
}				// This ends the Case 1.
				break;
		// This case is to pop a number from the stack.
				// This if statement will check to see if the program is empty. If it is, it will display an error saying the stack is empty the display the menu.
		case 2: if 	(is_empty(top)) {
					printf("Error: Stack is empty\n");
					selection = menu();
					
}				// Otherwise the program assigns a varible x to equal the what comes back from pop.
				else {
					x = pop(&top);
					// This printf statment will then use that variable to display the number that was popped.
					printf("This is the number that was popped: %d\n", x);
					// The program will then display the menu again.
					selection = menu();
}				// This ends case 2
				break;
		// This case will print the stack.
				// This if statement will check to see if the program is empty. If it is, it will display an error saying the stack is empty the display the menu.
		case 3: if 	(is_empty(top)) {
					printf("Stack is empty\n");
					selection = menu();
}				// Otherwise it will call on the program print_stack (which in turn will print the stack) and display the menu.
				else
					print_stack(top);
					selection = menu();
				// This ends case 3
				break;
		// This case is the case that will end the program for the user. I used return 0 due to that being a boolean value that ends the program. THIS IS NOT PART OF THE WHILE LOOP!
		case 4: return 0;
		// This is the default "case" if you will, that will take effect if the user does not enter the appropriate integers. I.e. 1, 2, 3, 4. The program will the display the menu.
		default:printf("%d is not a valid selection\n", selection);
				selection = menu();
}
}
}

// This is the subprogram which will display the menu to guide the program to the appropriate case in main.
int menu(void) {
	// This is declaring that there is an integer named choice.
	int choice;
		// These printf's are what the user will see.
		printf("Enter a selection 1 through 4\n");		
		printf("1 Push\n");
		printf("2 Pop\n");
		printf("3 Print\n");
		printf("4 Quit\n");
		// This will convert and assign the input from the user to the choice variable.
		scanf("%d", & choice);
		// The program will then return choice to use the input from the user.
		return choice;
}
