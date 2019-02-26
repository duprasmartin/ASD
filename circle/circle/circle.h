//
//  circle.h
//  circle
//
//  Created by Martin Dupras on 26/02/2019.
//  Copyright © 2019 Martin Dupras. All rights reserved.
//

#ifndef circle_h
#define circle_h


#endif /* circle_h */

class Circle {
public:
    float getRadius();
    void setRadius(float radius);
    
    void setCoordinates(float x, float y);
    
    float getDiameter();
    float getCircumference();
    float getArea();
    
    
private:
    float m_radius;
    float m_coordx;
    float m_coordy;
    
};



