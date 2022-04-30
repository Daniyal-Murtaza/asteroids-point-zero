#include "lives.hpp"

Lives::Lives() //co-ordinates of the lifes
{
    srcRect = {59, 196, 228, 59};
    moverRect = {15, 15, 90, 30};
}

void Lives::draw() //draw function of life
{
    if (n == 3) //we have 3 lifes 
    {
        srcRect = {59, 196, 228, 59}; //if we have 3 lifes what will be the coordinates
        moverRect.w = 90; //where will we draw it 
    }
    else if (n == 2) //we have 2 lifes
    {
        srcRect = {59, 196, 154, 59}; //if we have 2 lifes what will be the coordinates
        moverRect.w = 60; //where will we draw it
    }
    else if (n == 1) //we have 1 life
    {
        srcRect = {59, 196, 62, 59}; //if we have 1 life what will be the coordinates 
        moverRect.w = 30; //where we can draw it 
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
void Lives::operator--() //operator overloading 
{
    n--; //life is deducted when we collide with an object 
}