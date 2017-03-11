# include<stdio.h>/*<-- that includes the basic programming language allowing this program to understand the commands we are doing (excluding the math)*/
# define Pi 3.14 /* <-- that makes 3.14 be assigned through out the program to now be known as Pi so where ever Pi shows up it will be 3.14 in disquise*/
# include <math.h>/* <-- that includes the math library; without that, all the math functions wouldn't be available*/
/*
		
	AUTHOR:
		John Embry
		CMPSC 1113 - Computer Programming I

	
		PROGRAMMING COMMENT: This program will allow the user to do three math functions; find the circumference of a circle, find the area of a rectangle, and find the perimeter of a rectangle. 
			

		
		INPUT:  stdin

	
		OUTPUT: stdout
*/

/*	This declares there is a subprogram with a menu */
int menu(void);
	 
int main(void){
/*	This section is declaring which variables are integers, and which are floats. */

	int selection, r, l, perimeter, w, area, choice;
	float circumference;

/*	At the start of this section the program will display a simple printf saying the name of the author of the program. The selection = menu(); is calling on the subprogram to show its self for the user to choose a selection. The while loop is working with the switch statement below it telling the program if the selection the user enters is not equal to 4 to follow the appropriat case defined by what the user enters. I.e. if the user enters 1, or 2, or 3, or 4, the program will go through which ever selction is imput. 
	If it is a 1 the program will go through case 1. It will ask the user what the radius is with a printf, then the program will scan the users input and assign it to r. Now if the users input is less that or equal to 0, an error message will display using a printf statement echoing the users input as well as telling the user it must be greater than0. If that happens the program calls on the subprogram to allow the user to selection what they want to do next, otherwise the program will calculate the circumference of the circle using the formula 2 * Pi * r. The circumference will be assigned as a variable for the answer. the printf statement will then display the answer in sentence form echoing what the user entered. The program will then call the subprogram back, then the break after that is just telling the program the "case" is finished.
	
	If it is a 2 the program will go through case 2. It will ask the user what the length is with a printf statement. It will then scan the users input. The while loop is setting the condition that if the length (l) is less than or equal to 0 an error message will display to the screen echoing the users input as well as telling the user it must be greater than 0. It will then re-ask the user for the input for the length. If the user enters an integer that is less than or equal to 0, the program will do the same steps as mentioned above, otherwise the program will ask the user what the width is. The while loop set this condition just as I have described the lenth's while loop condition. After that, "area" is getting assigned as a variable for the answer with the special character "=" using the formula length * width. A printf statement will then display in sentence form what the user entered as well as calculate the and display the answer for the area of the rectangle. The program will then call the subprogram back; the break after that is just telling the program the "case" is finished.

	If it is a 3 the program will go through case 3. It will ask the user to enter the length with a printf statement. It will then scan the input and assign it to the variable "l" with a scanf statement. The while loop is setting the condition if l is less than or equal to 0 the program will display an error message echoing the users input as well as saying it must be greater than 0. It will then ask the user what the length is again and scanf and assign to the variable "l" if it does not offend the condition of the while loop. The same process happens for the next process for the getting the width. The program then assigns the answer to the variable "perimeter" using the formula 2 * length + 2* width. The answer is then displayed in sentence form echoing the users input. The program will then call the subprogram back; the break after that is just telling the program the "case" is finished.
	
	The default will take over if the user selects anything that is not 1, 2, or 3 having the program printf the error message that what the user entered is not a valid selection, this will also echo the users input. Just after the default the program will printf "Midterm Complete!" and will end the program if the user chooses 4
*/
	printf("Name: John Embry\n");
	selection = menu();
	while (selection != 4) {
		switch (selection) {
			case 1: printf("What is the radius of the circle: ");
				scanf("%d",& r);
				if(r<=0)
					printf("Error: The radius you entered (%d) can't be less than or equal to 0\n", r);
				else {
					circumference = 2 * Pi * r;
					printf("The circumference of a circle with the radius of %d is %.2f\n", r, circumference);
}
				selection = menu();
				break;
			case 2: printf("What is the length of the rectangle: ");
				scanf("%d", & l);
				while(l<=0) {
					printf("Error: The length you entered (%d) can't be less than or equal to 0\n", l);
					printf("What is the length of the rectangle: ");
					scanf("%d",& l);
}
				printf("What is the width of the rectangle: ");
				scanf("%d",& w);
				while(w<=0) {
					printf("Error: The width you entered (%d) can't be less than or equal to 0\n", w);
					printf("What is the length of the rectangle: ");
					scanf("%d",& w);
}
				area = l * w;
				printf("The area of a rectangle with a length of %d and a width of %d is %d\n", l, w, area);
				selection = menu();
				break;
			case 3: printf("Enter the length of the rectangle: ");
				scanf("%d",& l);
				while(l<=0) {
					printf("Error: The length you entered (%d) can't be less than or equal to 0\n", l);
					printf("What is the length of the rectangle: ");
					scanf("%d",& l);
}
				printf("Enter the width of the rectangle: ");
				scanf("%d",& w);
				while(w<=0) {
					printf("Error: The width you entered (%d) can't be less than or equal to 0\n", w);
					printf("What is the width of the rectangle: ");
					scanf("%d",& w);
}
				perimeter = 2*l + 2*w;
				printf("The perimeter of a rectangle with a length of %d and a width of %d is %d\n", l, w, perimeter);
				selection = menu();
				break;				
			default:printf("Error: (%d) is not a valid selection\n", selection);
				selection = menu();
}
}
	printf("Midterm Complete!\n");
}
/*	This subprogram will come up anytime the program calls on it using "selection = menu();" It will allow the program to display these 5 printf lines. The above program has already established cases of which the program will follow, but what this subprogram allows it to do is direct which case the program will follow. After the user makes a selection (1 through 4) the subprogram will scanf the input and assign it to choice and then the subprogram will then direct the main program using the return function on which case to follow from there. The second line of the subprogram is assigning the input that the user inputs as an integer.
*/
int menu(void) {
	int choice;
	printf("1 Circumference\n");
	printf("2 Area of a Rectangle\n");
	printf("3 Perimeter of a Rectangle\n");
	printf("4 Quit\n");
	printf("Enter a Selection: ");
	scanf("%d",& choice);
	return choice;
}			

