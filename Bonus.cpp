#include "Bonus.hpp"

Bonus::Bonus(int x) : Flying_Object({249, 493, 162, 113}, {x, 0, 30, 30}) {}

void Bonus::fly()
{
    if (!exploded)
    {
        switch (frame)
        {
        case 0:
            srcRect = {249, 493, 162, 113};
            frame = 1;
            break;
        case 1:
            srcRect = {430, 494, 142, 112};
            frame = 2;
            break;
        case 2:
            srcRect = {603, 496, 77, 112};
            frame = 3;
            break;
        case 3:
            srcRect = {326, 628, 25, 113};
            frame = 4;
            break;
        case 4:
            srcRect = {430, 629, 77, 113};
            frame = 5;
            break;
        case 5:
            srcRect = {546, 628, 142, 112};
            frame = 0;
            break;
        }
        moverRect.y += 15;
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

void Bonus::remove_Bonus()
{
    moverRect = {0, 0, 0, 0};
}