#include "complex.h"
#include "conjugate_complex.h"

// this is bringing in two of my own types and sending the answer back to the main program

complex conjugate_complex (complex num1) {
complex ans;
		ans.img = -1 * num1.img;
// this is returning the answer back to the main program
	return ans;
}
