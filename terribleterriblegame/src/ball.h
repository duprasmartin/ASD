//
//  ball.h
//  terribleterriblegame
//
//  Created by Martin Dupras on 28/02/2019.
//

#ifndef ball_h
#define ball_h


#endif /* ball_h */

class Ball {
public:
    void setSize(float s);
    int getSize();
    void setPosition(int x, int y);
    int getPositionx();
    int getPositiony();
    //ofPoint getPosition();
    
    void setSpeed(float s);
    float getSpeed();
    
private:
    int m_positionx;
    int m_positiony;
    int m_ballsize;
    float m_speedx;
    float m_speedy;
    
};
