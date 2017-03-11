#include "complex.h"
#include "add_complex.h"

// this is bringing in two of my own types and sending out my own types
complex add_complex (complex num1, complex num2) {
complex ans;
		ans.real = num1.real + num2.real;
		ans.img = num1.img + num2.img;
// this is returning the answer to the main program
		return ans;
//this is telling the program to stop this selection
		
}
