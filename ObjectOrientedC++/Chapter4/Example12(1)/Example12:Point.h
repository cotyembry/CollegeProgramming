/* 
 * File:   Point.h
 * Author: Mary Smith
 * Course: CMPSC 3543
 * Example 12
 * Created on November 26, 2014, 10:19 AM
 */

#include <iostream>     // needed for cout and cerr

#ifndef POINT_H
#define	POINT_H

using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point() : x(0), y(0) {}   
    Point(const double a, const double b) : x(a), y(b) {}
    void print() const { cout << "(" << x << "," << y << ")" << endl; }
};

#endif	/* POINT_H */

