#include "lives.hpp"

Lives::Lives()
{
    srcRect = {59, 196, 228, 59};
    moverRect = {15, 15, 90, 30};
}

void Lives::draw()
{
    if (n == 3)
    {
        srcRect = {59, 196, 228, 59};
        moverRect.w = 90;
    }
    else if (n == 2)
    {
        srcRect = {59, 196, 154, 59};
        moverRect.w = 60;
    }
    else if (n == 1)
    {
        srcRect = {59, 196, 62, 59};
        moverRect.w = 30;
    }
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
void Lives::operator--()
{
    n--;
}