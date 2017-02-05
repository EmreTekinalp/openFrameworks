#pragma once

#include "ofMain.h"
#include "ofMath.h"
#include "drop.h"


class Umbrella
{
    ofPoint position;
    ofPath path;
    float umbrellaHandle;
public:
    Umbrella();
    ~Umbrella();
    void update();
    void render();
    void checkCollision(Drop &drop);

    float radius;
};
