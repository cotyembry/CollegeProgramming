//  John Coty Embry
//  CMPSC 2323
//  Exercise 3.5

package exercise3_5;

public class Rectangle {
    
        private double length, width, area, perimeter;
        
        Rectangle(double length, double width) {
            this.length = length;
            this.width = width;
        }
        
        public double area() {
            this.area = length * width;
            return area;
        }
        
        public double perimeter() {
            this.perimeter = 2*(length + width);            
            return perimeter;
        }
        
        public void shrink(int s) { //this will be a value between 0 and 100, for example, the value 32 
                                      //means shrink the rectangle by 32%
            if((s < 0) || (s > 100)) {
                System.out.println("Error: Only values between 0 and 100 are accepted for shrinking!");
            }
            else {
                length = length - ( ( (double)s / 100 ) * length);
                width = width - ( ( (double)s / 100) * width);
                area = area();
                perimeter = perimeter();
            }
        }
        
       public void expand(int e) {
            if((e < 0) || (e > 100)) {
                System.out.println("Error: Only values between 0 and 100 are accepted for expanding!");
            }
            else {
                length = length + ( ( (double)e / 100 ) * length );
                width = width + ( ( (double)e / 100 ) * width );
                area = area();
                perimeter = perimeter();
            }
        }
       
       public void print() {
           System.out.println("area = " + area);
           System.out.println("perimeter = " + perimeter);
       }
       
       public double getArea() {
           return area;
       }
       
       public double getPerimeter() {
           return perimeter;
       }
    
}
