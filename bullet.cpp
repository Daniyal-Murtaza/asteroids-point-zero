#include "bullet.hpp"

Bullet::Bullet(int x, int y) : Flying_Object({1059, 313, 25, 14}, {x, y, 15, 35}) {}

void Bullet::fly()
{

    // Sprite will flap it wings
    if (exploded) //frames 
    {
        switch (frame)
        {
        case 0:
            srcRect = {9, 321, 33, 61}; //coordinates with the respective frame 
            frame = 1;
            break;
        case 1:
            srcRect = {40, 780, 92, 95}; //coordinates with the respective frame 
            frame = 2;
            break;
        case 2:
            srcRect = {190, 759, 133, 141}; //coordinates with the respective frame 
            frame = 3;
            break;
        case 3:
            srcRect = {340, 748, 162, 165}; //coordinates with the respective frame 
            frame = 4;
            break;
        case 4:
            srcRect = {507, 748, 162, 165}; //coordinates with the respective frame 
            frame = 5;
            break;
        case 5:
            srcRect = {682, 748, 154, 165}; //coordinates with the respective frame 
            frame = 6;
            break;
        case 6:
            srcRect = {848, 748, 154, 165}; //coordinates with the respective frame 
            // frame = 7;
            end = true;
            break;
        }
    }
    else
    {
        moverRect.y -= 2;
    }
}

void Bullet::removeBullet() //removing bullets
{
    moverRect = {0, 0, 0, 0};
}

// SDL_Rect* Bullet::getMov(){
//     return getMov();
// }