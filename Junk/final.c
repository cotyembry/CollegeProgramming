#include <stdio.h>

typedef struct mynode {
	int p1;
	float p2;
	char p3;
} *mytype;

int main (void) {
(*mytype) -> p1 = 2;
(*mytype) -> p2 = 2.3;
(*mytype) -> p3 = coty;

printf("%d, %f, %c\n", mynode.p1, mynode.p2, mynode.p3);

}
