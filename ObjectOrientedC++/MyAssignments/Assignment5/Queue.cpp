/* 
 * File:   Queue.cpp
 * Author: John Coty Embry
 * Course: CMPSC 3543
 * Assignment 5
 * Created on April 13, 2015, 9:32 AM6
 */
#include <iostream>
#include "Queue.h"
#include <assert.h>

using namespace std;

template <class TYPE>
    Queue<TYPE>::Queue(const int size) : max_len(size) {
        s = new TYPE[max_len];
        number = 0;
        head = max_len - 1;
        tail = 0;
    }

template <class TYPE>
    void Queue<TYPE>::enqueue(const TYPE x) {
        if(!isFull()) {            
            s[head = (head+1)%max_len] = x; //this should increment appropriately
        }
        else {
            int len_help = max_len; //this will be used for the copy 
            max_len = max_len*2;
            TYPE* t = new TYPE[max_len]; //making a new temp array
            int i = tail; //we want to make sure to start the new array correctly
            int ti = 0; //this will be used for the new array incrementation
            int occurrance = 0; //this will mark the ending of the array copy
            
            while(occurrance == 0) {  
                t[ti] = s[i]; //this will put the smaller array elements in the larger one                
                i = (i+1) % len_help; //this makes sure the increment the original array correctly
                ti++;
                if(i == tail) {
                    occurrance++;
                }
            }
            head = ti; //ti falls right in place for the head of the array since it post incremented in the above while loop
            t[head] = x;
            number++;//this keeps track of how many are in the array
            tail = 0;
            s = t;          
            cout << "\nThe Queue was full\nReallocated " <<
                max_len << " queue elements and copied queue to reallocated space.\n"<< endl;
 }
        number++; //this keeps track of how many numbers are in the queue        
                  //it decrements in the dequeue
    }
template <class TYPE>    
    TYPE Queue<TYPE>::dequeue(void) {
            //I don't need to check if the queue is empty because the checking is done
            //in the main program
            number--;
            TYPE temp = s[tail];
            tail = (tail+1) % max_len;
            return temp;
}

template <class TYPE>                            
    Queue<TYPE>::~Queue() {
        delete []s;
    }

template <class TYPE>
    bool Queue<TYPE>::isFull() const {
        return number >= max_len; //bc if it equals it, it is full
    }
template <class TYPE>
    bool Queue<TYPE>::isEmpty() const {
        if(number == 0) {
            cout << "Queue is Empty!" << endl;
        }
        return number == 0;
    }

template <class TYPE>
    TYPE Queue<TYPE>::print() const {
    if(s[0] == NULL)
        cout << "NULL" << endl;
    for(int j=0; j <= max_len-1; j++){
        cout << s[j] << endl;
    }
}

template <class TYPE>
    TYPE Queue<TYPE>::getHead() const {
    return s[head];
    }

template <class TYPE>
    TYPE Queue<TYPE>::getTail() const {
    return s[tail];
}


