/* 
 * File:   main.cpp
 * Author: Mary Smith
 * Course: CMPSC 3543
 * Example 12: Like example 11 except class Stack
 *             has its member variables and member
 *             function prototypes in header file
 *             Stack.h and the implementation (code)
 *             of the member functions in implementation
 *             file Stack.cpp.
 *
 * Created on November 26, 2014, 8:27 AM
 */

#include <cstdlib>
#include <iostream>     // needed for cout and cerr
#include <string.h>
#include "Stack.h"
#include "Stack.cpp"    // This seems to be required if
                        // the template class member
                        // functions are in a separate
                        // implementation file like Stack.cpp
#include "Point.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    // It appears that the stack size must
    // be passed to the constructor.
    Stack<char> c_stack(10);
    
    c_stack.push('e'); c_stack.push('k'); c_stack.push('a'); c_stack.push('t');
    while ( !c_stack.isEmpty() ) cout << c_stack.pop() << " ";
    cout << endl;

    const char* word = "racecar";
    for( int i = 0; i < strlen(word); ++i ) c_stack.push(word[i]);
    while ( !c_stack.isEmpty() ) cout << c_stack.pop() << " ";
    cout << endl;    
    
    // It appears that the stack size must
    // be passed to the constructor.    
    Stack<float> f_stack(15);
    
    f_stack.push(3.1); f_stack.push(-0.8); f_stack.push(7.4); f_stack.push(8.9);
    while ( !f_stack.isEmpty() ) cout << f_stack.pop() << " ";
    cout << endl;
x
    const float a[] = { 4.0, -6.5, 2.9, -7.4, 0.0, -3.5 };    
    for( int i = 0; i < sizeof(a)/sizeof(float); ++i ) f_stack.push(a[i]);
    while ( !f_stack.isEmpty() ) cout << f_stack.pop() << " ";
    cout << endl;

    Point polygon[] = { Point(5,2), Point(-1.5,3), Point(0,2), Point(7,-1) };
    const int p_size = sizeof(polygon)/sizeof(Point);
  
    Stack<Point> pstack(8);
    for( int i = 0; i < p_size; ++i ) pstack.push(polygon[i]);
    while( !pstack.isEmpty() ) pstack.pop().print(); 

    return 0;
}

// Assignment 5 (25 points): In this assignment you are asked to
//  create a template class named Queue the implements a circular
//  queue.  A circular queue will be explained in more detail in
//  lecture.  In any queue, whether it is circular or not, items
//  are placed on the queue at one end, sometimes referred to as
//  the head of the queue, and taken off the queue at the other
//  end, soemtimes referred to as the tail of the queue.  A queue
//  simulates such things as customers waiting to be serviced by
//  a bank teller, automobiles pulling up to a toll booth, customers
//  pulling up to a fast food drive through, etc.  The first customer,
//  car, etc. to enter the queue, is the first one taken off the queue
//  to be serviced.
//
//  The template class Queue will be written similar to example 12.
//  Class Queue will have its member variables and member function
//  prototypes declared in a header file named Queue.h and have its
//  member function implementation (code) in a separate C++ source
//  file named Queue.cpp.
//
//  First, consider header file Queue.h.  In this file declare the
//  following private member variables.
//
//  variable        type        description
//
//  max_len         int         maximum length of the queue array
//  number          int         number of elements currently in the queue
//  head            int         index of the head of the queue
//  tail            int         index of the tail of the queue
//  s               TYPE        array containing queue elements of generic
//                              type TYPE
//
//  The queue elements are stored in an array, similar to how elements
//  in a stack were stored in examples 11 and 12.  Template class Queue
//  will have one constructor declared in Queue.h that takes a single
//  parameter that MUST be given a default value of 10.  To get full
//  credit you MUST give the parameter a default value of 10.  Template
//  class Queue has one destructor.  To get full credit you MUST declare
//  a destructor in class Queue in Queue.h.
//
//  The following public member functions for class Queue are declared in
//  Queue.h.
//
//  function        parameters          description
//
//  enqueue         const TYPE x        put x at the head of the queue.
//                                      enqueue has no return value.
//  dequeue         none                take an item off the tail of the
//                                      queue.  dequeue has return type TYPE.
//  isFull          none                determnes whether the queue is full.
//                                      isFull returns a bool value.
//  isEmpty         none                determines whether the queue is empty.
//                                      isEmpty returns a bool value.
//  getHead         none                get the item at the head of the queue.
//                                      getHead has return tye TYPE.
//  getTail         none                get the item at the tail of the queue.
//                                      getTail has return tye TYPE.
//
// Now Consider the implementation code in Queue.cpp.  The constructor
// is passed a single parameter which determines the size of the queue.
// This parameter MUST be given the default value 10 in the prototype
// in file Queue.h.  In Queue.cpp, the constructor code takes the parameter
// and initializes max_len with it.  

// The constructor then allocates space
// for a new array of size max_len of type TYPE and sets number to zero
// since initially the queue is empty.  Then head is set to max_len-1 and
// tail to zero.  In a circular queue that is how head and tail are
// initialized.  

// As items are placed on and taken off the queue, head and
// tail are icremented and are viewed as "chasing" one another around the
// circular queue (refer to the discussion given during lecture).
//
// The destructor code in Queue.cpp deletes the space alllocated to array s
// thereby deleting the queue.
//
// Member function enqueue puts an item, passed as a parameter, at the head
// of the queue, provided the queue is not full.  Function enqueue first
// checks to see if the queue is full.  If the queue is not full, it increments
// number, increments head modulo max_len (ask the instructor what this means
// if this is not clear) and stores the item placed in the queue at index
// head.  If the queue is full, enqueue allocates space for a new array t
// of size twice the value of max_len.  It then copies all elements from s
// to t.  It updates max_len to the size of the new array t, deletes s and
// sets s to t.  Then it displays the following two messages
//
//  The queue was full.
//  Reallocated xxx queue elements and copied queue to reallocated space.
//
// where xxx was the new number of elements in the newly allocated queue.
// After Updating the queue, it then places the item in the new queue.
// That is, it does what it normally does when the queue is not full, namely,
// it increments number, increments head modulo max_len (using the new value
// of max_len) and stores the item placed in the queue at index head.
//
// Now consider member function dequeue.  This function checks to determine
// whether the queue is empty.  If the queue is empty, it simply returns.
// If the queue is not empty, it gets the item at index tail, increments
// tail modulo max_len and returns the item obtained from the queue.
//
// Member function getHead returns the item in the queue at index head,
// provided the queue is not empty.
//
// Member function getTail returns the item in the queue at index tail,
// provided the queue is not empty.
//
// Member function isEmpty returns true if the queue is empty and false
// otherwise.
//
// Member function isFull returns true if the queue is full and false
// otherwise.
//

//im here
// Now consider the code in function main.cpp that tests your template
// class Queue.  Function main in main.cpp creates a queue of characters
// of size 8.  It then stores the name Sally into the queue, one letter
// at a time.  It then empties the queue by taking (dequeuing) one letter
// at a time until the queue is empty.  Do NOT assume that 5 items are in
// the queue.  Dequeue items until the queue becomes empty and use member
// function isEmpty to determine when the queue becomes empty.  Display
// letters taken from the queue all on a single line separated by a space.
// A name like Sally would display as
//      S a l l y
// Note that, unlike a stack, a queue does not reverse the order of items.
// Next, create a queue of doubles of size 4.  Then delcare a double array
// having the following numbers in it.
//       0.8, -1.7, 5.0, 2.2, 9.6, -5.3
// Put the numbers in the queue in the above order.  Note that this will
// make member function enqueue allocate a new queue of size 8 because
// an initial queue of size 4 cannot hold the 6 numbers above.  Consequently,
// your program should display the following messages as output.
//
//  The queue was full.
//  Reallocated 8 queue elements and copied queue to reallocated space.
//
// Why were 8 queue elements reallocated in this case?  After all 6 numbers
// are placed in the queue, empty the queue, displaying each number taken
// from the queue on a single line, each separated by a space.  Dequeue
// items from the queue until it is empty.  Do not assume that 6 numbers
// were in the queue.  Us member function isEmpty to determine when the
// queue is empty.
//
// Next, function main creates a queue of size 3.  The elements stored in
// the queue are objects of class Order.  To complete this part, you need
// to create a new header file for the project named Order.h.  In Order.h
// declare a new class named Order.  Class Order will not be a template
// class.  Class Order will serve a role similar to what class Point did
// in example 12.  Class Order will have the following private member
// variables.
//
//  variable    type        description
//
//  number      int         order number for a meal at a fast food restaurant
//  price       float       price of a meal
//  meal        char[DSIZE] character array that describes a meal where DSIZE
//                          is a constant integer having the value 80
//
// Class Order will have two constructors and a public print function.  The
// first constructor has no parameters.  It sets private member variables
// number and price to zero, and initializes character meal as meal[0]=0.
// This essentialy makes meal the empty string.  The second constructor
// has 3 constant parameters n, p and m.  Parameter n is a constant integer
// that is an order number.  




//im here
//Parameter p is a constant float that is the
// price of a meal.  !!Parameter m is a constant character pointer that points
// to a character string that describes a meal.  Parameters n, p and m are
// used to initialize private member variables number, price and meal,
// respectively.
//
// Public member function print of class Order displays a message such as
//
//      order number: 207, meal: fries, drink, price: $1.45
//
// if the order number was 207, the meal was "fries, drink" and the price
// was $1.45.
//
// The private member variables, constructor and member functions should
// all have ther declaration, prototype and implementation (code) placed
// in header file Order.h.
//
// After class Order has been written, function main in main.cpp will
// use it to put objects of type Order onto a queue as follows.  Create
// an array named meal of Order objects in main.cpp as follows.
//
//    Order meal[] = {
//        Order(312,4.95,"burger, fries, drink"),
//        Order(245,4.15,"burger, drink"),
//        Order(207,1.45,"fries, drink"),
//        Order(156,0.65,"fries"),
//        Order(198,4.70,"combo")
//    };
//
// Then create a queue of Order objects of size 3.  Then put the 5 elements
// of array meal on the queue.  Note that the messages
//
//  The queue was full.
//  Reallocated 6 queue elements and copied queue to reallocated space.
//
// will be displayed when the Order objects are placed onto the queue.  Why
// are these messages displayed and why were 6 queue elements reallocated in
// this case?  After the Order objects are on the queue, empty the queue.  As
// the queue is emptied, call the print member function of class Order to
// display each order that is dequeued on a separate line.  In this case the
// output will look as follows.
//
//  order number: 312, meal: burger, fries, drink, price: $4.95
//  order number: 245, meal: burger, drink, price: $4.15
//  order number: 207, meal: fries, drink, price: $1.45
//  order number: 156, meal: fries, price: $0.65
//  order number: 198, meal: combo, price: $4.7
//
// Use Queue member function isEmpty to determine when the queue becomes
// empty.  Do not assume 5 elements are in the queue.
//
// When you complete assignment 5, compress your Netbeans project and
// submit your compressed file to Blackboard on or before the due date.
// The due date will be posted on Blackboard and announced in class. 
//
// If you DO NOT use Netbeans put files Order.h, Queue.h, Queue.cpp
// and main.cpp in a directory named Assignment5.  Then compress
// Assignment5 and submit the compressed file to Blackboard.  Submit
// your compressed file to Blackboard on or before the due date.
// The due date will be posted on Blackboard and announced in class.
