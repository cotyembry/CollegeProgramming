#include "complex.h"
#include "subtract_complex.h"

// this is bringing in two of my own types, calculating an answer, then sending the answers back to the main program.

complex subtract_complex (complex num1, complex num2) {
complex ans;
		ans.real = num1.real - num2.real;
		ans.img = num1.img - num2.img;
// this is returning the answers to the main program
		return ans;
}
