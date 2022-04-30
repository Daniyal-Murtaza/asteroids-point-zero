#include "hard.hpp"

Hard::Hard(int x) : Flying_Object({9, 321, 33, 61}, {x, 0, 40, 40}) {}

void Hard::fly()
{

    // Sprite will flap it wings
    if (!exploded)
    {
        switch (frame)
        {
        case 0:
            srcRect = {11, 422, 33, 61}; //coordinates with the respective frame 
            frame = 1;
            break;
        case 1:
            srcRect = {61, 423, 33, 61}; //coordinates with the respective frame 
            frame = 2;
            break;
        case 2:
            srcRect = {112, 427, 32, 56}; //coordinates with the respective frame 
            frame = 3;
            break;
        case 3:
            srcRect = {163, 428, 33, 51}; //coordinates with the respective frame 
            frame = 4;
            break;
        case 4:
            srcRect = {214, 429, 33, 48}; //coordinates with the respective frame 
            frame = 5;
            break;
        case 5:
            srcRect = {265, 429, 33, 48}; //coordinates with the respective frame 
            frame = 6;
            break;
        case 6:
            srcRect = {316, 429, 34, 48}; //coordinates with the respective frame 
            frame = 7;
            break;
        case 7:
            srcRect = {365, 428, 37, 49}; //coordinates with the respective frame 
            frame = 8;
            break;
        case 8:
            srcRect = {413, 427, 39, 51}; //coordinates with the respective frame 
            frame = 0; 
            break;
        }
        moverRect.y += 20;
    }
    else
    {
        switch (frame)
        {
        case 0:
            srcRect = {41, 880, 92, 95}; //coordinates with the respective frame 
            frame = 1;
            break;
        case 1:
            srcRect = {191, 859, 133, 141}; //coordinates with the respective frame 
            frame = 2;
            break;
        case 2:
            srcRect = {341, 848, 162, 165}; //coordinates with the respective frame 
            frame = 3;
            break;
        case 3:
            srcRect = {508, 848, 162, 165}; //coordinates with the respective frame 
            frame = 4;
            break;
        case 4:
            srcRect = {683, 848, 154, 165}; //coordinates with the respective frame 
            frame = 5;
            break;
        case 5:
            srcRect = {849, 848, 154, 165}; //coordinates with the respective frame 
            frame = 6;
            break;
        case 6:
            srcRect = {1012, 848, 158, 165}; //coordinates with the respective frame 
            // frame = 7;
            end = true;
            break;
        }
    }
}

void Hard::removeHard() //removing bullets
{
    moverRect = {0, 0, 0, 0};
}
