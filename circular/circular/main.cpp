//
//  main.cpp
//  circular
//
//  Created by Martin Dupras on 02/04/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

void initDelay(float DL[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        DL[i] = 0;
    }
}

// WRITE ME
void pushIntoDelay(float delayLine[], int SIZE, float inputValue, int *curIndex){
    // first put value into array at curIndex
    if((*curIndex)>SIZE) {
        (*curIndex) = fmod((*curIndex), SIZE);
    }
    delayLine[*curIndex] = inputValue;
    (*curIndex)++;
    // then increment
}

// void readIntoDelay(float delayLine[], int SIZE, int DELAY, int *curIndex);



int main() {
    int MAXDEL = 44100;
    float delayLine [MAXDEL]; // a delay line
    initDelay(delayLine, MAXDEL);
    int SAMPLEDELAY = 5;
    int currentIndex = 0;
    
    float runningValue = 0;
    float delayedValue = -999.9;
    
    // increment 123 times:
    for (int i = 0; i < 123; i ++) {
        runningValue+= 0.23;
        pushIntoDelay(delayLine, MAXDEL, runningValue, &currentIndex);

    }
    
    
    cout <<endl << "The current value is " << runningValue << endl;
    
    delayedValue = delayLine[currentIndex-SAMPLEDELAY-1];
    
    cout <<endl << "The delayed by 10 value is " << delayedValue << endl;

    
    
    return 0;
}
