#include "box.h"

void Box::set(float x, float y, float z, float r)
{
    pos.set(x, y, z);
    radius = r;
}

vector<Box> Box::generate()

    vector<Box> boxes;
    for (int x = -1; x < 2; x++)
    {
        for (int y = -1; y < 2; y++)
        {
            for (int z = -1; z < 2; z++)
            {
                int sum = abs(x) + abs(y) + abs(z);
                float r = radius / 3;
                if (sum > 1)
                {
                    Box b;
                    b.set(pos.x + x * r, pos.y + y * r, pos.z + z * r, r);
                    boxes.push_back(b);
                }
            }
        }
    }
    return boxes;
}

void Box::draw()
{
    ofBoxPrimitive box;
    box.setPosition(pos);
    box.set(radius);
    box.draw();
}
