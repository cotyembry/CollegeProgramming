/* 
 * File:   Employee.h
 * Author: cotyembry
 *
 * Created on March 26, 2015, 10:30 AM
 */

#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

enum building {warehouse, administration, research, business, maintenance, other};
enum section {executive, sales, marketing, software, engineering};

const int NSIZE = 30;       //size of name string
const int SSN_SIZE = 12;    //size of social security number
const int DSIZE = 20;

class Employee {
public:
    //this is the prototype for the Employee constructor
    Employee(const char* name, const char* SSN, building b, const int cubicle, const double salary);
    void print() const;
    // Function print displays an employee name, SSN, building, cubicle
    // and salary.
private:
    char SSN[SSN_SIZE];
    building b;
    int cubicle;
    char name[NSIZE];
    double salary;

};

class Supervisor: public Employee {
public:
    Supervisor(const char* name, const char* SSN, building b, const int cubicle, const double salary, const char* department, section s, const int projects);
    void print() const;
private:
    char department[DSIZE];
    section s;
    int projects;
};

#endif	/* EMPLOYEE_H */

