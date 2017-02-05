#include "mover.h"

Mover::Mover()
{
    position.set(ofRandom(0, ofGetWidth() * 0.5), ofGetHeight() * 0.5, 0);
    velocity.set(0, 0, 0);
    acceleration.set(0, 0, 0);
    color.set(255);
    mass = ofRandom(1, 5);
    radius = mass * 20;
}

Mover::~Mover()
{
}

void Mover::applyForce(ofVec3f force)
{
    ofVec3f f(force / mass);
    acceleration += f;
}

void Mover::bounceOnEdge()
{
    if (position.x + (radius * 0.5) > ofGetWidth())
    {
        position.x = ofGetWidth() - (radius * 0.5);
        velocity.x *= -1;
    }
    if (position.x - (radius * 0.5) < 0)
    {
        position.x = (radius * 0.5);
        velocity.x *= -1;
    }
    if (position.y + (radius * 0.5) > ofGetHeight())
    {
        position.y = ofGetHeight() - (radius * 0.5);
        velocity.y *= -1;
    }
    if (position.y - (radius * 0.5) < 0)
    {
        position.y = (radius * 0.5);
        velocity.y *= -1;
    }
    if (position.z > ofGetWidth() * 0.5)
    {
        position.z = ofGetWidth() * 0.5;
        velocity.z *= -1;
    }
    if (position.z < -ofGetWidth() * 0.5)
    {
        position.z = -ofGetWidth() * 0.5;
        velocity.z *= -1;
    }
}

void Mover::update()
{
    velocity += acceleration;
    position += velocity;
    acceleration *= 0;
    color.set(ofMap(position.z, -ofGetWidth() * 0.5, ofGetWidth() * 0.5, 0, 255));
}

void Mover::draw()
{
    ofSetColor(color);
    ofEllipse(position, mass*20, mass * 20);
}
