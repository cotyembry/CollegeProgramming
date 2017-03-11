/* 
 * File:   main.cpp
 * Author: Coty Embry
 * Course/Class: OOP 3543
 * Created on January 21, 2015, 2:09 PM
 * Program comment: this program will ask the user for an angle in degrees, convert it to radians, then output the correct answer. If the user enters 0 the program will end.
 */

#include <cstdlib>
#include <iostream>

using namespace std;
//This is somewhat equivalent to a #define in C.
inline const double convert(const double degree) { return degree*0.0174532925; }

int main(int argc, char** argv) {
    double degree = 0;
    do {
        cout << "\nHint: If you want to exit enter 0\n" << endl;
        cout << "Input angle in degrees: ";
        cin >> degree;
        
        if (degree == 0)
                cout << "Bye!" << endl;
        
        else { 
                //this uses the inline function to send the variable 'degree' to the convert routine which returns an answer.
                cout << "\nRadians is " << convert(degree) << " rads.\nwhere " << degree << " is the angle in radians." << endl;

        }        
    } while (degree > 0);
        return 0;
}