#include "boolean.h"
#include "shunting_yard.h"
#include "cstack.h"
#include "fstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "RPN.h"	

boolean is_space (char);
boolean is_operator (char);
int prec (char);

float shunting_yard(char myinput[500], float RPNans) {
	char temp[500], output[500], test[500], c;
	int i = -1, j = 0, state = 0, x, o = 0, o1, o2, f;
	float ans, num1, num2, numpush;
	fstack top;
	cstack ctop;
	init_fstack(& top);
	init_cstack(& ctop);


	while (1) {
		switch (state) {
			case 0:	i++;
					if (is_operator (myinput[i])) {
						state = 1;
					}
						else {
							if (isdigit(myinput[i]) || (myinput[i] == '.')) {
								state = 2;
							}
								else {
									if (is_space(myinput[i])) 
										state = 4;
										else {
											if (myinput[i] == '\0') {
												state = 5;
											}
												else {
													if (myinput[i] == '(') {
														cpush(& ctop, myinput[i]);
														state = 0;
													}
													else {
														if (myinput[i] == ')') {
															while (ctop -> data != '(' && (!is_cempty(ctop))) {
																output[o] = ' ';
																o++;
																output[o] = cpop(& ctop);
																o++;
															}
															cpop(& ctop);
															state = 0;
														}
														else {
															if (myinput[i] == ' ') 
															 state = 4;
															
															else 
																state = 6;															
														}			
													}				
												}
										}
								}
						}
					break;
			
			case 1:	o1 = prec(myinput[i]);
					if(!is_cempty(ctop) && (ctop -> data != '(')) {
						o2 = prec(ctop -> data);
					}

					while(!is_cempty(ctop) && (o1 <= o2) && (ctop -> data != '(')) {
						output[o] = cpop(&ctop);
						o++;
						output[o] = ' ';
						o++;
					}
					cpush(&ctop, myinput[i]);
					state = 0;

					break;
						
			case 2:	temp[j] = myinput[i];
					output[o] = temp[j];
					i++;
					j++;
					o++;
					if (isdigit(myinput[i]) || (myinput[i] == '.')) {
						state = 2;
					}
					else {
						state = 3;
					}
					break;
				
			case 3:	output[o] = ' ';
							o++;
							i--;
							j = 0;
							state = 0;
						
						break;
					
			case 4:	state = 0;
					break;
					
			case 5:	while ((!is_cempty(ctop))) {
								if (ctop -> data != '(') {
									output[o] = cpop(&ctop);
									o++;
									output[o] = ' ';
									o++;
								}
								else {
									if (ctop -> data == '(') {
										printf("Error: Found ( expecting )\n");
										exit (0);
									}
								}
							}	
							
								output[o] = '\0';
								strcpy(myinput, output);
								
								return RPNans = RPN(output);
								
							
					break;
					
			case 6:	printf("Error: Garbage found\n");
							exit (0);
							break;

		
	

			}
	}
}
boolean is_operator (char op) {
	if ((op == '+') || (op == '-') || (op == '*') || (op == '/')) {
		return true;
	}
	else {
		return false;
	}
}

boolean is_space (char space) {
	return(space == ' ');
}

int prec(char op) {
	switch (op) {
		case '-':
		
		case '+':	return 2;
					break;
		case '/':

		case '*':	return 3;
					break;
		default:	return 1;
	}
}