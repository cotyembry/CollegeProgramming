/*	Author:	Coty Embry
	Class:	Data Structures
	Program Comment:	This program will be able to calculate integers/floats in reverse polish notation. Such as 3 2 + is the same as the standard 3 + 2. It will also take advantage a delimeter checker so if the user enters ( or [ or { without a matching bracket, an error message will occur and the program will exit.
*/

#include <stdio.h>
#include <string.h>
#include "shunting_yard.h"
#include "RPN.h"



int main () {
	char myinput[500], output[501], test;
	float ans;
	int o;
	system("clear");

		printf("Enter in a Algebraic equation\n");

		gets(myinput);

			ans = shunting_yard(myinput, ans);

			printf("And the answer is: %.2f\n", ans);

}


