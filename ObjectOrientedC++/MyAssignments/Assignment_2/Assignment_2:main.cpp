/* 
 * File:   main.cpp
 * Author: John Coty Embry
 *	Class:  CMPSC 3543
 *	Assignment_2
 * Created on January 30, 2015, 12:26 PM
 */

#include <cstdlib>
#include <iostream>

#include "Vector.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {    
    double x[] = { 8.5, -2.0, 0.0, 4.2, 8.0, -3.5, 0.7 };
    int s = sizeof(x)/sizeof(double);
   
    Vector vector (s,x);

    vector.setVector(s,x); //this will make the length of x be v and make the elements of x be v
    vector.print();

    vector.print(4);

    double a[30];
              
    s = sizeof(a)/sizeof(double);
    for(int i=0; i < s; i++) {
        a[i] = i;
    } 
    Vector vector1(s,a);
    
    vector1.setVector(s,a);
    vector1.print();

    double y[] = { 0.5, -2.0, -1.0, 0.0, 4.1 };
    s = sizeof(y)/sizeof(double);

    Vector vy(s,y);
       
    vy.print();

    s = sizeof(x)/sizeof(double);
    Vector vx(s,x);

    vx.print();
        
    Vector vu;
    
    vu = vx + vy;
    vu.print();

   
    Vector vw;
    vw = vx - vy;
    vw.print();
          
    Vector vz;
   
    vz = vy - vx;

    vz.print();
 
    s = sizeof(x)/sizeof(double);
    Vector my_vector(-s, x); //this should give an error message by the constructor    
    
    return 0;
}
