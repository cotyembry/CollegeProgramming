#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
// This "init_queue" program is taking myqueue (pass by reference)
void init_queue(queue *myqueue) {
	// Allocating memory (while casting) for the size of the queuenode structure
	(*myqueue) = (queue) malloc (sizeof(struct queuenode));
	// Setting the myqueue variable pointer (front and back) both to NULL
	(*myqueue) -> front = NULL;
	(*myqueue) -> back = NULL;
}
// This "is_empty" program will return a boolean variable and take in the myqueue queue variable (pass by value)
boolean is_empty(queue myqueue) {
	// This is saying if bothe the front and back pointers point to NULL, the program will return the boolean value of true
	if (((myqueue) -> front == NULL) && ((myqueue) -> back == NULL))
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
	temp = (node_pointer) malloc (sizeof(struct queuenode));
	// If so, true will be returned
	if (temp == NULL)
		return true;
	// Otherwise, false will be returned
	else
		return false;
}
// add will take in myqueue (pass by reference) and numadd (pass by value)
void add(queue *myqueue, int numadd) {
	// I'm declaring temp as a node_pointer
	node_pointer temp;
	// I'm allocating enought memory for temp
	(temp) = (node_pointer) malloc (sizeof(struct queuenode));
			// This will call on is_empty and send myqueue. If that returns true, the program will set the data portion of temp to numadd, then make both myqueue front and back pointers to temp
			if	(is_empty(*myqueue)) {
				temp -> data = numadd;			
				(*myqueue) -> front = temp;
				(*myqueue) -> back = temp;
			
}
		// Otherwise if there is things in the queue
		else {
			// This if statement is checking to see if front and back myqueue pointers are the same. If they are, temp pointers data will be assigned to numadd. Then the last queuenode will now be temp and then the myqueue pointer back will then be pointing at temp
			if 	((*myqueue) -> front == (*myqueue) -> back) {
				temp -> data = numadd;
				(*myqueue) -> back -> next = temp;
				(*myqueue) -> back = temp;

}
			// Otherwise if front and back arent the same
			else {
				// If front and back are different
				if 	((*myqueue) -> front != (*myqueue) -> back) {
					// Temps data will now be numadd
					temp -> data = numadd;
					// The last queuenode will now become temp
					(*myqueue) -> back -> next = temp;
					// And the myqueue pointer back will be temp (the last thing in line)
					(*myqueue) -> back = temp;

}
}
}
}
// Fetch will return an integer, while bringing in myqueue (pass by reference)
int fetch (queue *myqueue) {
	// I declare data_fetched as an integer and temp as a node_pointer
	int data_fetched;
	node_pointer temp;
		// If myqueue pointers front equals back:
		if	((*myqueue) -> front == (*myqueue) -> back) {
			// Temp will become the front of the line
			temp = (*myqueue) -> front;
			// data_fetched will become the data portion of temp
			data_fetched = temp -> data;
			// The program will free temp
			free (temp);
			// Then return data_fetched
			return data_fetched;
}
		// Otherwise
		else {
			// If the front and the back pointers do not equal the same thing
			if	((*myqueue) -> front != (*myqueue) -> back) {
				// Temp will now equal the front of the line
				temp = (*myqueue) -> front;
				// The front will now be moved to the next queuenode
				(*myqueue) -> front = (*myqueue) -> front -> next;
				// data_fetched will equal the data portion of temp
				data_fetched = temp -> data;
				// Temp will be freed
				free (temp);
				// data_fetched will now be returned
				return data_fetched;
}
}
}
// print_queue will bring in myqueue (pass by value)
void print_queue(queue myqueue){
	// I am declaring temp as a node_pointer and data_portion as an integer
	node_pointer temp;
	int data_portion;
		// Im setting temp to be the front of the queuenode
		temp = myqueue -> front;
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
