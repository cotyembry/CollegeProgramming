/* 
 * File:   Employee.cpp
 * Author: cotyembry
 * 
 * Created on March 26, 2015, 10:47 AM
 */

#include <cstdlib>
#include <iostream>
#include "Employee.h"
#include <assert.h>
#include <string.h>



using namespace std;

Employee::Employee(const char* name, const char* SSN, building b, const int cubicle, const double salary) {
    assert(strlen(name) < NSIZE);
    assert(strlen(SSN) < SSN_SIZE);
    strcpy(this->name, name);
    strcpy(this->SSN, SSN);
    this->b = b;
    this->cubicle = cubicle;
    this->salary = salary;
}
//Employee(const char* name, const char* SSN, building b, const int cubicle, const double salary);

void Employee::print() const {
    cout << "name\t\t" << name << endl;
    cout << "SSN\t\t" << SSN << endl;

    switch(b) {
        case 0:
            cout << "building\twarehouse" << endl;
            break;
        case 1:
            cout << "building\tadministration" << endl;            
            break;
        case 2:
            cout << "building\tresearch" << endl;            
            break;
        case 3:
            cout << "building\tbusiness" << endl;            
            break;
        case 4:
            cout << "building\tmaintenance" << endl;            
            break;
        case 5:
            cout << "building\tother" << endl;            
            break; 
        default:
            cout << "building\tnone" << endl;
            break;
    }

    cout << "salary\t\t" << salary << endl;
    cout << "\n";
}

Supervisor::Supervisor(const char* name, const char* SSN, building b, const int cubicle, const double salary, const char* department, section s, const int projects) : Employee(name, SSN, b, cubicle, salary) {
    assert(strlen(department) < DSIZE);
    strcpy(this->department, department);
    this->s = s;
    this->projects = projects;
}

void Supervisor::print() const { //the const makes sure that nothing gets changed
    Employee::print();
    cout << "department\t" << department << endl;
    cout << "section\t\t" << s << endl;
    cout << "projects\t" << projects << endl;
    cout << "\n";
 }
