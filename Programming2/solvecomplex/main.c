/*
	Author: Coty Embry
	Course: Computer Programming II
	Date: 03-01-2013
	Instructor: Ms. Tarver

	Program Comment: This program will add, subtract, multiply, negate, conjugate, divide, and toggle the selection on and off at will for the user.
	Input: stdin
	Output: stdout
*/
#include <stdio.h>
#include "complex.h"
#include "complex_arith.h"
#include "complex_io.h"
#include "boolean.h"

int main (void) {
complex num1, num2, ans;
int selection;
boolean menu = true;
boolean quit = false;


	

	while (!quit) {
		if (menu) {
				
					printf("1 Add\n");
					printf("2 Subtract\n");
					printf("3 Multiply\n");
					printf("4 Negate\n");
					printf("5 Conjugate\n");
					printf("6 Divide\n");
					printf("7 Toggle Menu\n");
					printf("8 Quit\n");
					printf("Enter a Selection: ");		
					scanf("%d", & selection);
}
		else {
			printf("Make a selection. (To toggle menu on and off press 7 and then enter\n)");
			scanf("%d", & selection);
}
/* throught this section of the switch statement which tells the program to go to which case from the user's selection, it will then call on the programs that I have written to do the arithmatic and input and output. */	
		switch (selection) {
			case 1: 
					num1 = read_complex();
					num2 = read_complex();
					ans = add_complex(num1, num2);
					write_complex(ans);
					break;
			case 2:
					num1 = read_complex();
					num2 = read_complex();
					ans = subtract_complex(num1, num2);
					write_complex(ans);
					break;
			case 3:
					num1 = read_complex();
					num2 = read_complex();
					ans = multiply_complex(num1, num2);
					write_complex(ans);
					break;
			case 4:
					num1 = read_complex();
					num2 = read_complex();
					ans = negate_complex(num1, num2);
					write_complex(ans);
					break;
			case 5:
					num1 = read_complex();
					num2 = read_complex();
					ans = conjugate_complex(num1);
					write_complex(ans);
					break;
			case 6:
					num1 = read_complex();
					num2 = read_complex();
					ans = divide_complex(num1, num2);
					write_complex(ans);
					break;
			case 7:
					menu = !menu;
					break;
			case 8:
					quit = true;
					break;
			default:
					printf("%d is not a valid selection\n", selection);
					printf("To toggle menu on and off press: 7 then enter\n");
					scanf("%d",& selection);
}
}
}





