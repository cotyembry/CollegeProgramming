#include<stdio.h>
#include<math.h>
/*
	AUTHOR:
		Coty Embry
		CMPSC 1113 - Computer Programming II

		PROGRAMMING COMMENT: This program will allow the user to enter where they want the number to start at, end at, and what increment the table will increase by. It will display the number in question followed by its square root value.

		INPUT: command line, stdin

		OUTPUT:stdout
*/
int main (int argc, char *argv[]) {

  int start, stop, step, col;
  float fans;
/* this is telling the program to read and assign the integers entered from the command line to a variable */
  if (argc == 4) {
      sscanf (argv[1], "%d", &start);
      sscanf (argv[2], "%d", &stop);
      sscanf (argv[3], "%d", &step);
}
/* This is prompting the user to enter in the starting point, stopping point, and the increments of this table then the program is assigning the users integers to a variable */
  else {
      printf ("What integer do you want the table to start at?\n");
      scanf ("%d", &start);
      printf ("What integer do you want the table to end at?\n");
      scanf ("%d", &stop);
      printf ("What integer do you want the table to increase, or decrease by?");
      scanf ("%d", &step);
      printf ("_______________________________________________________________\n");
}
/* This if statement is setting the condition that if start is <= to start and the increment is > 0 the program will run a for loop and create a table. */
  if ((start <= stop) && (step > 0)) { 
     for (col = start; col <= stop; col = col + step) {
/* This is making it where if the program happens to take the square root of a negative # it will put an i on the end of the number to show it is imaginary after taking the square root of the absolute value of the number in question */
	if(col < 0) {
		fans = sqrt (abs (col));
		printf ("%d\t %.3fi\n", col, fans);
}		
/* This is simply saying if the integer is anything other than something being less than 0 it will just solve the problem and print out the answer */
	else {
		fans = sqrt (col);
		printf ("%d\t %.3f\n", col, fans);
}
}
}
/* This compound if statement is making sure that the table is decreasing. */
  else {
	if ((start >= stop) && (step > 0)) {
/* This for loop is having the program subtract the amount of the increment from the starting point that the user enters in. */
    		for (col = start; col >= stop; col = col - step){
/* This if statement is < 0 to go with the process of adding an i on the end of the absolute value of the negative # to show it is imaginary. */
			if (col < 0) {
				fans = sqrt (abs (col));
				printf ("%d\t %.3fi\n", col, fans);
}
			else {
				fans = sqrt (col);
				printf("%d\t %.3f\n", col, fans);
}
}
}
/* This is just to tell the user that if they did a table that is not plausable to try making another one */
	else {
		printf("Invalid selection, try again.");
}
}
printf("\n");
}
