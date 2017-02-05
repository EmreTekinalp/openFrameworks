#include "umbrella.h"

Umbrella::Umbrella()
{
    radius = 100;
    umbrellaHandle = 80;
}

Umbrella::~Umbrella()
{
}

void Umbrella::checkCollision(Drop &drop)
{
    // check if drop is inside the umbrella shape
    if (ofDist(drop.position.x, drop.position.y, position.x, position.y) <= radius)
    {
        if (drop.position.y - position.y < 0)
        {
            // we want to see quick collision feedback
            ofEllipse(drop.position, 10, 10);
            drop.reset();
        }
    }
}


void Umbrella::update()
{
    path.clear();
    position.set(ofGetMouseX(), ofGetMouseY() - umbrellaHandle);
}

void Umbrella::render()
{
    path.arc(position, radius, radius, 180, 0);
    path.setArcResolution(40);
    path.setColor(ofColor(255, 255, 255, 40));
    ofEnableAlphaBlending();
    ofMesh mesh = path.getTessellation();
    for (ofPoint vtx : mesh.getVertices())
    {
        ofSetColor(100, 100, 200);
        ofEllipse(vtx, 3, 3);
    }
    path.close();
    path.draw();
    // we need the umbrella handle as well
    ofSetLineWidth(20);
    ofLine(position, ofPoint(position.x, position.y + umbrellaHandle));
}
