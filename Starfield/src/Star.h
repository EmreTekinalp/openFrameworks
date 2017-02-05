#pragma once

#include "ofMain.h"
#include "ofMath.h"

class Star
{
    ofVec3f position;
    ofVec3f trailPosition;
    float radius;
public:
    Star();
    ~Star();

    void update();
    void draw();

    ofVec3f velocity;
    float speed;
};