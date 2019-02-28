#include "ofApp.h"
//#include "ball.h"

//--------------------------------------------------------------
void ofApp::setup(){
// set position and speed of p1_paddle
    // set position and speed of p2_paddle;
    // set position and speed of ball
    myBall.setSize(12);
    myBall.setPosition(ofGetWidth()-50, ofGetHeight()-30);
    // set scores to 0
}

//--------------------------------------------------------------
void ofApp::update(){
    // update paddle1 position
    // update paddle2 position
    // update ball position
    
    //test for collisions:
        // test ball against upper and lower walls
                // if hit, switch vertical speed
    
        // test ball against paddles
                // if hit, switch horizontal speed
    
    // else:
                // give point to other paddle
                // update score
                // test if game won
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    // draw myball
    ofSetColor(255,255,255);
    ofDrawCircle(myBall.getPositionx(),myBall.getPositiony(), myBall.getSize());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


/////
void Ball::setPosition(int x, int y){
    m_positionx = x;
    m_positiony = y;
}

int Ball::getPositionx(){
    return m_positionx;
}

int Ball::getPositiony(){
    return m_positiony;
}

void Ball::setSize(float s){
    m_ballsize = s;
}

int Ball::getSize(){
    return m_ballsize;
}

