//Hello World
#include <stdio.h>
int main() {
	printf("Hello world!\n");

	return 0;
}


/*
Let's break the code down a little
#include - this is a command that basically takes the code from within the '<>' angled brackets and makes it available in this code (remember, we're hitting the ground running)
<stdio.h> - this is a file we are 'including' in this file to use the code in it. (i.e. the printf() code)
int - this is the return type (more on this later)
main - this is the name of the `function`
{} - in between these curly braces is the block of code to be 'executed' when the funciton main is 'invoked'
printf() - this is a function that is from the stdio.h library
return 0; - this is a `keyword` in C that has a specific meaning. In this case we are returning 0, which is an int (integer - i.e. 1, 2, 3, 4 are all integers)
*/

//Question: what is a difference between the printf(...); and int main() { ... } functions?











//Answer: int main() { ... } is a function definition, printf(...) is 'invoking' the printf function
//anytime you see some name with () on the end of it, that is a function call. calling the funciton, invoking the function - same sort of thing

//What is a function?
//It allows you to define some arbitrary (general) code to be executed when the function that contains the code is invoked

//variables - they let you save data to use a function and/or algorithm

//int myAwesomeFirstVariable = 7;

//the can be named anything you want (pretty much)
//issues: cannot start with a number or special character other than '_' (the underscore)
//THIS IS WRONG: int $x = 88;

//other 'types' of variables

//float thatPiWuzGood = 3.14159;

//long lecturesAreHard = 55;

//char z = "a"; //or even char z = "z"; (but that might be confusing right now)

//now lets talk about how the C code gets executed

//sort of top to bottom if you want to compare it to English
//but for left to right... thats a little different

//Question: what will be printed on the screen
int main() {
	printf("1\n");
	printf("2\n");
	printf("3\n");
}

