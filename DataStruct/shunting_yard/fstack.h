#ifndef stack_h
#define stack_h
#define true 1
#define false 0
typedef int boolean;

typedef struct fstacknode {
	float data;
	struct fstacknode *next;
} *fstack;

void init_fstack(fstack *);

boolean is_ffull(void);

boolean is_fempty(fstack);

void fpush(fstack *, float);

float fpop(fstack *);

void print_fstack(fstack top);

#endif
