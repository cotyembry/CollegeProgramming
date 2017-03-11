// One way to run this program WITHOUT Netbeans is to do the following.
//
// 1. Save the java source file in a directory named functions
//    which is the same name as in the package statement below.
// 2. Compile the program in the directory that is the parent of directory
//    functions as follows.
//	javac functions/Functions.java
// 3. Run the program in the directory that is the parent of directory
//    functions as follows.
//	java functions/Functions
//
// In general, the directory name where the Java source file(s) is
// saved is the name of the package in the package statement, e.g.,
// the name functions in a statement like
//	package functions;
//
// Another way is to comment out the statement
//	package functions;
// and compile and run the Java program from the directory where the
// Java source file is saved.

package functions;

/**
 *
 * @author  Mary Smith
 * Course:  CMPSC 2323
 * Example: Functions
 */
/*
A computer program can be divided into separate
functions.  Functions perform specific tasks and
can be re-used.  Functions are often passed
parameters, which consist of data that the function
uses as input to perform a task which usually
produces an output.  The output is returned as the
function value.
	
The usual use of a function is to "call" the function.
Calling a function means referencing it by name and
passing it zero or more parameters.  Execution transfers
to the function, the function performs its task and
returns a value to the program (or function) that called
it.
	
Functions have their own operating environment.  Variables
declared in functions are local to the function and are not
generally available to other functions.  This means, among
other things, that you can have variables with the same names
in separate functions but the variables are treated distinct
from each other.  This is demonstrated below.
*/

import java.io.*;

public class Functions {

// Function main is called by external software
    public static void main(String args[]) throws IOException {
        Add(3.2, 4.5);
	double z = -3.5;
	Add(z, 2.2);
	Echo("Hello");
	Echo();
	double x = 8.5;
	System.out.println("Before swap x=" + x + " z=" + z);		
	swap(x,z);
	System.out.println("After swap x=" + x + " z=" + z);
	System.out.println("Before swap x=" + x + " z=" + z);
	double nums[] = new double[2];
	nums[0] = x;	nums[1] = z;
	System.out.println("Before swap nums[0]=" + nums[0] +
			   " nums[1]=" + nums[1]);		
	swap(nums);
	x = nums[0];	z = nums[1];
	System.out.println("After swap x=" + x + " z=" + z);
	double y = Sum(z,3.0);
	System.out.println("y=" + y);
	y = Calculator('/',23.1,3);
	System.out.println("y=" + y);
	Calculator();
        System.out.println(Paste("a cat"," is on ","the mat"));
        System.out.println(Paste(" the mat","is on","a cat "));
}
	
// Function Add adds 2 values and prints result
static void Add(double x, double y) {
    double z = x + y;
    System.out.println("Sum of " + x + " and " + y + " = " + z);
}	

// Several versions of the same function can be
// created.  What distinguishes each version is
// the function's prototype (signature).  A function
// prototype (signature) is the number and type of
// parameters declared on the first line of the function.
//
// Having two or more versions of a function is
// called "function overloading".  There cannot be
// two versions of a function with the same prototype
// (signature).  This causes an error.  Here is an example
// of function overloading.

// Version 1 of function Echo prints a string
// which is passed as a parameter
static void Echo(String s) {
    System.out.println(s);
}	

// Version 2 of function Echo always prints the 
// string "Echo"
static void Echo() {
    System.out.println("Echo");
}	

// Version 1 of function swap attempts to swap
// the contents of two variables
static void swap(double x, double y) {
    double temp = x;
    x = y;
    y = temp;
}

// Version 2 of function swap swaps the contents
// of two array elements
static void swap(double a[]) {
    double temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}
	
// Compute the sum of two values and return the result.
// Note that the following function cannot be named Add.
// Why?
static double Sum(double a, double b) {
    return a + b;
}

static boolean validOperator(char operator) {
    boolean valid = true;
    switch( operator ) {
    case '+':
    case '-':
    case '*':
    case '/':
    	break;
    default:
    	valid = false;
	System.out.println("Invalid operator");
    }
    return valid;
}

static double Calculator(char operator, double x, double y) {
    double z = 0;
    switch( operator ) {
    case '+':
	z = x + y;
	break;
    case '-':
	z = x - y;
	break;
    case '*':
	z = x * y;
	break;
    case '/':
	if( y != 0 )
            z = x / y;
	else
            System.out.println("Can't divide by zero");
	break;
    }
    return z;
}
	
// Function that prompts for an operator (+,-,*,/) and two values.
// Perform the operation by calling function Calculator.  Print result.
static void Calculator() throws IOException {
    String line;
    BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));	
    System.out.print("Enter an operation: ");
    line = stdin.readLine();
    char operation  = line.charAt(0);
    if( validOperator(operation) ) {
	System.out.print("Enter first value: ");
	double x = Double.parseDouble( stdin.readLine() );
	System.out.print("Enter second value: ");
	double y = Double.parseDouble( stdin.readLine() );
	double result = Calculator(operation,x,y);	
	System.out.println("The result is: " + result);
    }
}

// Concatenate 3 strings in the opposite order they were passed.
static String Paste(String a, String b, String c)
{
    return c + b + a;
}
// Assignment: (20 points)
//
// Do Exercise 3.4 below.  Create a Netbeans project named
// Exercise3_4.  When you complete the project, compress the
// folder Exercise3_4 that contains the Netbeans project into
// a compressed file.  Submit the compressed file to Blackboard
// on or before the due date.
//
// Put the following comments at the beginning of your Java
// source file (replace Mary Smith with your name).
//
//  Mary Smith
//  CMPSC 2323
//  Exercise 3.4
//
// Exercise 3.4: Write a Java program that contains the following functions:
//  a. Difference - Pass the function two doubles.  The function returns
//     their difference (first minus second).  Test your
//     function on:
//       i)  7.5 and 8.2
//       ii) x and y where x = -5.6 and y = -10.0
//     Write a SECOND version of Difference.  This version
//     computes the difference of two integers, passed to
//     the function.  Test your function on:
//       i)  100 and 45
//       ii) u and v where u = 31 and v = 44
//  b. Large - Pass the function two integers.  The function returns
//     the larger value.  Test your function on:
//       i)   -8 and -3
//       ii)  u and v where u = 5 and v = 5
//       iii) u and 20 where u = 14
//     Write a SECOND version of Large that finds the larger
//     value of two doubles, passed as parameters, and returns
//     the larger value.  Test your function on:
//       i)   7.2 and 9.0
//       ii) -6.5 and y where y = -3.7
//  c. Small - Pass the function three doubles.  The function returns
//     the smallest value.  Test your function on:
//       i)  6.5, -3.2 and 0.0
//       ii) x, 8.8 and y where x = 3.1 and y = 3.1
//  d. Power - Pass the function two parameters.  The first parameter
//     is a double, say x, and the second is an integer, say p.
//     The function calculates x to the power p.  The function
//     prints an error message "Invalid operation" if x is zero
//     and p is less than or equal to zero.  Return zero in the
//     case of an invalid operation.

//im here

//  e. Compute - Pass the function three parameters: operation, x and y
//     where operation is a character indicating one of the
//     operations +, -, *, /, %, ^ where the last symbol ^ means
//     take x to the power y.  Parameters x and y are doubles.
//
//     The operation, and values for x and y are entered at the
//     terminal, similar to what was done in the second version of
//     function Calculator above.  In fact, you can copy and paste
//     some of the code from that function. The prompts and user
//     responses MUST be on the same line.
//
//     After the operation, and values for x and y are entered, call
//     function Compute, passing the operation, and the two values as
//     parameters.  The main function does not have to check to ensure
//     that the operation is valid.  This is done in function Compute.
//
//     Your function must check for division by zero when the
//     operations / or % are entered (check to see if y is zero)
//     and print an error message when this occurs.
//
//     Your function must print an error message when an invalid
//     operation is entered (something other than + - * / % ^).
//
//     When % is entered convert x and y to integers before
//     computing x % y.  This can be done with the integer cast.
//
//     When ^ is entered the function must convert y to an integer.
//     This can be done with the integer cast.  Function Compute
//     calls function Power, which you wrote in part d, to
//     calculate x taken to the power y.  In each case print the
//     result of a calculation.
//        
// If you DO NOT use Netbeans or use Netbeans 7 in the
// CS computer lab at ECU, create a Java file named
// named Exercise3_4.java in a folder named exercise3_4.
// The folder name is exercise3_4 all in lower case.
//        
// If you use Netbeans 7 in the CS computer lab at ECU
// follow the procedure to create a Netbeans 7 Java Project
// with Existing Source Files.  After you complete the
// exercise compress your Netbeans 7 Java project and submit
// the compressed file to Blackboard.  Submit the compressed
// file to Blackboard on or before the due date.  The due date
// will be posted on Blackboard and announced in class.    
//
// If you do not use Netbeans 7 or 8 then compress the folder
// exercise3_4 that contains your Java file.  Submit the compressed
// file to Blackboard on or before the due date.  The due date will
// be posted on Blackboard and announced in class.
//
// One way to run the program WITHOUT Netbeans is to do the following.
// 
// 1. Save the java source file in a directory named exercise3_4
//    which is the same name as in the package statement below.
// 2. Compile the program in the directory that is the parent of directory
//    exercise3_4 as follows.
//	javac exercise3_4/Exercise3_4.java
// 3. Run the program in the directory that is the parent of directory
//    exercise3_4 as follows.
//	java exercise3_4/Exercise3_4
//
// In general, the directory name where the Java source file(s) is
// saved is the name of the package in the package statement, e.g.,
// the name exercise3_4 in a statement like
//	package exercise3_4;
//
// Another way is to comment out the statement
//	package exercise3_4;
// and compile and run the Java program from the directory where the
// Java source file is saved.   
}
