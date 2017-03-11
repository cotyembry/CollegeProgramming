#include "cstack.h"
#include <stdlib.h>
#include <stdio.h>

void init_cstack(cstack *s) {
	(*s) = NULL;
}

boolean is_cfull(void) {
	cstack temp;
	temp = (cstack) malloc (sizeof(struct cstacknode));
	if(temp == NULL)
		return true;
	else {
			free (temp);
			return false;
	}
}
boolean is_cempty(cstack s) {
	if(s == NULL)
		return true;
	else
		return false;
}
void cpush(cstack *s, char charpush) {
	cstack temp;
	if(is_cfull()) {
		printf("sorry, the stack is full!\n");
	}
	else {
	temp = (cstack) malloc(sizeof(struct cstacknode));	
	temp -> data = charpush;
	temp -> next = (*s);
	(*s) = temp;
	}	
}

char cpop(cstack *s) {
	cstack temp;
	char data_popped;
	temp = *s;
	data_popped = temp -> data;
	*s = temp -> next;
	free (temp);
	return data_popped;
}
void print_cstack(cstack s) {
	if(!is_cempty(s)) {
		printf("data printed: %c\n", s -> data);
		print_cstack(s -> next);
	}
	else
		printf("Stack is empty\n");
}
