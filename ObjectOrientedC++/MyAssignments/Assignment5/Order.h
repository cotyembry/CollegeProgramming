/* 
 * File:   Order.h
 * Author: cotyembry
 *
 * Created on April 20, 2015, 11:37 PM
 */

#include <cstdlib>
#include <assert.h>
#include <iostream>
#include <string.h>

#ifndef ORDER_H
#define	ORDER_H

const int DSIZE = 80;
using namespace std;

class Order {
public:
    Order() {
        number = 0;
        price = 0;
        meal = new char[1]; //we have to dynamically allocate for a new array
        meal[0] = 0;
    }
    
    Order(const int n, const float p, const char* m) : number(n), price(p) {
        meal = new char[DSIZE]; //this function initializes all the values passed
        assert(strlen(m) < DSIZE);
        strcpy(meal, m);
    }
    
    void print() const {
        cout << "order number: " << number << ", meal: " << meal << ", price: $" << price << endl;
    }
private:
    int number;
    float price;
    char* meal;
};




#endif	/* ORDER_H */

