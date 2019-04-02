//
//  main.cpp
//  dumbdumbdelay
//
//  Created by Martin Dupras on 02/04/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.
//


#include <iostream>
#include <math.h>

using namespace std;

// for testing:
void printSignal(float sigbuf[], int SIZE)
{
    for (int i = 0; i < SIZE; i++){
        cout << sigbuf[i] << endl;
    }
}

void fillSignal(float sigbuf[], int SIZE)
{
    for (int i = 0; i < SIZE; i++){
        sigbuf[i] = i;
    }
}


int main() {
    // this is the full signal
    float signal[44100]; // an empty delay lines
    
    // this just the current 64 values read
    float temp[64];
    
    int whereAmIglobal = 0;
    int whereAmIlocal = 0;
    
    int valuestoprocess = 44100;
    
    // fill the signal with values
    fillSignal(signal, 44100);
    
    //printSignal(signal, 44100);
    
    while( valuestoprocess > 64) {
    // copy the first 64 values of signal into temp
    for (int i = whereAmIglobal; i < whereAmIglobal+64; i++){
        temp[whereAmIlocal] = signal[i];
        whereAmIlocal++;
    }
  
    printSignal(temp, 64);
    
    whereAmIglobal += 64; // move up one buffer
    whereAmIlocal = 0; // restart at the beginning
        valuestoprocess-= 64;
    
    }
    
    cout << "We now have " << valuestoprocess << "values to process";
    
    
    while( valuestoprocess > 0) {
        // copy the first 64 values of signal into temp
        for (int i = whereAmIglobal; i < whereAmIglobal+64; i++){
            temp[whereAmIlocal] = signal[i];
            whereAmIlocal++;
            valuestoprocess--;
        }
    }
    printSignal(temp, 4);

    return 0;
}
