/* 
 * File:   Shape.h
 * Author: Mary Smith
 * Course: CMPSC 3543
 * Example 10: Illustrates an abstract base
 *             class that contains virtual
 *             functions and protected member
 *             variables.
 *
 * Created on November 22, 2014, 3:35 PM
 */

#ifndef SHAPE_H
#define	SHAPE_H

#include <iostream>     // needed for cout and cerr
#include <math.h>       // needed for M_PI = 3.14159...

using namespace std;

// Shape is an abstract base class because it
// has at least one member function that is a
// pure virtual function.  A pure virtual function
// is declared with the virtual keyword and is
// set to zero in its prototype.  A class such
// as Shape is considered an abstract base class.
// An abstract class CANNOT have an object
// delcared, for example, in main for it.  For
// example, trying to declare a Shape object in
// function main causes a compiler error.
class Shape {
private:
    // Area and Perimeter are pure virtual functions.
    // A virtual function is overidden by functions in
    // a derived class (a class derived from Shape in this
    // case) having the same name, i.e., Area, Perimeter.
    // A pure virtual function is set to zero in its prototype.
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    
// protected items can be accessed directly
// from a derived class but not, for example,
// in main.    
protected:
    double area;
    double perimeter;
};

// Derive Rectangle from Shape.
class Rectangle: public Shape {
protected:
    double width;
    double height;

private:    
    // Override virtual function Area in the base class Shape.
    double Area() const { return width*height; }
    // Override virtual function Perimeter in the base class Shape.
    double Perimeter() const { return 2.0*(width + height); }    
    
public:
    // This constructor shows another way to initialize
    // member variables width and height.  The notation
    // after the colon : width(w), height(h) initializes
    // private member variables width to w and height to h.
    Rectangle(const double w, const double h) : width(w), height(h)
    {
        // The constructor can access area and perimeter
        // directly because they are protected and class
        // Rectangle is derived from Shape.  If you declare
        // area and perimeter as private in Shape it causes
        // a compiler error.
        area = Area();
        perimeter = Perimeter();
    }
    
    void print() const {
        cout << "width=" << width << " height=" << height << endl;
        // Function print can access area and perimeter
        // directly because they are protected and class
        // Rectangle is derived from Shape.  If you declare
        // area and perimeter as private in Shape it causes
        // a compiler error.        
        cout << "area=" << area << endl;
        cout << "perimeter=" << perimeter << endl;        
    }
};

class Square: public Rectangle {
public:   
    Square(const double side) : Rectangle(side, side) { }
    
    void print() const {
        // Class Square can access width directly because
        // width is a protected member variable of Rectangle
        // and Square is derived from Rectangle.  If you declare
        // width as private you get a compiler error.  Similar
        // remarks apply to area and perimeter.
        cout << "side= " << width << endl;
        cout << "area=" << area << endl;
        cout << "perimeter=" << perimeter << endl;        
    }
};

// Derive Circle from Shape.
class Circle: public Shape {
private:
    double radius;
    
    // Override virtual function Area in the base class Shape.
    double Area() const { return M_PI*radius*radius; }
    // Override virtual function Perimeter in the base class Shape.
    double Perimeter() const { return 2.0*M_PI*radius; }
    
public:
    // This constructor shows another way to initialize
    // member variables width and height.  The notation
    // after the colon : radius(r) initializes private
    // member variable radius to r.
    Circle(const double r) : radius(r)
    {
        // The constructor can access area and perimeter
        // directly because they are protected and class
        // Circle is derived from Shape.  If you declare
        // area and perimeter as private in Shape it causes
        // a compiler error.        
        area = Area();
        perimeter = Perimeter();        
    }
    
    void print() const {
        cout << "radius=" << radius << endl;
        // Class Circle can access area and perimeter directly
        // because they are protected member variables of Shape
        // and Circle is derived from Shape.  If you declare
        // area or perimeter as private you get a compiler error.
        cout << "area=" << area << endl;
        cout << "circumference=" << perimeter << endl;
    }
};

#endif	/* SHAPE_H */

