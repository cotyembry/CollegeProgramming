#include <stdio.h>
#define true 1
#define false 0

typedef int boolean;

selection = true;
quit = false;

typedef struct {
		int real;
		int img;
}   	complex;

int menu (void);
int main (void) {
complex num1, num2, ans;
selection = menu();

	complex read_complex (void);
	void write_complex (complex);
	boolean boolean (void);
	complex add_complex (complex, complex);
	complex subtract_complex (complex, complex);
	complex multiply_complex (complex, complex);
	complex negate_complex (complex, complex);
	complex conjugate_complex (complex);
	complex divide_complex (complex, complex);

	printf("To toggle menu on and off press: 7 then enter");

	while (!quit) {
		switch (selection) {

						case 1: 
										ans = 
						}

						case 2:
								// this is bringing in two of my own types, calculating an answer, then sending the answers back to the main program.
								complex subtract_complex (complex, complex); {

										ans.real = num1.real + num2.real;
										ans.img = num1.img + num2.img;
								// this is returning the answers to the main program
										return ans.real, ans.img;
								//this is telling the program to stop this selection
										break;
						}

						case 3:
								complex multiply_complex (complex, complex);
								// this is the number 3 selection that the user enters on the menu
										ans.real =  num1.real * num2.real - (num1.img * num2.img);
										ans.img = num2.real * num1.img - (num1.real * num2.img);
								// this is returning the answer to the main program
										return ans.real, ans.img;
								//this is telling the program to stop this selection
										break;

						case 4:
								// this is bringing in two of my own types and sending my own type back
								complex negate_complex (complex, complex) {
										ans.real = -1 * num1.real;
										ans.img = -1 * num1.img;
								// this is returning the answers back to the main program
									return ans.real, ans.img;
						}

						case 5:
							// this is bringing in two of my own types and sending the answer back to the main program
							complex conjugate_complex (complex, complex) {
									ans.img = -1 * num1.img;
							// this is returning the answer back to the main program
								return ans.img;
						}

						case 6:
								// this is bringing in two of my own types and sending the answer back as my own type as well
								complex divide_complex (complex, complex) {
										// I am casting so there is not int / int division
										ans = (float)(num1 * (-1 * num2)) / (num2 * (-1 * num2));
										printf("%f %f", & num1, num2);
										printf("To toggle menu on and off press: 7 then enter");
}
}
}

int menu(void) {
				int choice;
					printf("1 Add\n");
					printf("2 Subtract\n");
					printf("3 Multiply\n");
					printf("4 Negate\n");
					printf("5 Conjugate\n");
					printf("6 Divide\n");
					printf("7 Toggle Menu\n");
					printf("8 Quit\n");
					printf("Enter a Selection: ");
					scanf("%d", &choice);
					return choice;
}
	
