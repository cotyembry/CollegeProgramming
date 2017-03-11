#include <stdio.h>
#include "write_complex.h"

// this is bringing in my own type and printing the answer as a real and imaginary part. It is not sending back anything however

void write_complex (complex ans) {

	printf("%d + %di\n", ans.real, ans.img);
	printf("To toggle menu on and off press: 7 then enter\n");
}
