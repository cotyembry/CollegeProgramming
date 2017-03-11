/* 
 * File:   Geometric.h
 * Author: cotyembry
 *
 * Created on March 29, 2015, 10:06 PM
 */

#ifndef GEOMETRIC_H
#define	GEOMETRIC_H
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

class Geometric {
public:
    
private:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
protected: //these can be accessed from a derived class, but not for example in
           //the main file
    double area;
    double perimeter;

};

class Triangle: public Geometric {
public:
    Triangle(const double x, const double y, const double z) : a(x), b(y), c(z) {
        perimeter = Perimeter();
        area = Area();        
    }
    void print() {
        cout << "side a\tside b\tside c\tarea\tperimeter\t" << endl;
        cout << a << "\t" << b << "\t" << c << "\t" << area << "\t" << perimeter << endl;
        cout << "\n";
    }
private:
    //this is for a triangle
    double Perimeter() const { return a + b + c; }
    
    double Area() const{
        double s = perimeter/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    
protected: 
    double a, b, c;
};

class Equilateral: public Triangle {
public:
    Equilateral(const double common) : Triangle(common, common, common) {
        this->common = common;
    }
    
    void print() const {
        cout << "common side\t" << common << endl;
        cout << "area\t\t" << area << endl;
        cout << "perimeter\t" << perimeter << endl;
        cout << "\n";
    }
private: 
    double common;
    
};

class Ellipse: public Geometric {
protected:
    double majorAxis; //idk what types these are suppose to me
    double minorAxis; //so I chose type double
public:
    Ellipse(double a, double b) : majorAxis(a), minorAxis(b) {
        perimeter = Perimeter();
        area = Area();
        
    }
    
    void print() const {
        cout << "majorAxis = " << majorAxis << " minorAxis = " << minorAxis << " area = " << area << " perimeter = " << perimeter << endl;
        cout << endl;
    }
    
private:
    double Perimeter() const {
        return (2*M_PI)*sqrt( ((majorAxis*majorAxis)+(minorAxis*minorAxis)) / 2);
    }

    double Area() const { return M_PI*majorAxis*minorAxis; }

};

class Circle: Ellipse {
public:
    Circle(double r) : Ellipse(r, r), radius(r) {
    }
    
    void print() const {
        cout << "radius = " << radius << " perimeter = " << perimeter << " area = " << area << endl;
        cout << endl;
    }
protected:
    double radius;
};

#endif	/* GEOMETRIC_H */

