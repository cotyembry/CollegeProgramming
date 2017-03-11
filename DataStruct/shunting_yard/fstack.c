#include "fstack.h"
#include <stdio.h>
#include <stdlib.h>

void init_fstack(fstack *s) {
	(*s) = NULL;
}

boolean is_ffull(void) {
	fstack temp;
	temp = (fstack) malloc (sizeof(struct fstacknode));
	if(temp == NULL)
		return true;
	else {
			free (temp);
			return false;
	}
}

boolean is_fempty(fstack s) {
	if(s == NULL)	
		return true;
	else
		return false;
}

void fpush(fstack *s, float numpush) {
	fstack temp;

	temp = (fstack) malloc(sizeof(struct fstacknode));

	temp -> data = numpush;
	temp -> next = (*s);
	(*s) = temp;
}

float fpop(fstack *s) {
	fstack temp;
	float data_popped;
	temp = *s;
	data_popped = temp -> data;
	*s = temp -> next;
	free (temp);
	return data_popped;
}

void print_fstack(fstack s) {

	if(!is_fempty(s)) {
		printf("\n%f\n\n", s -> data);
		print_fstack(s -> next);
	}
}
