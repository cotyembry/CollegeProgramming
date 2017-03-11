#include "complex.h"
#include <stdio.h>
// this is not bringing anything into the program, but it is sending my own type back to the main program
complex read_complex (void) {
// this is setting x as my own type, called "complex"
	complex x;
	printf("Enter real part: ");
	scanf("%d", & x.real);
	printf("Enter imaginary part: ");
	scanf("%d", & x.img);
// this is returning x to the main program
	return x;
}
