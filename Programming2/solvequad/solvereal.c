// NEW!
#include <stdio.h>
#include <math.h>
#include "solvequad.h"
/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II
*/
/* this is bringing in the variables of a, b, and c, into the program. The program then delcares the variables x1 and x2 as floats*/
void
solvereal (int a, int b, int c)
{
  float x1, x2;
/* this is assigning the calculated answers to x1 and x2 */
  x1 = (-b + sqrt (b * b - 4 * a * c)) / (2 * a);
  x2 = (-b - sqrt (b * b - 4 * a * c)) / (2 * a);
/* the program then prints out the answers from the variables x1 and x2 */
  printf ("The answers are: %.2f and %.2f\n", x1, x2);
}
