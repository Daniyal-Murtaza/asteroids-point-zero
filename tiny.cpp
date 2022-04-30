#include "tiny.hpp"

//  Inheriting from flying_object class
Tiny::Tiny(int x) : Flying_Object({165, 360, 26, 23}, {x, 0, 70, 70}) {}

// Polymorphism from flying_object class
void Tiny::fly()
{
    // flying animation
    if (!exploded)
    {
        switch (frame)
        {
        case 0:
            srcRect = {165, 360, 26, 23};
            frame = 1;
            break;
        case 1:
            srcRect = {215, 358, 22, 28};
            frame = 2;
            break;
        case 2:
            srcRect = {264, 354, 19, 35};
            frame = 3;
            break;
        case 3:
            srcRect = {313, 352, 16, 39};
            frame = 4;
            break;
        case 4:
            srcRect = {361, 353, 16, 38};
            frame = 5;
            break;
        case 5:
            srcRect = {407, 356, 20, 31};
            frame = 6;
            break;
        case 6:
            srcRect = {452, 358, 24, 26};
            frame = 7;
            break;
        case 7:
            srcRect = {498, 360, 27, 23};
            frame = 8;
            break;
        case 8:
            srcRect = {546, 359, 26, 23};
            frame = 0;
            break;
        }
        // controlling speed
        moverRect.y += 7;
        moverRect.x += -1;
    }
    else
    {
        // explosion animation
        switch (frame)
        {
        case 0:
            srcRect = {41, 880, 92, 95};
            frame = 1;
            break;
        case 1:
            srcRect = {191, 859, 133, 141};
            frame = 2;
            break;
        case 2:
            srcRect = {341, 848, 162, 165};
            frame = 3;
            break;
        case 3:
            srcRect = {508, 848, 162, 165};
            frame = 4;
            break;
        case 4:
            srcRect = {683, 848, 154, 165};
            frame = 5;
            break;
        case 5:
            srcRect = {849, 848, 154, 165};
            frame = 6;
            break;
        case 6:
            srcRect = {1012, 848, 158, 165};
            // frame = 7;
            end = true;
            break;
        }
    }
}

void Tiny::removeTiny() // removing bullets
{
    moverRect = {0, 0, 0, 0};
}
