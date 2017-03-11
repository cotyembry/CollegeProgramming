/**
 *
 * @author John Coty Embry
 * Internet Programming
 * CMPSC 2323
 * Exercise 3.2
 */

import java.util.Scanner;

public class Exercise3_2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        char a;
        
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a character: ");
        a = in.next().charAt(0);
        
        switch(a) {
            case ':':                
            case ';':
            case ',':
                System.out.println("punctuation mark " + a);
                break;
            case '{':
            case '}':
            case '[':
            case ']':
            case '(':
            case ')':
                System.out.println("grouping symbol " + a);
                break;
            case '=':
            case '<':
            case '>':
                System.out.println("compare symbol " + a);
                break;
            default:
                System.out.println("miscellaneous symbol " + a);
        }
        
    }
    
}
