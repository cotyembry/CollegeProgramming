/* 
 * File:   main.cpp
 * Author: Coty
 * Assignment 8
 * Object Oriented Programming
 *
 * Created on February 22, 2015, 9:07 PM
 */

#include <cstdlib>
#include "Set.h"

using namespace std;

/*  John Coty Embry
 *  Object Oriented Programming
 *  Assignment 8 
 */
int main(int argc, char** argv) {
    int na, nb;
    
    double a[] = { -6.2, -3.1, 0.0, 1.9, 5.2, 8.3, 9.5, 10.7, 11.0, 12.5 };
    double b[] = { -8.1, -3.1, 0.0, 2.5, 5.8, 8.3, 9.5, 11.0 };
    
    na = sizeof(a)/sizeof(double);
    nb = sizeof(b)/sizeof(double);
    Set Z;
    Set X;
    Set Y;//this creates an empty set
    X.setSet(na,a);
    Y.setSet(nb,b);
    X.print();
    Y.print();
    Z = X + Y;
    Z.print();
    Z = X * Y;
    Z.print();
    Set U(-na, a);
    Z.setSet(nb,NULL);//I wrote a case for this, I don't know why it doesnt run here
}

