#include "end_life.hpp"

End_Life::End_Life()
{
    srcRect = {133, 143, 80, 49};
    moverRect = {20, 15, 30, 30};
}

void End_Life::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}