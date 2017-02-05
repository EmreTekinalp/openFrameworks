#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f gravity;
    gravity.set(0, 0.4, 0);
    for (unsigned int i=0; i<sizeof(movers) / sizeof(Mover); i++)
    {
        movers[i].applyForce(gravity);
        movers[i].bounceOnEdge();
        movers[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (unsigned int i = 0; i<sizeof(movers) / sizeof(Mover); i++)
    {
        movers[i].draw();
    }
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
    if (button == 0)
    {
        ofVec3f wind;
        wind.set(ofGetMouseX() * 0.01, 0.0, 0);
        //ofVec3f depth;
        //depth.set(0.0, 0.0, -2);

        for (unsigned int i = 0; i<sizeof(movers) / sizeof(Mover); i++)
        {
            movers[i].applyForce(wind);
            // movers[i].applyForce(depth);
        }
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
