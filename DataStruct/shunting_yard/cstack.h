#ifndef cstack_h
#define cstack_h
#define true 1
#define false 0
typedef int boolean;
typedef struct cstacknode {
	char data;
	struct cstacknode *next;
} *cstack;
void init_cstack(cstack *);
boolean is_cfull(void);
boolean is_cempty(cstack);
void cpush(cstack *, char);
char cpop(cstack *);
void print_cstack(cstack);
#endif
