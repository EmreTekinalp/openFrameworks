#include "Star.h"

Star::Star()
{
    position.x = ofRandom(0, ofGetWidth());
    position.y = ofRandom(0, ofGetHeight());
    position.z = ofRandom(0, ofGetWidth());
    trailPosition = position;
    radius = ofRandom(0, 10);
    velocity.set(ofGetMouseX(), ofGetMouseY(), position.z);
}

Star::~Star()
{
}

void Star::update()
{
    position.z += speed;
    velocity.set(ofGetMouseX(), ofGetMouseY(), 0);
    ofVec3f direction;
    direction = velocity - position;
    direction.normalize();
    direction *= 2;
    position += direction;

    if (position.z > ofGetWidth())
    {
        position.set(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()), ofRandom(0, ofGetWidth()));
        trailPosition = position;
        ofSetLineWidth(0);
    }
}

void Star::draw()
{
    // draw the star itself
    ofSetColor(255);
    radius = ofMap(position.z, 0, ofGetWidth(), 0, 10);
    ofEllipse(position, radius, radius);

    trailPosition = position;
    trailPosition.z *= 0.8;
    // cout << position << "    " << trailPosition << endl;
    // draw the star trail
    ofSetLineWidth(1);
    ofLine(position, trailPosition);
}