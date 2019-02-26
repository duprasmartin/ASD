//
//  main.cpp
//  circle
//
//  Created by Martin Dupras on 26/02/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.
//

#include <iostream>
#include "circle.h"

#define PI 3.14159

using namespace std;

void Circle::setRadius(float radius) {
    m_radius = radius;
}

float Circle::getRadius() {
    return m_radius;
}

float Circle::getArea() {
    float area;
    area = PI * m_radius * m_radius;
    return area;
}

void Circle::setCoordinates(float x, float y){
    m_coordx = x;
    m_coordy = y;
}

int main(int argc, const char * argv[]) {

    
    // instantiate a variable called myClock of type Circle
    Circle myCircle;
    
    // set the radius of myClock to 2.2
    myCircle.setRadius(2.2);
    
    // print "The radius of myClock is " with the value
    cout << "The radius of myCircle is " << myCircle.getRadius() << endl;
    
    // print "The area of myCircle is " with the value
    cout << "The area of myCircle is " << myCircle.getArea() << endl;

    return 0;
}
