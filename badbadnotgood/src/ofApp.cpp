#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    mygrey = 0;
    myball.x = ofGetWidth()/2;
    myball.y = ofGetHeight()/2;
    myball.vx = 4;
    myball.vy = 3;
    myball.size = 17;
    
    otherball.x = ofGetWidth()/4;
    otherball.y = ofGetHeight()/4;
    otherball.vx = 7;
    otherball.vy = 9;
    otherball.size = 29;
}

//--------------------------------------------------------------
void ofApp::update(){
    mygrey = mygrey + 1;
    if (mygrey > 255) {
        mygrey = 0;
    }
    
    // move ball someplace buddy
    myball.x = myball.x + myball.vx;
    if (myball.x < (0+myball.size) || myball.x > (ofGetWidth()-myball.size)) {
        myball.vx = -myball.vx;
    }
    myball.y = myball.y + myball.vy;
    if (myball.y < (0+myball.size) || myball.y > (ofGetHeight()-myball.size)) {
        myball.vy = -myball.vy;
    }
    
    // move otherball someplace buddy
    otherball.x = otherball.x + otherball.vx;
    if (otherball.x < (0+otherball.size) || otherball.x > (ofGetWidth()-otherball.size)) {
        otherball.vx = -otherball.vx;
    }
    otherball.y = otherball.y + otherball.vy;
    if (otherball.y < (0+otherball.size) || otherball.y > (ofGetHeight()-otherball.size)) {
        otherball.vy = -otherball.vy;
    }

    // test for collision between balls
    if (ofDist(myball.x,myball.y,otherball.x,otherball.y) < (myball.size+otherball.size)) {
        myball.vx = -myball.vx;
        myball.vy = -myball.vy;
        otherball.vx = -otherball.vx;
        otherball.vy = -otherball.vy;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(mygrey,mygrey,mygrey);
    // draw myball
    ofSetColor(255,192,203);
    ofDrawCircle(myball.x,myball.y, myball.size);

    //draw otherball
    ofSetColor(255,0,0);
    ofDrawCircle(otherball.x,otherball.y, otherball.size);

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
