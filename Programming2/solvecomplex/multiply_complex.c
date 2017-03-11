#include "complex.h"
#include "multiply_complex.h"

// this is bringing in and declaring num1 and num2 as complex numbers and sending back a complex type (ans)
complex multiply_complex (complex num1, complex num2) {
complex ans;
		ans.real =  num1.real * num2.real - (num1.img * num2.img);
		ans.img = num2.real * num1.img - (num1.real * num2.img);
// this is returning the answer to the main program
		return ans;
}

