#include "Bonus.hpp"

Bonus::Bonus(int x) : Flying_Object({249, 493, 162, 113}, {x, 0, 30, 30}) {} //child class of flying object

void Bonus::fly()
{
    if (!exploded)
    {
        //the sprite will flap its wings here 
        switch (frame)
        {
        case 0:
            srcRect = {249, 493, 162, 113}; //coordinates with the respective frame 
            frame = 1;
            break;
        case 1:
            srcRect = {430, 494, 142, 112}; //coordinates with the respective frame 
            frame = 2;
            break;
        case 2:
            srcRect = {603, 496, 77, 112}; //coordinates with the respective frame 
            frame = 3;
            break;
        case 3:
            srcRect = {326, 628, 25, 113}; //coordinates with the respective frame 
            frame = 4;
            break;
        case 4:
            srcRect = {430, 629, 77, 113}; //coordinates with the respective frame 
            frame = 5;
            break;
        case 5:
            srcRect = {546, 628, 142, 112}; //coordinates with the respective frame 
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

void Bonus::remove_Bonus() //removing bullets
{
    moverRect = {0, 0, 0, 0};
}