#ifndef queue_h
#define queue_h

#define true 1
#define false 0
typedef int boolean;

typedef struct queuenode {
	int data;
	struct queuenode *next;
} *node_pointer;

typedef struct endpointer {
	node_pointer front;
	node_pointer back;
} * queue;

void init_queue(queue *);

boolean is_full(void);

boolean is_empty(queue);

void add(queue *, int);

int fetch(queue *);

void print_queue(queue );

#endif
