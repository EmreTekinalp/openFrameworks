#pragma once

#include "ofMain.h"


class Mover
{
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    ofColor color;
    float mass;
    float radius;
public:
    Mover();
    ~Mover();
    void applyForce(ofVec3f force);
    void bounceOnEdge();
    void update();
    void draw();
};