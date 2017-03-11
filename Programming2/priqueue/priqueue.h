#ifndef priqueue_h
#define priqueue_h

#define true 1
#define false 0
typedef int boolean;

typedef struct {
	int userdata;
	int priority;
} userchoice;

typedef struct priqueuenode {
	int data;
	int priority;
	struct priqueuenode *next;
} *node_pointer;

typedef struct endpointer {
	node_pointer front;
	node_pointer back;
} * priqueue;

void init_priqueue(priqueue *);

boolean is_full(void);

boolean is_empty(priqueue);

void add(priqueue *, userchoice);

int fetch(priqueue *);

void print_priqueue(priqueue);

#endif
