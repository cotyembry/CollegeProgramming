// NEW!
#include <stdio.h>
#include <math.h>
#include "solvecomplex.h"
/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II
*/
/* This is bringing in the values a,b,and c, into the program and then the program delcares the variables x1real, x1imaginary, x2real, and x2imaginary, as floats */
void
solvecomplex (int a, int b, int c)
{
  float x1real, x1imaginary, x2real, x2imaginary;
/* this is calculating the real number value for the x1 then it calculates the imiganary value for x1, and it does the same for x2 */
  x1real = -b / (float) (2 * a);
  x1imaginary = (+sqrt (abs ((b * b) - 4 * (a * c)))) / (float) (2 * a);
  x2real = -b / (float) (2 * a);
  x2imaginary = (-sqrt (abs ((b * b) - 4 * (a * c)))) / (float) (2 * a);
/* this then prints the real + (or -) the imaginary value of the calculation */
  printf ("%.2f + %.2fi\n", x1real, x1imaginary);
  printf ("and\n");
/* this if and else statement is making it where if the program produces a number greater than or equal to 0 for the  imaginary number, it will just display the real number + the imaginary number, otherwise it will just display the real number - the imaginary number */
  if(x2imaginary <= 0)
	  printf ("%.2f %.2fi\n", x2real, x2imaginary);
  else
	  printf("%.2f %.2fi\n", x2real, x2imaginary);
}
