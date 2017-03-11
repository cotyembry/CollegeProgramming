// Created on Tue Jun 14 2016

#include <stdio.h>

int main(){
motor(0,1000);//turn on motor in port 0 forward
motor(3,1000);//turn on motor in port 3 forward
sleep(3.0); //wait for 3 seconds
ao(); //turn off both motors
mav(0,1000); //turn on motor in port 0 forward
mav(3,-1000); //turn on motor in port 3 backward
sleep(6.0); //wait for 6.0 seconds
ao(); //turn off both motors
motor(0,1000); // turn on motor in port 0 forward
motor(3,1000); // turn on motor in port 3 forward
sleep(3.0); // wait for 3 seconds
ao(); //turn off both motors
}
