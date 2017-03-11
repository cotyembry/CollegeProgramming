/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author John Coty Embry
 * CMPSC 2323
 * Exercise 3.3
 */

import java.util.Scanner;


public class Exercise3_3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
            int i = 0, mult_seven = 0, temp = 0, noaverage = 0;
            float input = 0, input_sum = 0, average = 0, smallest = 0, largest = 0;
            Scanner in = new Scanner(System.in);
            //this is part a
            for(int a = -28; a != 77; a = a + 7) {
                if(a < 0) {
                    temp = a*-1;
                }
                else {
                    temp = a;
                }
                System.out.print(temp + " ");
            }
            
            System.out.println();

            //this is part b
            do{
                System.out.print("Enter a decimal value (or enter a negative number to exit loop): ");
                input = in.nextFloat();
                if(input >= 0) {
                    //this will keep track of how many numbers were entered to get the average
                    i++;
                    input_sum = input + input_sum;
                }else if((input < 0) && (i ==0)){
                    System.out.println("All that was entered was " + " so no average will be given.");
                    noaverage = 1; //this is if all the user entered at the first was 0 and thats it
                }
                else {
                    average = input_sum / i;
                }
                
            }while(input >=0);
            
            if(noaverage != 1) {
                  System.out.println("Average = " + average);
            }
            
            //this is part c
           input = -1;
           i = -1;
            while(input != 0) {                
                System.out.print("Enter a decimal value (or enter 0 to exit loop): ");
                if(input != 0) {
                    input = in.nextFloat();
                    i++;
                }
                if((input > largest) && (input != 0)){
                    largest = input;
                }else if((input < smallest) && (input != 0)) {
                    smallest = input;
                }
                
            }
            
            if(i == 0) {
                System.out.println("All that was ever entered was 0.");
            }else {
                System.out.println("Smallest = " + smallest + " largest = " + largest);

            }          
    }
}
