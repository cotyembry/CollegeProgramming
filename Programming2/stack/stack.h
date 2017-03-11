#ifndef boolean_h
#define boolean_h
#define true 1
#define false 0
typedef int boolean;
#endif
// This is defining my stacknode structure. It is saying the first part of it is an integer that holds data. The second part of it is a structure that is a stacknode which in turn points to the next thing at in line using pass by reference.
typedef struct stacknode {
	int data;
	struct stacknode *next;
} *stack;
// The rest of these are prototypes using the ifndef #define endif functions so there are no compiling errors. Some of these prototypes take data in, some send it out. Others, do both. 
#ifndef init_stack_h
#define init_stack_h
void init_stack(stack *);
#endif

#ifndef is_full_h
#define is_full_h
boolean is_full(void);
#endif

#ifndef is_empty_h
#define is_empty_h
boolean is_empty(stack);
#endif

#ifndef push_h
#define push_h
void push(stack *, int);
#endif

#ifndef pop_h
#define pop_h
int pop(stack *);
#endif

#ifndef print_stack_h
#define print_stack_h
void print_stack(top);
#endif
