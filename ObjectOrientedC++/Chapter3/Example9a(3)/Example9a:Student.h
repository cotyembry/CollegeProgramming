/* 
 * File:   Student.h
 * Author: Mary Smith
 * Course: CMPSC 3543
 * /
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
/*
 *
 * Created on November 22, 2014, 10:36 AM
 */

#ifndef STUDENT_H
#define	STUDENT_H

enum support { ta, ra, fellowship, other };
enum year { freshman, sophomore, junior, senior, grad };

const int NSIZE = 30;
const int DSIZE = 20;
const int TSIZE = 80;

class Student {
public:
    Student(const char* name, const int ID, const double GPA, year y);
    void print() const;
    // Mary will implement member function setName at a future time.
    // Note that setName does not have to be in implementation file
    // Student.cpp and the program can compile and run.
    void setName(const char* name);
private:
    int     ID;                 // student ID
    double  GPA;                // grade point average
    year    y;                  // year
    char    name[NSIZE];        // name
};

class GradStudent: public Student {
public:    
    GradStudent(const char* name, const int ID, const double GPA, year y,
                support s, const char* department, const char* thesis);
    void print() const;
    // Mary will implement member function getSupport at a future time.
    // Note that getSupport does not have to be in implementation file
    // Student.cpp and the program can compile and run.
    const support getSupport() const;
private:
    support s;                  // tuition support
    char    department[DSIZE];  // department
    char    thesis[TSIZE];      // thesis title
};

#endif	/* STUDENT_H */

