#include "lives.hpp"

Lives::Lives()
{
    srcRect = {133, 196, 80, 59};
    moverRect = {100, 15, 30, 30};
}

void Lives::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}