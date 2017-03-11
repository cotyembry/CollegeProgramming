#include "complex.h"
#include "negate_complex.h"
// this is bringing in two of my own types and sending my own type back
complex negate_complex (complex num1, complex num2) {
complex ans;
		ans.real = -1 * num1.real;
		ans.img = -1 * num1.img;
// this is returning the answers back to the main program
	return ans;
}
