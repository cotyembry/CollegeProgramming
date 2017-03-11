#include "boolean.h"
#include "RPN.h"
#include "fstack.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


float RPN(char * myinput) {
	char temp[100];
	int i = -1, j = 0, state = 0, x;
	float ans, num1, num2, numpush;
	fstack top;
	init_fstack(&top);


while (1) {
	switch (state) {
		case 0:	i++;
				if (is_RPN_operator(myinput[i])) {
					state = 1;
				}
					else {
						if (isdigit(myinput[i]) || (myinput[i] == '.')) {
							state = 2;
						}
							else {
								if (is_RPN_space(myinput[i])) 
									state = 4;
									else {
										if (myinput[i] == '\0') {
											state = 5;
										}
											else 
												state = 0;
									}		
							}				
					}
				break;
		
		case 1: if(is_fempty(top)) {
					printf("Error: Stack is empty!\n");
					exit (0);
				}
				else {
					num2 = fpop(& top);
					if (is_fempty(top)) {
						printf("Error: Stack is empty!\n");
						exit (0);
					}
					else {
						num1 = fpop(& top);
						switch (myinput[i]) {
								case '+':	fpush(& top, num1 + num2);
											break;
											
								case '-':	fpush(& top, num1 - num2);
											
											break;
											
								case '*':	fpush(& top, num1 * num2);
											break;
											
								case '/':	if (num2 == 0) {
												printf("Error: Cannot divide by 0\n");
												exit (0);
											}
											else {
												fpush(& top, num1 / num2);
											break;
											}
				}	}	}
					state = 0;
					break;
					
		case 2:	temp[j] = myinput[i];
				i++;
				j++;
				if (isdigit(myinput[i]) || (myinput[i] == '.')) {
					state = 2;
				}
				else {
					state = 3;
				}
				break;
			
		case 3:	temp[j] = '\0';
				sscanf(temp, "%f", & numpush);
				fpush(& top, numpush);
				j = 0;
				state = 0;
				break;
				
		case 4:	state = 0;
				break;
				
		case 5:	if(is_fempty(top)) {
					printf("Error: Please Enter a valid RPN expression\n");
					exit (0);
				}
				else {
					ans = fpop(& top);
					return ans;
				}
				break;
				
		case 6:	printf("Error: Garbage found\n");
				exit (0);
	
}

}
}


boolean is_RPN_operator (char op) {
	if ((op == '+') || (op == '-') || (op == '*') || (op == '/')) {
		return true;
	}
	else {
		return false;
	}
}


boolean is_RPN_space (char space) {
	return(space == ' ');
}
