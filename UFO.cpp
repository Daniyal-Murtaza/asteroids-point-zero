#include "UFO.hpp"

UFO::UFO(int x) : Flying_Object({13, 10, 72, 72}, {0, x, 30, 30}) {}

void UFO::fly()
{
    if (!exploded)
    {
        switch (frame)
        {
        case 0:
            srcRect = {9, 321, 33, 61};
            frame = 1;
            break;
        case 1:
            srcRect = {105, 9, 80, 77};
            frame = 2;
            break;
        case 2:
            srcRect = {198, 6, 86, 84};
            frame = 3;
            break;
        case 3:
            srcRect = {386, 4, 94, 90};
            frame = 4;
            break;
        case 4:
            srcRect = {482, 4, 94, 90};
            frame = 5;
            break;
        case 5:
            srcRect = {578, 4, 94, 90};
            frame = 6;
            break;
        }
        moverRect.y += 1;
        moverRect.x += 5;
        
    }
    else
    {
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

void UFO::remove_UFO()
{
    moverRect = {0, 0, 0, 0};
}