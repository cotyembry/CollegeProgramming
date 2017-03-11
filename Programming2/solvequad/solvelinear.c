// NEW!
#include <stdio.h>
#include <math.h>
#include "solvelinear.h"
/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II
*/
// this is bringing the variable values of b and c into the program, then the program declares x as a float
void
solvelinear (int b,int c)
{
  float x;
/* this (float) is to make the program give an answer as a float due to integer / integer would produce an integer, it is making the answer a float */
  x = (float) -c / b;
  printf ("x = %.2f", x);
}
