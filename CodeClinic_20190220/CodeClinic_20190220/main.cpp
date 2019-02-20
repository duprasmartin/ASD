//  main.cpp
//  CodeClinic_20190220
//  Created by Martin Dupras on 20/02/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.

#include <iostream>

//add
void add(int *thevalue, int adder) {
    int temp = *thevalue+adder;
    *thevalue = temp;
}
//subtract
void subtract(int *thevalue, int subtracter) {
    int temp = *thevalue-subtracter;
    *thevalue = temp;
}
//divide
void divide(int *thevalue, int diviser) {
    int temp = *thevalue/diviser;
    *thevalue = temp;
}

//squarevalue
void squarevalue(int * thevalue){
    int temp = *thevalue * *thevalue;
    *thevalue = temp;
}
//multiply
void multiply(int *thevalue, int multiplier) {
    int temp = *thevalue*multiplier;
    *thevalue = temp;
}

void printvalue(int * thevalue) {
    std::cout << "thevalue has value " << *thevalue << std::endl;
}
void inputvalue(int * thevalue, int thenumber) {
    *thevalue = thenumber;
}


void explorefunctions() {
    
    int thevalue = 0;
    printvalue(&thevalue);
    inputvalue(&thevalue,200);
    printvalue(&thevalue);
    multiply(&thevalue, 7);
    printvalue(&thevalue);
    squarevalue(&thevalue);
    printvalue(&thevalue);
    divide(&thevalue, 2);
    printvalue(&thevalue);
    subtract(&thevalue, 111);
    printvalue(&thevalue);
    add(&thevalue, 3);
    printvalue(&thevalue);
        
}






float doublevalue(float thenumber) {
    return thenumber*2;
}

void checkerboardrice() {
    // display a grid of 8 x 8
    // and starting at the top left, put 1 grain, 2 grains, 4 and so forth
    // just like the tale
    float thevalue = 1;
    
    for (int j = 0; j < 8; j++) {
    // display one row
        for (int i = 0; i < 8 ; i++) {
            std::cout << thevalue << " ";
            thevalue = doublevalue(thevalue);
        }
    std::cout << std::endl;
    //
    }
}


void arraysbypointers() {
    int phonenumber[11] = { 3, 7, 7, 7 ,5, 1, 2,3,4,5,6};
    for (int i = 0; i < 11; i ++) {
        std::cout << phonenumber[i];
    }
    std::  cout << std::endl;
    
    // do the same thing with pointers:
    for (int i = 0; i < 11; i ++) {
        std::cout << *(phonenumber+i);
    }
    std::  cout << std::endl;
    //std::cout << "The value at the index 0 of phonenumber is ";
    //std::cout << phonenumber[0] << std::endl;
    
    //std::cout << "The value at the address pointed by phonenumber is ";
    //std::cout << *phonenumber << std::endl;
    
    std::cout << "Gimme the last value of the array: " << *(phonenumber+4) <<std::endl;
}


void showaddresses() {
    // this creates a memory space of size int, which has three things:
    // a name (by which we can refer to that memory
    // some content, which right now is 7
    // it has a memory address, which we don't know, but the computer does
    // in other words "avalue" is the name we said we wanted to use to know what is there.
    // Martin might might be at realworld coordinates 0.234, 0.123, but you might say "let's go to Martin's place"
    
    int myvalue = 9;
    int yourvalue = 3;
    std::cout << "The value of myvalue is : " << myvalue << std::endl;
    std::cout << "The value of yourvalue is : " << yourvalue << std::endl;
    
    std::cout << "The address of myvalue is : " << &myvalue << std::endl;
    std::cout << "The address of yourvalue is : " << &yourvalue << std::endl;
    
    int * mypointer;
    mypointer = &yourvalue;
    
    std::cout << "The content at the address pointed to by mypointer is : " << *mypointer << std::endl;
    
    std::cout << "The address pointed to by mypointer is : " << mypointer << std::endl;
}


int main() {
    //showaddresses();
    //arraysbypointers();
    //checkerboardrice();
    
    explorefunctions();
    return 0;
}
