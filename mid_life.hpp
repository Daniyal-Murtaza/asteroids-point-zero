#pragma once
#include <iostream>
#include <SDL.h>
#include "drawing.hpp"
using namespace std;

class Mid_Life
{
protected:
    SDL_Rect srcRect;
    SDL_Rect moverRect;

public:
    Mid_Life();
    void draw();
};