// NEW!
#include <stdio.h>
#include "solvecomplex.h"
#include "solvereal.h"
#include "solvequad.h"
/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II
*/
/* this is bringing the values of a, b, and c, into the program */


void
solvequad (int a, int b, int c)
{
  int ans;
/* this is setting the expectation that if b * b - 4 * a * c is less than 0, the program will call the solvecomplex program and send the values a,b,and c. If it is greater than 0, it will call on the solvereal program and send the values a, b, and c. */

  ans = (b * b) - (4 * (a * c));
  if (ans < 0)
    solvecomplex (a, b, c);
  else
    solvereal (a, b, c);
}
