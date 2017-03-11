
package exercise3_5;

/**
 *
 * @author      John Coty Embry
 * Class:       CMPSC 2323 Internet Programming
 * Assignment:  Exercise3_5
 */
public class Main {
    public static void main(String args[]) {
   // double area = 0, area1 = 0, area2 = 0, perimeter = 0, perimeter1 = 0, perimeter2 = 0;
     Rectangle rectangle = new Rectangle(12, 7);
     Rectangle rectangle1 = new Rectangle(100, 85);
     Rectangle rectangle2 = new Rectangle(44.5, 30.8);

     rectangle.perimeter();
     rectangle.area();
     rectangle.print();
     System.out.println("\n");
     
     rectangle1.perimeter();
     rectangle1.area();
     rectangle1.print();
     System.out.println("\n");

     rectangle2.perimeter();
     rectangle2.area();
     rectangle2.print();
     System.out.println("\n");     
     
     rectangle.expand(20);
     rectangle.print();
     System.out.println("\n"); 
     
     rectangle1.shrink(15);
     rectangle1.print();
     System.out.println("\n");     
     
     rectangle2.expand(150);
     
     rectangle2.shrink(-22);   
    }
}
