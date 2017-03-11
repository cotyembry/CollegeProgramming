#include <stdio.h>
#include "queue.h"
/*	Author:		Coty Embry
	Date:		04/14/2013
	Class:		Computer Programming II
	Assignment:	Queue's
	Input:		stdin
	Output:		stdout
*/

// I'm delcaring a submenu program
int menu(void);
int main(void){
	// These are my variables I will use
	int selection, numadd, data_fetched;
	queue myqueue;
	selection = menu();
		// This is calling my init_queue program so it will start the front and back quenodes at NULL
		init_queue (&myqueue);
		// This will start my case's
		while (selection != 4) {
			// This is directing the program to the input the user intended to do
			switch (selection) {
						// This calls on the program is_full
				case 1:	if (is_full()) {
							// If the subprogram is true, this error message will appear
							printf("Error: Queue is full!\n");

}			
						// Otherwise the program will continue on and have the user enter a number then assign that number to a variable
						else {
							printf("Enter a number to add\n");
							scanf("%d", & numadd);
							// This calls on the program "add" and sends it the address of myqueue (pass by reference) and the value of the numadd variable
							add(&myqueue, numadd);

}
						// This ends the case
						break;
						// Just like case ones first if statement
				case 2:	if	(is_empty(myqueue)) {
							printf("Error: Queue is empty!\n\n");

}
						// Otherwise the program will call on "fetch" and bring back and assign what was fetched to data_fetched. The program will then print out the data_fetched variable
						else {
							data_fetched = fetch(&myqueue);
							printf("This was the data that was fetched: %d\n", data_fetched);

}
						break;
						// Just like case 1 and 2's first if statement
				case 3: if	(is_empty(myqueue)) {
							printf("Error: Queue is empty!\n");

}
						// This will call on "print_queue" and send with it myqueue
						else {
							print_queue(myqueue);

}
						break;
				// This is the default if the user doesn't enter an appropriate selection from the choices in the menu
				default:printf("%d is not a valid selection\n", selection);

						break;

}
		// After the cases go through with everything and the switch statement is done, the program will then call on the menu again to ask the user what they want to do
		selection = menu();
}
// If the user enters #4, the program will display this message and exit.
printf("Goodbye!\n");
}

// This is the menu of the program used by the case statements
int menu(void) {
	// I declare a variable
	int choice;
		// Display the options for the user
		printf("Enter a selection 1 through 4\n");		
		printf("1 Add\n");
		printf("2 Fetch\n");
		printf("3 Print\n");
		printf("4 Quit\n");
		// Assign the user's selection to a variable
		scanf("%d", & choice);
		// Then return the selection to go to the appropriate case
		return choice;
}



