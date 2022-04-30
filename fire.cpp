#include "fire.hpp"

Fire::Fire(int x) : Flying_Object({41, 880, 92, 95}, {0, x, 60, 60}) {}

void Fire::fly()
{

    // Sprite will flap it wings
    if (!exploded)
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
            frame = 0;
            break;
            moverRect.x += 4;
        }
        // else
        // {
        //     switch (frame)
        //     {
        //     case 0:
        //         srcRect = {41, 880, 92, 95};
        //         frame = 1;
        //         break;
        //     case 1:
        //         srcRect = {191, 859, 133, 141};
        //         frame = 2;
        //         break;
        //     case 2:
        //         srcRect = {341, 848, 162, 165};
        //         frame = 3;
        //         break;
        //     case 3:
        //         srcRect = {508, 848, 162, 165};
        //         frame = 4;
        //         break;
        //     case 4:
        //         srcRect = {683, 848, 154, 165};
        //         frame = 5;
        //         break;
        //     case 5:
        //         srcRect = {849, 848, 154, 165};
        //         frame = 6;
        //         break;
        //     case 6:
        //         srcRect = {1012, 848, 158, 165};
        //         // frame = 7;
        //         end = true;
        //         break;
        //     }
    }
}

void Fire::removeFire()
{
    moverRect = {0, 0, 0, 0};
}
