#include "complex.h"
#include "divide_complex.h"
#include <stdio.h>
#include "conjugate_complex.h"



// this is bringing in two of my own types and sending the answer back as my own type as well
complex divide_complex (complex num1, complex num2) {
// I declare these numbers as floats so the program can actually output the answer that I want in the printf statements below
float ans_real, ans_img;
int numer, denom;
	numer = multiply_complex (num1, conjugate_complex(num2));
	denom = multiply_complex (num2, conjugate_complex(num2));
	ans_real = (float)numer / denom;
	ans_img = (float)numer / denom;
/* this is setting the condition so that a person cannot divide by 0. If either the real part or img part of the answer is 0, an error message will appear. If not, the program will continue. */
	if ((num2.real == 0) && (num2.img == 0))
		printf("Error: division by 0");
// these if and else statements are strictly for formatting purposes.
	else {
		if (ans_img > 0)
			printf("%f + %f", ans_real, ans_img);
		else 
			printf("%f %f", ans_real, ans_img);
}
		
}
