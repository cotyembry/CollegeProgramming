/* 
	Coty Embry
   CMPSC 2323
   Exercise 2.1
*/

import java.io.*;	// needed to read input stream

public class Exercise2_1 {

	public static void main(String args[]) throws IOException {
	
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		
		int first, second, difference;
		
		System.out.print("Enter first whole number: ");
		first = Integer.parseInt( stdin.readLine() );
		
		System.out.print("Enter second whole number: ");
		second = Integer.parseInt( stdin.readLine() );
		
		difference = first - second;
		System.out.println("The difference of the numbers is: " + difference);
	}

// Java Program Assignment 1 (10 points)
	
// For each of the following exercises, at the top of your
// program put the following comment statements
//
//			Mary Smith
//			CMPSC 2323
//			Exercise 2.1 
//
// except replace Mary Smith with your name.  Replace
// Exercise 2.1 with Exercise 2.2 for Exercise 2.2.
// 
// Put the Java source files for Exercise 2.1 and
// Exercise 2.2 in a folder named Chapter2Assignment1.
//	
// Exercise 2.1: Write a Java program that reads two
//		 whole numbers, computes their difference,
//		 first number minus second number, and
//		 prints the result.  Your program should
//		 ask (prompt) the user for each number.
//		 Your prompt and the user's answer MUST be
//		 on the SAME line for you to get full credit.
//		 Your output should appear as follows
//		   The difference of the numbers is: xxx
//		 where xxx is the result.
//
//		 Name your Java source file Exercise2_1.java
//		 and put Java source file Exercise2_1.java in
//		 folder Chapter2Assignment1.
	
// Exercise 2.2: Write a Java program that reads two whole
//		 numbers into variables a and b.  Your program
//		 prompts the user for each number.  The prompt
//		 and the user's response MUST be on the SAME
//		 line for you to get full credit.  Next the
//		 program prints the following
//		   a = xxx
//		   b = yyy
//		 where xxx is the first number and yyy is
//		 the second number.  Now swap the contents
//		 of a and b.  Then print the following
//		   a = yyy
//		   b = xxx
//		 where yyy is the new contents of a and xxx
//		 is the new contents of b.
//
//		 Name your Java source file Exercise2_2.java
//		 and put Java source file Exercise2_2.java in
//		 folder Chapter2Assignment1.

// When you complete Exercise 2.1 and Exercise 2.2 compress folder
// Chapter2Assignment1.  Submit the compressed file to Blackboard to
// be graded on or before the due date.  The due date for assignment 1
// will be posted on Blackboard and announced in class.
	
}
