// Author: Mary Smith
// Course: CMPSC 3543
// Example 9: Illustrates class inheritance.  When a
//            class is derived from another class it
//            shares common characteristics with the
//            class it is derived from, it inherits
//            those characteristics.  In addition, it
//            may have other characteristics and is
//            considered a special case of the class
//            it is inherited from.
//
//            Unlike previous examples, in example 9
//            only member function prototypes are in
//            the header file while their implementation
//            is in a separate C++ source file (.cpp
//            extension).  Putting member variable declarations
//            and function prototypes in a header file and the
//            function implementations in a separate C++ source
//            file is the more common organization for lagrer
//            programs.
//            
//            This example also illustrates enumerators
//            and assertions.

#include "Student.h"
#include <string.h>
#include <assert.h>
#include <iostream>     // needed for cout and cerr

using namespace std;

Student::Student(const char* name, const int ID, const double GPA, year y)
{
    assert( strlen(name) < NSIZE );
    strcpy(this->name,name);
    this->ID = ID;
    this->GPA = GPA;
    this->y = y;
}

void Student::print() const
{
    cout << "Name: \t\t" << name << endl;
    cout << "Student ID:\t" << ID << endl;
    cout << "GPA: \t\t" << GPA << endl;
    cout << "Year: \t\t";
    switch( y ) {
        case freshman:
            cout << "freshman";
            break;
        case sophomore:
            cout << "sophomore";
            break;
        case junior:
            cout << "junior";
            break;
        case senior:
            cout << "senior";
            break;
        case grad:
            cout << "grad student";
            break;
        default:
            cout << "unknown";
            break;            
    }
    cout << endl;
}

GradStudent::GradStudent(const char* name, const int ID, const double GPA, year y,
                         support s, const char* department, const char* thesis)
            : Student(name,ID,GPA,y)
{
    this->s = s;
    assert( strlen(department) < DSIZE );
    strcpy(this->department,department);
    assert( strlen(thesis) < TSIZE );
    strcpy(this->thesis,thesis);
}

void GradStudent::print() const
{
    Student::print();

    cout << "Support: \t";
    switch( s ) {
        case ta:
            cout << "teaching assistant";
            break;
        case ra:
            cout << "research assistant";
            break;
        case fellowship:
            cout << "fellowship";
            break;
        case other:
            cout << "other";
            break; 
        default:
            cout << "unknown";
            break;            
    }
    cout << endl;

    cout << "Department: \t" << department << endl;
    cout << "Thesis:\t\t" << thesis << endl;
}