/* 
 * File:   main.cpp
 * Author: Mary Smith
 * Course: 3543
 * Example 10: Illustrates an abstract base
 *             class that contains virtual
 *             functions and protected member
 *             variables.
 *
 * Created on November 22, 2014, 3:34 PM
 */

#include <cstdlib>
#include "Shape.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Rectangle window(5.2,4.5);
    window.print();
    cout << endl;
    
    Square slab(4.3);
    slab.print();
    cout << endl;    
    
    Circle plate(2.5);
    plate.print();
    cout << endl;
    
    Rectangle* frame = new Rectangle(2.2,8.5);
    frame->print();
    cout << endl;      
    delete frame;  
    
    Circle* hoop = new Circle(3.2);
    hoop->print();
    delete hoop;   
    
    // The following statement causes a
    // compiler error if it is uncommented
    // because Shape is an abstract class
    // and an abstract class CANNOT have
    // have an object delared for it.
    //Shape object;
    
    // The following statement causes an error
    // if it is uncommented because perimeter
    // is a protected member variable of Shape.
    //cout << "window's boundary=" << window.perimeter << endl;
    
    return 0;
}

// Assignment 4 (25 points): This assignment is similar
//  to examples 9 and 10.  For assignment 4, create a 
//  project that contains two C++ header files named,
//  Employee.h and Geometric.h, and a C++ implementation
//  C++ source file named Employee.cpp.  Create these
//  three files in addition to the file main.cpp that is
//  used to test the C++ classes.
//
//  First, consider header file Employee.h and its implementation
//  file Employee.cpp.  Declare a class named Employee in header
//  file Employee.h and write the implementation (code) for the
//  member functions in C++ source file Employee.cpp, similar to
//  what was done for example 9 with files Student.h and Student.cpp.
//  To get full credit you MUST only declare member function prototpyes
//  for class Employee in the header file Employee.h and put their
//  implementation (code) in file Employee.cpp.
//
//  Header file Employee.h contains the following enumerations.
//   enumeration  elements
//   building     warehouse, administration, research, business, maintenance, other
//   section      executive, sales, marketing, software, engineering
//
//  Header file Employee.h defines the following integer constants.
//   constant    value      description
//   NSIZE          30      size of name string
//   SSN_SIZE       12      size of social security string
//   DSIZE          20      size of department string
//
//  Class Employee has a single constructor that has the following 5 parameters.
//  parameter   type            description
//  name        const char*     employee name having up to NSIZE-1 characters
//  SSN         const char*     social security number (with -) having exactly
//                              11 characters
//  b           building        a building enumeration value
//  cubicle     const int       cubicle number
//  salary      const double    salary
//
//  The prototype of constructor Employee MUST be declared in
//  header file Employee.h and its implementation (code) MUST
//  be in implementation file Employee.cpp, similar to what was
//  done in example 9 with the constructor for Student.

//  Class Employee has the following 5 private member variables.
//  type        variable       description
//  char        SSN[SSN_SIZE]  social security number
//  building    b              building
//  int         cubicle        cubicle
//  char        name[NSIZE]    name
//  double      salary         salary
//
// The names of the private member variables and parameters passed to the
// constructor MUST be the same.  Use the this-> operator to reference the
// private member varaibles, similar to what was done in example 9.
//
// Constructor Employee initializes the private member variables from
// the parameters passed to it.  Use assertions to ensure that the
// string length of the name and SSN passed as a parameter do not exceed
// NSIZE and SSN_SIZE, respectively.  You MUST use assertions to get full
// credit.
//
// Declare a public member function named print in class Employee.
// Function print displays an employee name, SSN, building, cubicle
// and salary.  Put the implementation (code) for print in file
// Employee.cpp.  Function print should use tabs to display this
// information, similar to how it was displayed in example 9.  You
// MUST use tabs to align all displayed information similar to what
// was done in example 9 to get full credit.
//
// Header file Employee.h will also contain a second class named
// Supervisor that is an inherited class.  Class Supervisor is
// inherited from class Employee.
//
// Class Supervisor has a single constructor that has the following 8
// parameters.
//  parameter   type            description
//  name        const char*     employee name having up to NSIZE-1 characters
//  SSN         const char*     social security number (with -) having exactly
//                              11 characters
//  b           building        a building enumeration value
//  cubicle     const int       cubicle number
//  salary      const double    salary
//  department  const char*     department being supervised
//  s           section         section being supervised (enumeration value)
//  projects    const int       number of projects being supervised
//
//  The prototype of constructor Supervisor MUST be declared in
//  header file Employee.h and its implementation (code) MUST
//  be in implementaion file Employee.cpp, similar to what was
//  done in example 9 with the constructor for GradStudent.

//  Class Supervisor has the following 3 private member variables.
//  type        variable            description
//  char        department[DSIZE]   department being supervised
//  section     s                   section being supervised
//  int         projects            number of projects being supervised
//
// The names of the private member variables and parameters passed to the
// constructor MUST be the same.  Use the this-> operator to reference the
// private member varaibles, similar to what was done in example 9.
//
// Constructor Supervisor initializes the private member variables from
// the parameters passed to it.  The Supervisor constructor calls the
// Employee constructor similar to what was done in example 9.  Use an
// assertion to ensure that the string length of the department passed
// as a parameter do not exceed DSIZE.  An assertion MUST be used in order
// to get full credit.
//
// Declare a public member function named print in class Supervisor.
// Function print calls the print function for class Employee to
// display a supervisor name, SSN, building, cubicle and salary. 
// In addition, print displays the department, section and number
// of projects the supervisor manages.  Put the implementation (code)
// for print in file Employee.cpp.  Function print should use tabs to
// display this information, similar to how it was displayed in example 9.
// To get full credit, use tabs to align all displayed information.
//
// Now consider header file Geometric.h.  This file is similar to
// Shape.h in example 10.  File Geometric.h contains an abstract
// base class named Geometric that is almost identical to the base
// abstract class Shape in Shape.h.  Class Geometric has two private
// pure virtual functions named Area and Perimeter.  It also contains
// two protected double variables named area and perimeter.
//
// File Geometric will also contain two classes named Triangle and
// Ellipse that are inherited from Geometric.  First, consider class
// Triangle.  Class Triangle has 3 protected doubles named a, b and c
// which represent the 3 sides of a triangle.  Class Triangle has two
// private member functions named Area and Perimeter which each return
// a double.  Function Area calculates the area of a triangle having
// sides a, b and c.  Function Perimeter calculates the perimeter of
// a triangle with sides a, b and c.  The formulas for area and perimeter
// are given in a separate document.  The implememntation (code) for
// functions Area and Perimeter are put in header file Geometric.h.
//
// Class Triangle contains a public constructor and print function.
// The constructor is passed 3 constant double parameters x, y and z,
// and it initializes the protected variables a, b and c with the
// values of x, y and z, respectively.  The constructor then calls
// private functions Area and Perimeter to calculate the area and
// perimeter of the triangle and stores the values in protected member
// variables area and perimeter, respectively, of base class Geometric.
// The print function displays the sides a, b and c of the triangle,
// and the area and perimeter of the triangle.  The implementation (code)
// for the constructor and print function are put in header file Geometric.h.
//
// Another class named Equilateral is derived from class Triangle
// and it represents an equilateral triangle, i.e., a triangle
// all of whose sides are equal (have the same length).
// Class Equilateral has a public constructor and print function.
// The constructor has a single constant double parameter that is
// the length of the common side.  The constructor calls the
// Triangle constructor, passing the common side for all three
// parameters of the Triangle constructor.  The print function
// displays the common side of the tirangle, together with the
// area and perimeter of the triangle.
//
// The second class in Geometric.h that is derived from base class
// Geometric is class Ellipse.  Class Ellipse represents an ellipse.
// Class Ellipse has two protected member variables named majorAxis
// and minorAxis.  They represent the major and minor axes of an ellipse.
// Class Ellipse has two private member functions named Area and
// Perimeter that calculate the area and perimeter (also called the
// circumference) of an ellipse.  The formulas for area and perimeter
// are given in a separate document.
//
// Class Ellipse has a public constructor and print function.  The
// constructor has two parameters, the major and minor axes of the
// ellipse.  The constructor uses the parameters to initialize protected
// member variables majorAxis and minorAxis, respectively.  Then the
// constructor calls private functions Area and Perimeter to calculate
// the area and perimeter of the ellipse and store the results in
// protected member variables area and perimeter of base class Geometric.
// The public print function displays the major and minor axes of the
// ellipse, together with the area and perimeter (also called the
// circumference) of the ellipse.
//
// Another class named Circle is derived from class Ellipse.  Class
// circle has a public constructor and print function.  The constructor
// has a single parameter, which is the radius of the circle.  The
// constructor calls the Ellipse constructor, passing it the radius
// for both the major and minor axis.  The print function prints the
// radius, together with the area and perimeter (also called the
// circumference) of the circle.

// To test the classes in files Employee.h, Employee.cpp and
// Geometric.h, the main function in file main.cpp must do the
// following.
//  1. Create an Employee object named Sarah by passing the following
//     information to the Employee constructor.
//     name            SSN          building    cubicle     salary    
//     Sarah Miller    789-01-5029  business    15          $56,805

//  2. Print the Sarah object.

//  3. Create a Supervisor object named Sue by passing the following
//     information to the Supervisor constructor.
//     name            SSN          building    cubicle     salary    
//     Sue Ackerman    201-33-8710  research    4           $71,020
//
//     department           section      projects
//     Flight Simulator     software     6

//  4. Print the Sue object.

//  5. Create a Triangle object named arrow_head by passing the following
//     information to the Triangle constructor.
//     a        b       c
//     4.0      3.0     5.0

//  6. Print the arrow_head object.

//  7. Create an Equilateral object named sign by passing the following
//     information to the Equilateral constructor.
//     side 
//     7.2

//  8. Print the sign object.

//  9. Create an Ellipse object named oval by passing the following
//     information to the Ellipse constructor.
//     major axis       minor axis
//     5.0              2.0

// 10. Print the oval object.

// 11. Create a Circle object named ring by passing the following
//     information to the Ellipse constructor.
//     radius
//     4.5

// 12. Print the ring object.

// 13. Create a Triangle object by using the new operator and a pointer
//     as follows.
//     Triangle* t = new Triangle(5.2,4.6,5.2);

// 14. Print the Triangle object pointed to by t.
//
// When you complete assignment 4, compress your Netbeans project and
// submit your compressed file to Blackboard on or before the due date.
// The due date will be posted on Blackboard and announced in class.
//
// If you DO NOT use Netbeans put files Employee.h, Employee.cpp,
// Geometric.h and main.cpp in a directory named Assignment4.  Then
// compress Assignment4 and submit the compressed file to Blackboard.
// Submit your compressed file to Blackboard on or before the due date.
// The due date will be posted on Blackboard and announced in class.