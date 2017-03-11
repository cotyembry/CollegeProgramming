// NEW!
#include <stdio.h>
#include "solvelinear.h"
#include "solvequad.h"

/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II

		PROGRAMMING COMMENT: This program will solve a linear, or quadratic equation
		INPUT: command line, stdin

		OUTPUT:stdout
*/
/* This is saying that there is input coming fro the command line, then after that I am declaring variables as integers */
int
main (int argc, char *argv[])
{
  int a, b, c;
/* this if statement is directing the program to turn the strings from the command line into integers and assign them to variables */
  if (argc == 4)
    {
      sscanf (argv[1], "%d", &a);
      sscanf (argv[2], "%d", &b);
      sscanf (argv[3], "%d", &c);
    }
/* this is setting the condition that if there is no input from the command line, to give an error message. The return 1 then ends the program */
  else
	{
      printf("Enter 3 integers to start the program\n");
	  return 1;
	} 
/* these if and else statements are here to direct the program to the correct handeling procedure. After filtering out the users input, the program calls on the correct program */
  if (a == 0) {
      if (b == 0)
          printf("Error: Please enter a valid numbers that requires problem solving\n");
      else
          solvelinear (b, c);
  }
  else
    solvequad (a, b, c);
}
