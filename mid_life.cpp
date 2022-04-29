#include "mid_life.hpp"

Mid_Life::Mid_Life()
{
    srcRect = {133, 258, 80, 55};
    moverRect = {60, 15, 30, 30};
}

void Mid_Life::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}