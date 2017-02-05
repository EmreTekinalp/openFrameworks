#pragma once

#include "ofMain.h"

class Box
{
    ofVec3f pos;
    float radius;
public:
    void set(float x, float y, float z, float r);
    vector<Box> generate();
    void draw();
};