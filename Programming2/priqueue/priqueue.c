#include <stdio.h>
#include "priqueue.h"
#include <stdlib.h>
// This "init_queue" program is taking myqueue (pass by reference)
void init_priqueue(priqueue *mypriqueue) {
	// Allocating memory (while casting) for the size of the queuenode structure
	(*mypriqueue) = (priqueue) malloc (sizeof(struct priqueuenode));
	// Setting the myqueue variable pointer (front and back) both to NULL
	(*mypriqueue) -> front = NULL;
	(*mypriqueue) -> back = NULL;
}
// This "is_empty" program will return a boolean variable and take in the myqueue queue variable (pass by value)
boolean is_empty(priqueue mypriqueue) {
	// This is saying if bothe the front and back pointers point to NULL, the program will return the boolean value of true
	if (((mypriqueue) -> front == NULL) && ((mypriqueue) -> back == NULL))
		return true;
	// Otherwise it will return false (boolean value)
	else
		return false;
}
// is_full will return a boolean variable
boolean is_full() {
	// Declaring temp as a node_pointer variable
	node_pointer temp;
	// I'm checking to see after allocating memory, if temp still equals NULL
	temp = (node_pointer) malloc (sizeof(struct priqueuenode));
	// If so, true will be returned
	if (temp == NULL)
		return true;
	// Otherwise, false will be returned
	else
		return false;
}
// add will take in mypriqueue (pass by reference) and numadd (pass by value)
void add(priqueue *mypriqueue, userchoice data) {
	// I'm declaring temp as a node_pointer
	node_pointer temp, newnode;
	// I'm allocating enought memory for newnode. Without this, nothing will be able to be put into the program
	(newnode) = (node_pointer) malloc (sizeof(struct priqueuenode));	
	newnode -> data = data.userdata;
	newnode -> priority = data.priority;
			// This will call on is_empty and send mypriqueue. If that returns true, the program will continue on this if statment
			if	(is_empty(*mypriqueue)) {
				// This is setting the front and back of the priority queue to the newnode since there is only one node_pointer in the priqueue. I then set the backs next to NULL to avoid any errors in the future			
				(*mypriqueue) -> front = newnode;
				(*mypriqueue) -> back = newnode;
				(*mypriqueue) -> back -> next = NULL;	



}
			// Otherwise if there is things in the priqueue
			else {
				// This is if it belongs to the front. temp will be the front of the priqueue as well as newnode. the newnode's next will then be temp to properly patch the correct node_pointer in the priority queue
				if 	(newnode -> priority > (*mypriqueue) -> front -> priority) {
					temp = (*mypriqueue) -> front;
					(*mypriqueue) -> front = newnode;
					newnode -> next = temp;
}
				else {
					// This is if it belongs to the back. temp will now equal the mypriqueue's back pointer as well will the newnode. temps next will then equal the newnode and finally, once again to avoid any errors, the back of the priority queue will then equal NULL.
					if ((newnode -> priority) <= ((*mypriqueue) -> back -> priority)) {
						temp = (*mypriqueue) -> back;
						(*mypriqueue) -> back = newnode;
						temp -> next = newnode;
						(*mypriqueue) -> back -> next = NULL;
}
					else {
						// This is if it belongs to the middle due to it being the last option (since it didn't belong to the front or the back. I set temp to equal the front and implemented a while loop that while the newnode's priority is less than or equal to the temp's next priority temp will move up the priority queue little by little.
							temp = (*mypriqueue) -> front;
							while ((newnode -> priority) <= (temp -> next -> priority)) {
								temp = temp -> next;
}
						// If and when the while loop is fulfilled, the newnode's next will then equal the temps next and of course to properly patch the new node in properly, temp's next will then need to equal the newnode.
						newnode -> next = temp -> next;
						temp -> next = newnode;
}
}
}
}

// Fetch will return an integer, while bringing in myqueue (pass by reference)
int fetch (priqueue *mypriqueue) {
	// I declare data_fetched as an integer and temp as a node_pointer, then I have my own type of data which consists of the data portion and the priority portion of the users input.
	int data_fetched;
	node_pointer temp;
	userchoice data;

		// If myqueue pointers front equals back, I set a temp variable to equal the front of the priority queue then assign the data portion of the node_pointer
		if	((*mypriqueue) -> front == (*mypriqueue) -> back) {
			temp = (*mypriqueue) -> front;
			data_fetched = temp -> data;
			data.priority = temp -> priority;

			printf("#1 the priority = %d\n", data.priority);
			printf("#1 the data = %d\n", data_fetched);
			(*mypriqueue) -> front = NULL;
			(*mypriqueue) -> back = NULL;
			free (temp);

			// Then return data_fetched
			return data_fetched;
}
		// Otherwise
		else {
			// If the front and the back pointers do not equal the same thing
				temp = (*mypriqueue) -> front;
				(*mypriqueue) -> front = (*mypriqueue) -> front -> next;
				data_fetched = temp -> data;
				data.priority = temp -> priority;
				// Temp will be freed
				free (temp);
				// data_fetched will now be returned
				return data_fetched;

}
}
// print_queue will bring in myqueue (pass by value)
void print_priqueue(priqueue mypriqueue){
	// I am declaring temp as a node_pointer and data_portion as an integer
	node_pointer temp;
	int data_portion;
		// Im setting temp to be the front of the queuenode
		temp = mypriqueue -> front;
		// This is a while loop to make the program continue to print the data until temp equals NULL
		while (temp != NULL) {
			// This is setting the data_portion variable to be the data portion of the temp queuenode
			data_portion = temp -> data;
			// This is just printing the data_portion variable
			printf("%d\n", data_portion);
			// This is going to "walk up" the queuenodes until eventually temp equals NULL
			temp = temp -> next;
}
}
