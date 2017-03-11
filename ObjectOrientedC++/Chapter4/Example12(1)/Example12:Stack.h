/* 
 * File:   Stack.h
 * Author: Mary Smith
 * Course: CMPSC 3543
 * Example 12: Like example 11 except class Stack
 *             has its member variables and member
 *             function prototypes in header file
 *             Stack.h and the implementation (code)
 *             of the member functions in implementation
 *             file Stack.cpp.
 *
 * Created on November 26, 2014, 8:28 AM
 */

#ifndef STACK_H
#define	STACK_H

template <class TYPE>
class Stack {
private:
    enum { EMPTY = -1 };
    TYPE* s;
    int max_len;
    int top;
public:
    // If no parameter is passed to the constructor
    // the parameter size takes the default value 20.
    Stack(const int size = 20);
    
    // The following is a destructor.  A destructor
    // begins with the tilde symbol ~ followed by the
    // name of the class.  A destructor is used to
    // destroy, i.e., delete the object.  This destructor
    // deletes the stack.
    ~Stack();
    
    // Reset the stack to empty.
    void reset();
    
    // Push an item onto the stack.
    void push(const TYPE x);
    
    // Pop an item from the stack
    TYPE pop();
    
    // Get the item on the top of the stack
    TYPE getTop() const;
    
    // Determine whether the stack is empty.
    bool isEmpty() const;
    
    // Determine whether the stack is full.
    bool isFull() const;
};


#endif	/* STACK_H */

