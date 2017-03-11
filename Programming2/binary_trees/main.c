#include "binary_tree.h"
#include <stdio.h>
/*	Author:		Coty Embry
	Date:		04/26/2013
	Class: 		Programming II
	Professor:	Ms. Tarver
	Program Comment: This program is a Binary Tree that will operate as a menu driven program for the user. It will ask for a number, then compare the number that is at the top of the tree. If the new number to add is greater than the current treenode, the number will go to the right side of the Binary Tree, if it is less than or equal to it, it will go to the left. The user will be able to delete a number from the tree of their choice. If the number exists the program removes, and re-patches the tree so no other data is lost. If the number does not exist, an error message will be given. The user also has two options to print the numbers that are in the tree. They can print them in Ascending order, or Descending order.
*/
int menu (void);
int main (void) {
	// I am declaring my variables to use later in the program. root is a binary_tree which is a structure that consists of a left and right pointer. it also contains a data portion which is an integer. My own type "binary_tree" is a pointer which consists of what I just described what root is.
	binary_tree root;
	int numadd, numdelete, selection;
	// I am declaring a there is going to be a menu on this program.
	selection = menu();
		// This initializes the binary tree. It sends the address of root (a binary_tree structure) to be able to change it. In the init_binary_tree function it sets root to NULL.
		init_binary_tree (&root);
		// This while loop will continue until on until the user enters 5 in the menu.
		while (selection != 5) {
			// The program then switches to the users selection which is returned from the sub menu below
			switch (selection) {
				// This will happen if the user enters "1" in the menu
						// The program calls on the is_full program. This program will return a true or false boolean value. If is_full returns true, the program will display an error message.
		/*Add*/	case 1:	if (is_full ()) 
							printf("Error: Binary Tree is full!\n");
						// If the is_full returns the false boolean value, the program will ask, then assign the integer to numadd. Then it sends the address of root (because it is going to be changed, and numadd (the number we just got from the user) to add_binary_tree
						else {
							printf("What number do you want to add?\n");
							scanf("%d", & numadd);
							add_binary_tree (&root, numadd);
						}
						// This break will end this case and stop the switch statement
						break;				
				// This will happen if the user enters "2" in the menu
						// The program will call on the is_empty program sending root pass by value because it is just looking at it. is_empty will return a true or false boolean value. If it returns a true value, an error message will display
	/*Delete*/	case 2:	if	(is_empty(root))
							printf("Error: Binary Tree is empty\n");
						// If the is_empty program returns a false boolean value, the program will ask the user for an integer they wish to delete. The program will assign that integer to numdelete 
						else {
							printf("What number do you want to delete?\n");
							scanf("%d", & numdelete);
							// The program will call on delete_binary_tree sending the address of root (because it is going to be changed) and numdelete (the number we just got from the user)
							delete_binary_tree (&root, numdelete);
						}
						// This break will end this case and stop the switch statement
						break;
				// LNR (Prints in Ascending Order)
						// This will call on the LNR program sending root pass by value because it is not going to be changed. It is just being looked at.
/*Ascending*/	case 3:	LNR (root);
						break;
				// RNL (Prints in Descending Order)
						// This will call on the RNL program sending root pass by value because it is not going to be changed. It is just being looked at.
/*Descending*/	case 4:	RNL (root);
						// This break will end this case and stop the switch statement
						break;
				// This is the default that the switch statement will go to if the user doesn't enter: 1, 2, 3, 4, or 5
				default:	printf("Error: That is not a valid selection!\n");
							// This break will end this case and stop the switch statement
							break;
			}
	// After the case from the switch statement hits the "break;" and ends the case, 
	selection = menu ();
}
	// If the user enters a 5, that selection will pass the while loop and get to this printf statement. The program will then end
	printf("Bye!\n");
}

int menu (void) {
	int choice;
		printf("\nPlease make a selection, then press enter\n");
		printf("1 Add\n");
		printf("2 Delete\n");
		printf("3 LNR (Ascending Order)\n");
		printf("4 RNL (Descending Order)\n");
		printf("5 Quit\n");
		scanf("%d", & choice);
		return choice;
}
