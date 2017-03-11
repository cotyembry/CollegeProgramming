/* 
 * File:   Set.h
 * Author: Coty
 *
 * Created on February 22, 2015, 9:07 PM
 */
#include <cstdlib>
#include <iostream>

#ifndef SET_H
#define	SET_H

using namespace std;

class Set {
    private: 
        double* set;
        int number;
    public:
        //creates an empty double array
        Set() {
            number = 1;
            set = new double[number];//this is dynamically creating an array
            set[0] = 0;
            cout << "An empty set will be created." << endl;
        }

        Set(const int number, const double *set) {        
            int i;
            if(number > 0) {
                this->number = number;            
                this->set = new double[number]; //dynamically allocating an array
    //!Question, will this next line copy the array properly, or do I need to use a for loop?            
    //            this->set = set;
                //in perl you can say @newarray = @originalarray; I'm pretty sure
                for(i=0; i<=number; ++i) { 
                    this->set[i] = set[i];                
                }

                this->set[i] = 0;            
            }
            else if(number == 0) {
                cout << "An empty set will be created";
                this->number = 0;
                this->set = new double[number];
                this->set[0] = 0;
            }

            else if(number < 0) {
                cerr << number << " must be greater than or equal to zero." << endl;
                cerr << "An empty set will be created." << endl;
                this->number = 0;
                this->set = new double[number];
                this->set[0] = 0;
            }
        }

        void print() const {
            for (int i=0; i < number; i++) {
                cout << set[i] << " ";
            }
            cout << "\n";
        }

        const int getNumber() const { return number; }       

        const double* getSet() const { return set; }

       void setSet(const int n, const double* s) { 
            int i=0;
            if((n == 0) || (s == NULL)) {
                cout << "An empty set will be created." << endl;
                delete []set;
                number = 0;
                set = new double[0];
                set[0] = 0;                                        
            }

            else if(n > 0) { 
                number = n;
                delete []set;
                set = new double[n];
                for(i=0; i <= n; ++i) {
                    set[i] = s[i];
                }
                set[i] = 0;                         
            }

            else if(n < 0) {
                cerr << n << " must be greater than or equal to zero." << endl;
                cerr << "An empty set will be created." << endl;
                delete []set;            
                number = 0;
                set = new double[number];
                set[0] = 0;            
            }                
        }
       
       int min(const int a, const int b) {
           if(a>b) return b;
           else return a;
       }
       
       int max(const int a, const int b) {
           if(a>b) return a;
           else return b;
       }
       
    //this is the set union
    friend Set operator+(const Set a, const Set b);
    
    //this is the set intersection
    friend Set operator*(const Set a, const Set b);

// Class Set has two friend functions that implement the operators + and *
// where + is set union and * is set intersection defined as follows.
// Consider two Set objects X and Y where
//  X = { -6.2, -3.1, 0.0, 1.9, 5.2, 8.3, 9.5, 10.7, 11.0, 12.5 }
//  Y = { -8.1, -3.1, 0.0, 2.5, 5.8, 8.3, 9.5, 11.0 }
// Then
//  X + Y = { -8.1, -6.2, -3.1, 0.0, 1.9, 2.5, 5.2, 5.8, 8.3, 9.5, 10.,7 11.0, 12.5 }
//  X * Y = { -3.1, 0.0, 8.3, 9.5, 11.0 }
// That is, X + Y is the union of set X with set Y and X * Y is the
// intersection of set X with set Y.
// For + and * you may assume that the sets X and Y are in ascending order.
// This makes the construction of X + Y and X * Y easier.  The sets X + Y
// and X * Y MUST also be in ascending order.  If you implement + and *
// correctly you will NOT have to do any sorting.  Ask the instructor if
// you have questions.   
};

Set operator+(const Set a, const Set b) {
    Set tempset;    
    double* pa = (double*)a.getSet();
    double* pb = (double*)b.getSet();
    int na = a.getNumber();
    int nb = b.getNumber();
    int mini = min(na,nb); //these min and max functions help me later on
    int maxi = max(na,nb); //when I go to combined the arrays together
    int sum = mini + maxi;
    int temp2length = sum;
    double temp[sum], temp2[sum]; //this is as big as my temp array needs to be

    int i, z=0, k=0;    
    for(i=0; i<mini; i++) {
        if(pa[i] < pb[i]) {            
            temp[z] = pa[i];
            z++;
            temp[z] = pb[i];
            z++;
        }
        else {
            temp[z] = pb[i];
            z++;
            temp[z] = pa[i];
            z++;
        }
    }

    while(i<maxi) {
        if(na>nb) {
            temp[z] = pa[i];
            i++; z++;
        }
        else {
            temp[z] = pb[i];
            i++; z++;
        }
    }

    for(int i=0; i<sum; i++) {
        if(temp[i] != temp[i+1]) {
            temp2[k] = temp[i];            
            k++;
        }
        else {
            temp2[k] = temp[i];            
            i++; k++;          
            temp2length--;
        }
    }
    temp2[temp2length] = 0; //this finishes the double array
    //now to return the Set object
    tempset.setSet(temp2length,temp2);
    return tempset;
}

Set operator*(const Set a, const Set b) {
    Set tempset;    
    double* pa = (double*)a.getSet();
    double* pb = (double*)b.getSet();
    int na = a.getNumber();
    int nb = b.getNumber();
    int mini = min(na,nb); //these min and max functions help me later on
    int maxi = max(na,nb); //when I go to combined the arrays together
    int sum=0;
    double temp[maxi]; //this is as big as my temp array needs to be

    int i, z=0;    
    for(i=0; i<maxi; i++) {
        if(na > nb) { //I just want to find the longest array here
            for(int t=0; t < mini; t++) {
                if(pa[i] == pb[t]) { //this will always look at the longest array
                    temp[z] = pb[t]; //number and compare to the shorter array
                    z++;
                    sum++; //this will keep track of how long the array is
                }
            }
            temp[z] = 0; //this finishes the double array
        }
        else {
            for(int t=0; t < mini; t++) {
                if(pb[i] == pa[t]) { //this will always look at the longest array
                    temp[z] = pa[t]; //number and compare to the shorter array
                    z++;
                    sum++; //this will keep track of how long the array is
                }
            }
            temp[z] = 0; //this finishes the double array
        }
    }     
    //now to return the Set object
    tempset.setSet(sum,temp);
    return tempset;
}    


#endif	/* SET_H */

