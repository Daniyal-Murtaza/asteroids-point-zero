#pragma once
#include <iostream>
#include <SDL.h>
#include "drawing.hpp"
using namespace std;

class End_Life
{
protected:
    SDL_Rect srcRect;
    SDL_Rect moverRect;

public:
    End_Life();
    void draw();
};