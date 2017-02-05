#pragma once

#include "ofMain.h"

class Drop
{
    ofColor color;
    float dropThickness;
    float dropLength;
    float ySpeed;
public:
    Drop();
    ~Drop();
    void setSpeed(float speed);
    void reset();
    void update();
    void render();

    ofVec3f position;
    ofVec3f dragPosition;
};
