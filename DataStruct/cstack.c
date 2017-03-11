/*	Author:	Coty Embry
	Date:	8/27/2013
	Class:	Data Structures
	Program Comment: This program will automatically push numbers 1, 2, 3, 4, and 5 on a stack, then pop them off 1 by one while printing the results to the screen.
	Instructor:	Ms. Tarver
	Input: 	stdin
	Output:	stdout
*/
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int boolean;
typedef struct cstacknode {
	char data;
	struct cstacknode *next;
} *cstack;
void init_cstack(cstack *);
boolean is_full(void);
boolean is_empty(cstack);
void push(cstack *, char);
char pop(cstack *);
void print_cstack(cstack);

char main (void) {
	char charpush, data_popped, x;
	cstack top;
	init_cstack(&top);
//	need to use gets function here to get the string		for(charpush = 1; charpush < 6; charpush ++) 
			charpush = x;
			printf("%c\n", charpush);
			push(& top, charpush);
			printf("data pushed: %c\n", charpush);
			printf("\n");

	data_popped = pop(&top);
		printf("\ndata popped: %c\n", data_popped);
	data_popped = pop(&top);
		printf("\ndata popped: %c\n", data_popped);
	data_popped = pop(&top);
		printf("\ndata popped: %c\n", data_popped);
	data_popped = pop(&top);
		printf("\ndata popped: %c\n", data_popped);
	data_popped = pop(&top);
		printf("\ndata popped: %c\n", data_popped);
	if(is_empty(top))
		printf("\nthe stack is now empty\n");
}


void init_cstack(cstack *s) {
	(*s) = NULL;
}

// This is a boolean function that will use the malloc function to check and see if there is enough memory in the program. If so, the program will return the true boolean variable. Else it will return the false boolean variable after freeing the temporary data from the program.
boolean is_full(void) {
	cstack temp;
	temp = (cstack) malloc (sizeof(struct cstacknode));
	if(temp == NULL)
		return true;
	else {
			free (temp);
			return false;
	}
}
// This is a boolean variable that brings in a stack variable. It will allow the program to see if there is anything in the stack by returning if it is true or false by checking the if s == NULL condition.
boolean is_empty(cstack s) {
	if(s == NULL)	
		return true;
	else
		return false;
}
// This prototype is bringing in a stack variable via pass by reference and an integer via pass by value.
void push(cstack *s, char charpush) {
	// This is setting declaring a stack type variable (data portion, and pocharer portion)
	cstack temp;
	if(is_full()) {
		printf("sorry, the stack is full!\n");
	}
	else {
	// Then it allocates enough memory to be able to take in the data
	temp = (cstack) malloc(sizeof(struct cstacknode));
	// Now in these next three steps the program is setting the new top of the stack as the temp variable, reassigning the "use to be top of the stack" to the second in line now.
	temp -> data = charpush;
	temp -> next = (*s);
	(*s) = temp;
}
}
// This simply removes the top of the stack, creates a stack temp variable to be able to hold that which was removed, reassignes the second in line to the top once again, then returnes the data that was removed.
char pop(cstack *s) {
	cstack temp;
	char data_popped;
	temp = *s;
	data_popped = temp -> data;
	*s = temp -> next;
	free (temp);
	return data_popped;
}
// This uses recursion by calling on its self inside of its own program to print the stack out to the user. It brings in the variable s (which is a stack variable).
void print_cstack(cstack s) {
	// This if statement is to check and see if the program is empty or not. If it is, there would be nothing to print of course. Then it prints by point the stack s variable towards the data then uses recursion by calling on its self to go to the next in line stack data.
	if(!is_empty(s)) {
		printf("%c\n", s -> data);
		print_cstack(s -> next);
	}
}
