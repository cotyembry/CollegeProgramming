/* 
 * File:   Queue.cpp
 * Author: John Coty Embry
 * Course: CMPSC 3543
 * Assignment 5
 * Created on April 13, 2015, 9:32 AM6
 */

#include <cstdlib>
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"
#include "Order.h"

using namespace std;
/*
 * 
 */
int main(int argc, char** argv) {
    Queue<char> testing(3);

    testing.enqueue('S');    
    testing.enqueue('a');
    testing.enqueue('l');
    testing.enqueue('l');
    testing.enqueue('y');
    while(!testing.isEmpty()) {
        cout << testing.dequeue() << " ";
    }
    
    Queue<double> testing2(4);
    double darray[] = {0.8, -1.7, 5.0, 2.2, 9.6, -5.3};
    for(int i = 0; i < sizeof(darray)/sizeof(double); i++) {
        testing2.enqueue(darray[i]);
    }

    Order meal[] = {
        Order(312,4.95,"burger, fries, drink"),
        Order(245,4.15,"burger, drink"),
        Order(207,1.45,"fries, drink"),
        Order(156,0.65,"fries"),
        Order(198,4.70,"combo")        
    };

    Queue<Order> theorder(3);
    int j = 0;
    for(int i = 0; i < sizeof(meal)/sizeof(Order); i++) {
        theorder.enqueue(meal[i]);
    }
    while(!theorder.isEmpty()) {
        theorder.dequeue().print();
    }
    theorder.dequeue();

}

