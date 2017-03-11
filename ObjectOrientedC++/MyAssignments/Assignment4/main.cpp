/* 
 * File:   main.cpp
 * Author: John Coty Embry
 * Assignment 4
 * Created on March 26, 2015, 10:47 AM
 */

#include <cstdlib>
#include "Employee.h"
#include "Geometric.h"

using namespace std;

//no specifics were given on the department being supervised (i.e. what departments there are)
int main(int argc, char** argv) {
    Employee Sarah("Sarah Miller","789-01-5029", business, 15, 56805);
    Sarah.print(); 
    
    Supervisor Sue("Sue Ackerman", "201-33-8710", research, 4, 71020, "Flight Simulator", software, 6);
    Sue.print();

    Triangle arrow_head(4.0, 3.0, 5.0);
    arrow_head.print();
    
    Equilateral sign(7.2);
    sign.print();
    
    Ellipse oval(5.0, 2.0);
    oval.print();
    
    Circle ring(4.5);
    ring.print();
    
    Triangle* t = new Triangle(5.2, 4.6, 5.2);
    t->print();
}
