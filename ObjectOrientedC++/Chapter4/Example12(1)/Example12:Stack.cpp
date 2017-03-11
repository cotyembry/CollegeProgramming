/* Author: Mary Smith
 * Course: CMPSC 3543
 * Example 12: Like example 11 except class Stack
 *             has its member variables and member
 *             function prototypes in header file
 *             Stack.h and the implementation (code)
 *             of the member functions in implementation
 *             file Stack.cpp.
 */
#include "Stack.h"

// If no parameter is passed to the constructor
// the parameter size takes the default value 20.
template <class TYPE>
    Stack<TYPE>::Stack(const int size) : max_len(size)
    { s = new TYPE[size]; top = EMPTY; }
   
// The following is a destructor.  A desctructor
// begins with the tilde symbol ~ followed by the
// name of the class.  A destructor is used to
// destroy, i.e., delete the object.  This destructor
// deletes the stack.
template <class TYPE>
    Stack<TYPE>::~Stack() { delete []s; }
    
// Reset the stack to empty.
template <class TYPE>
    void Stack<TYPE>::reset() { top = EMPTY; }
    
// Push an item onto the stack.
template <class TYPE>
void Stack<TYPE>::push(const TYPE x) { s[++top] = x; }
    
// Pop an item from the stack
template <class TYPE>
    TYPE Stack<TYPE>::pop() { return s[top--]; }
    
// Get the item on the top of the stack
template <class TYPE>
    TYPE Stack<TYPE>::getTop() const { return s[top]; }
    
// Determine whether the stack is empty.
template <class TYPE>
    bool Stack<TYPE>::isEmpty() const { return top == EMPTY; }
    
// Determine whether the stack is full.
template <class TYPE>
    bool Stack<TYPE>::isFull() const { return top == max_len-1; }

