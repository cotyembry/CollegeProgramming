/* 
 * File:   main.cpp
 * Author: Mary Smith
 * Course: CMPSC 3543
 * Example 9
 *
 * Created on November 22, 2014, 10:24 AM
 */

// To compile and run this program WITHOUT
// Netbeans do the following.
//
//  g++ -c Student.cpp
//  g++ -o Example9 Student.o main.cpp
//
// The first command compiles Student.cpp 
// and creates object file Student.o which
// is needed to compile main.cpp.  The second
// command compiles main.cpp to create executable
// file Example9

#include <cstdlib>
#include <iostream>     // needed for cout and cerr
#include "Student.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Student Mary("Mary Smith",320175,3.6,sophomore);
    Mary.print();
    cout << "\n";
    Student Alan("Alan Turing",290007,3.4,freshman);
    Alan.print();
    cout << "\n";
    GradStudent Sue("Sue Brown",147021,3.9,grad,ta,
                    "Mathematics","Riemann Hypothesis");
    Sue.print();
    return 0;
}

