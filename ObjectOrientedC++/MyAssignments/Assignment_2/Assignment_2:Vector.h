/* 
 * File:   Vector.h
 * Author: John Coty Embry
 *
 * Created on January 30, 2015, 12:26 PM
 */
#include <iostream>
#include <climits> //needed for INT_MAX. INT_MAX
                                //is the largest signed integer that
                                //can be stored in 32 bits
                                // INT_MAX = 2^31-1 = 2147483647.
                                // The leftmost bit is a sign bit.

#ifndef VECTOR_H
#define	VECTOR_H

using namespace std;

const int max_len = 20;

class Vector {
        private:
            double v[max_len];
            int length;
            
        public:
            //This is the 1st constructor
            Vector () { //this will create an empty vector
                length = 0;
            }
            //This is the 2nd constructor
            //first parameter specifies size of the vector
            //second parameter is an array with size elements
            Vector(const int vector_length, const double size_elements[]) {                
                    //if parameter 1 size isn't between 0 and max_len inclusive
                    //use cerr to display errors             
                
                if ((vector_length >= 0) && (vector_length <= max_len)) {
                    length = vector_length;
                    
                }
                else if (vector_length >= max_len) {
                        length = max_len;
                        
                }
                else if (vector_length < 0) {
                        cerr << vector_length <<" is an invalid length. The length of the vector will be set to zero." << endl;
                        length = 0;
                        v[length] = 0;
                }  
                for(int i = 0; i < length; i++) {
                        v[i] = size_elements[i]; 

                }                
            }
            
            const double*  getVector () const { return v; }
            
            const int getLength () const { return length; }
            
           //done
           void print () const { //this will print elements v[0], v[1], and v[2], ..., v[length-1]

               for(int i=0; i < length; i++) {
                   cout << v[i] << " ";
               }
                cout << "" << endl;

           }
           //done
           void print (const int n) const { //this will print elements v[0], v[1], and v[2], ..., v[m-1]

               int m = min(n, length); //this calls method that returns which one is less
               for (int i = 0; i < m; i++) { 
                   cout << v[i] << " "; 
               }
               cout << "\n";
           }
                                
           
           // done
          void setVector (const int vector_length, const double size_elements[]) { //this will set
           //this should init the first size elements of v using the array passed as the second param and sets private member variable length to size    
               if (vector_length > max_len) { 
                   cerr << "The vector size " << vector_length << " is too large.\nOnly " << max_len <<" will be used." << endl;                
                   length = max_len;
               }
               else if (vector_length < 0 ) {
                   cout << "The vector size is too small.\n The vector will be set to the empty vector." << endl;
                   length = 0;
                   delete []v;
                   v[length]=0;
               }
               else {
                   length = vector_length;                   
               }
               for( int i = 0; i < length; i++) {
                   v[i] = size_elements[i];
               }
          }

 
         //done
         int min (const int vector_length, const int length) const{
             if (vector_length >= length) 
                return length;              
             
             else 
                 return vector_length;
         }
         int max (const int a, const int b) const{
             if (a >= b) 
                return a;
             else
                 return b;
         }

}; //this is the end of the Vector class     

        Vector operator+(const Vector a, const Vector b) { //this will add the elements of two vectors element wise (element by element).
            int i;
            double* pa = (double*)a.getVector(); //pa and pb are the vectors
            double* pb = (double*)b.getVector(); 
            int lengtha = a.getLength();
            int  lengthb = b.getLength();
            int biggest = max(lengtha, lengthb);
            int length = min(lengtha, lengthb); //length is the lesser of the lengths
            double c[length];
                                    
            for (i = 0; i < length; i++) {
                    c[i] = pa[i] + pb[i];
                
                 //I may need to revisit this to make "if one Vector conains more elements then the
                                             // other, the remaining elements are copied to the result." correct
             }

            if (lengtha > lengthb) {
                while (i < lengtha) {
                    c[i] = pa[i];
                    i++;              
                }
            }
            else if (lengthb > lengtha) {
                 while (i < lengthb) {
                   c[i] = pb[i];
                   i++;
                 }
            }             
            
            Vector temp;
            temp.setVector(biggest, c);
            return temp;
          }
          
        Vector operator-(const Vector a, const Vector b) { //this will add the elements of two vectors element wise (element by element).
            int i;
            double* pa = (double*)a.getVector(); //pa and pb are the vectors
            double* pb = (double*)b.getVector(); 
            int lengtha = a.getLength();
            int  lengthb = b.getLength();
            int biggest = max(lengtha, lengthb);
            int length = min(lengtha, lengthb); //length is the lesser of the lengths
            double c[length];
                                    
            for (i = 0; i < length; i++) {
                    c[i] = pa[i] - pb[i];                
                 //I may need to revisit this to make "if one Vector conains more elements then the
                                             // other, the remaining elements are copied to the result." correct
             }

            if (lengtha > lengthb) {
                while (i < lengtha) {
                    c[i] = pa[i];
                    i++;              
                }
            }
            else if (lengthb > lengtha) {
                 while (i < lengthb) {
                   c[i] = pb[i];
                   i++;
                 }
            }             
            
            Vector temp;
            temp.setVector(biggest, c);
            return temp;
          }

//do i need these things?
/*            r
#ifdef	__cplusplus
extern "C" {
#endifr

#ifdef	__cplusplus
}
#endif
*/
 
#endif	/* VECTOR_H */
