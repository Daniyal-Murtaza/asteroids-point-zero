#include "small_asteroid.hpp"

Small_Asteroid::Small_Asteroid(int x) : Flying_Object({11, 422, 33, 61}, {x, 0, 60, 60}) {}

void Small_Asteroid::fly()
{

    // Sprite will flap it wings
    if (!exploded)
    {
        switch (frame)
        {
        case 0:
            srcRect = {11, 422, 33, 61};
            frame = 1;
            break;
        case 1:
            srcRect = {61, 423, 33, 61};
            frame = 2;
            break;
        case 2:
            srcRect = {112, 427, 32, 56};
            frame = 3;
            break;
        case 3:
            srcRect = {163, 428, 33, 51};
            frame = 4;
            break;
        case 4:
            srcRect = {214, 429, 33, 48};
            frame = 5;
            break;
        case 5:
            srcRect = {265, 429, 33, 48};
            frame = 6;
            break;
        case 6:
            srcRect = {316, 429, 34, 48};
            frame = 7;
            break;
        case 7:
            srcRect = {365, 428, 37, 49};
            frame = 8;
            break;
        case 8:
            srcRect = {413, 427, 39, 51};
            frame = 0;
            break;
        }
        moverRect.y += 4;
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

void Small_Asteroid::removeSmall_Asteroid() //removing bullets
{
    moverRect = {0, 0, 0, 0};
}
