/* 
	Coty Embry
   CMPSC 2323
   Exercise 2.2
*/

import java.io.*;	// needed to read input stream

public class Exercise2_2 {

	public static void main(String args[]) throws IOException {
	
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		
		int a, b, temp = 0;
		
		System.out.print("Enter first whole number: ");
		a = Integer.parseInt( stdin.readLine() );
		
		System.out.print("Enter second whole number: ");
		b = Integer.parseInt( stdin.readLine() );
		
		System.out.println("a = " + a + " b = " + b);
		temp = b;
		b = a;
		a = temp;
				System.out.println("a = " + a + " b = " + b);

	}

}
