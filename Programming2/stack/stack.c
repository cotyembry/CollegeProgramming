#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
// I included the stack.h due to me referencing that program, the stdio due to using printf's, and the stdlib.h due to me using malloc commands.
// From here down are the program definitions.
// This is just making it where the stack is pointing to NULL at the start so there isn't any errors that could occur when starting the stack program out.
void init_stack(stack *s) {
	(*s) = NULL;
}
// This is a boolean function that will use the malloc function to check and see if there is enough memory in the program. If so, the program will return the true boolean variable. Else it will return the false boolean variable after freeing the temporary data from the program.
boolean is_full(void) {
	stack temp;
	temp = (stack) malloc (sizeof(struct stacknode));
	if(temp == NULL)
		return true;
	else {
			free (temp);
			return false;
	}
}
// This is a boolean variable that brings in a stack variable. It will allow the program to see if there is anything in the stack by returning if it is true or false by checking the if s == NULL condition.
boolean is_empty(stack s) {
	if(s == NULL)	
		return true;
	else
		return false;
}
// This prototype is bringing in a stack variable via pass by reference and an integer via pass by value.
void push(stack *s, int numpush) {
	// This is setting declaring a stack type variable (data portion, and pointer portion)
	stack temp;
	// Then it allocates enough memory to be able to take in the data
	temp = (stack) malloc(sizeof(struct stacknode));
	// Now in these next three steps the program is setting the new top of the stack as the temp variable, reassigning the "use to be top of the stack" to the second in line now.
	temp -> data = numpush;
	temp -> next = (*s);
	(*s) = temp;
}
// This simply removes the top of the stack, creates a stack temp variable to be able to hold that which was removed, reassignes the second in line to the top once again, then returnes the data that was removed.
int pop(stack *s) {
	stack temp;
	int data_popped;
	temp = *s;
	data_popped = temp -> data;
	*s = temp -> next;
	free (temp);
	return data_popped;
}
// This uses recursion by calling on its self inside of its own program to print the stack out to the user. It brings in the variable s (which is a stack variable).
void print_stack(stack s) {
	// This if statement is to check and see if the program is empty or not. If it is, there would be nothing to print of course. Then it prints by point the stack s variable towards the data then uses recursion by calling on its self to go to the next in line stack data.
	if(!is_empty(s)) {
		printf("%d\n", s -> data);
		print_stack(s -> next);
	}
}
