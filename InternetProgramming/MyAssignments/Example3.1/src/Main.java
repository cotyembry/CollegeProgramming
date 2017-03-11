

import java.util.Scanner;

/**
 * Class: Internet Programming
 * @author John Coty Embry
 * Exercise 3.1
 * CMPSC 2323
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) { //with buffer we have to throw IOException
        int a, b;
        //Bufferreader stdin = new Bufferreader(new InputStreamReader(System.in)); I chose to use Scanner instead
        //a = Integer.parseInt( stdin.readLine());
        
        System.out.println("Enter a number: ");
        a = in.nextInt();
        System.out.println("Enter a number: ");
        b = in.nextInt(); 
        
        if(a > b) {
            System.out.println(b + " is smaller.");
        }
        else if(a < b) {
            System.out.println(a + " is smaller.");
        }
        
        if(a != b) { 
            System.out.println("The numbers are different.");
        }
        else if(a == b) {
            System.out.println("The numbers are equal.");
        }
        
        if( ((a*a) - (b*b)) >= (10*b)) {
            a = a*a*a;
            System.out.println("a cubed is " + a);
        }
        else {
            a = a*b;
            System.out.println("a*b is " + a);
        }
    }
    
}