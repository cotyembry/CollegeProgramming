/* 
 * File:   Queue.h
 * Author: cotyembry
 *
 * Created on April 13, 2015, 9:19 AM
 */

#ifndef QUEUE_H
#define	QUEUE_H

template <class TYPE>
    class Queue {
    private:
        int max_len;
        int number;
        int head;
        int tail;
        TYPE* s;  
    public:
        Queue(const int size = 10); //this is the default value if no parameter is passed
        
        ~Queue();

        void enqueue(const TYPE x);

        TYPE dequeue(void);
        
        bool isFull() const;

        bool isEmpty() const;

        TYPE getHead() const;

        TYPE getTail() const;
        
        TYPE print() const;
        
        TYPE mydelete(void);
    };




#endif	/* QUEUE_H */

