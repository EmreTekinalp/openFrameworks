#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setForceAspectRatio(true);
    cam.setupPerspective(true);
    cam.setPosition(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 0.0);
    origin.set(0, 0, 0);
    box.set(0, 0, 0, 200);
    sponge.push_back(box);
    light.enable();
    ofEnableDepthTest();
    ofBackgroundGradient(ofColor(255), ofColor(128));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    cam.begin();
    light.setPosition(cam.getPosition());
    for (Box b : sponge)
    {
        ofSetColor(200, 100, 0);
        b.draw();
    }
    cam.end();
    ofPopMatrix();
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
    if (button == 1)
    {
        vector<Box> next;
        for (Box b : sponge)
        {
            vector<Box> newBoxes = b.generate();
            for (Box nb : newBoxes)
            {
                next.push_back(nb);
            }
        }
        sponge = next;
    }
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
