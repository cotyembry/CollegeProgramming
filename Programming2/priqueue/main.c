// Im working on add. 

#include <stdio.h>
#include "priqueue.h"
/*	Author:		Coty Embry
	Date:		04/14/2013
	Class:		Computer Programming II
	Assignment:	Queue's
	Input:		stdin
	Output:		stdout
	Program Comment: This program will make a Priority queue that will assign numbers to a standard queue, but it goes by the priority in the list in order of greatest appearance.
*/

// I'm delcaring a submenu program
int menu(void);
int main(void){
	// These are my variables I will use
	int selection, numadd, data_fetched, x;
	priqueue mypriqueue;
	userchoice data;
	selection = menu();
		// This is calling my init_queue program so it will start the front and back quenodes at NULL and send it mypriqueue to be able to change it
		init_priqueue (&mypriqueue);
		// This will start my case's. if the user enters something not 4, the program will switch to the selection of the cases I have written
		while (selection != 4) {
			// This is directing the program to the input the user intended to do because it brings the integer from the menu, hence selection = menu();
			switch (selection) {
						// This calls on the program is_full
				case 1:	if (is_full()) {
							// If the subprogram is true, this error message will appear
							printf("Error: Priority Queue is full!\n");

}			
						// Otherwise, if false, the program will continue on and have the user enter a number then assign that number to a variable
						else {
							printf("Enter a number to add\n");
							// I am using a typedef to send more than two things through the program and I'm assigning the information the user wants to the correct part of the data's typedef portion
							scanf("%d", & data.userdata);
							printf("What is your number's priority?\n");
							scanf("%d", & data.priority);
							// This calls on the program "add" and sends it the address of myqueue (pass by reference) and the value of the numadd variable
							add(&mypriqueue, data);

}
						// This ends the case
						break;
						// Just like case ones first if statement
				case 2:	if	(is_empty(mypriqueue)) {
							printf("Error: Priority Queue is empty!\n\n");

}
						// Otherwise the program will call on "fetch" and bring back and assign what was fetched to data_fetched. The program will then print out the data_fetched variable
						else {
							data_fetched = fetch(&mypriqueue);
							x = data_fetched;
							printf("This was the data that was fetched: %d\n", x);

}
						break;
						// Just like case 1 and 2's first if statement
				case 3: if	(is_empty(mypriqueue)) {
							printf("Error: Priority Queue is empty!\n");

}
						// This will call on "print_queue" and send with it myqueue
						else {
							print_priqueue(mypriqueue);

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




