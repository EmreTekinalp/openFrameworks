#include "drop.h"


Drop::Drop()
{
    // initialize position
    position.set(ofRandom(0, ofGetWidth()), -ofGetHeight(), ofRandom(0, ofGetHeight() * 0.1));
    color.set(ofMap(position.z, 0, ofGetHeight() * 0.1, 0, 255));
    ySpeed = ofMap(position.z, 0, ofGetHeight() * 0.1, 1, 20);
    dropLength = ofMap(position.z, 0, ofGetHeight() * 0.1, ofRandom(5, 20), ofRandom(20, 50));
    dropThickness = ofMap(position.z, 0, ofGetHeight() * 0.1, 0.5, 2);
}

Drop::~Drop()
{
}

void Drop::setSpeed(float speed)
{
    ySpeed = ofMap(position.z, 0, ofGetHeight() * 0.1, speed * 0.1, speed);
}

void Drop::reset()
{
    position.set(ofRandom(0, ofGetWidth()), -ofGetHeight(), ofRandom(0, 50));
}

void Drop::update()
{
    position.y += ySpeed;
    if(dragPosition.y > ofGetHeight())
    {
        position.set(ofRandom(0, ofGetWidth()), -ofGetHeight(), ofRandom(0, 50));
    }
}

void Drop::render()
{
    dragPosition.set(position.x, position.y - dropLength, position.z);
    ofSetColor(color);
    ofSetLineWidth(dropThickness);
    ofLine(dragPosition, position);
}