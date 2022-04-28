#pragma once
#include <iostream>
#include <SDL.h>
#include "drawing.hpp"
using namespace std;

class Lives
{
protected:
    SDL_Rect srcRect;
    SDL_Rect moverRect;

public:
    Lives();
    void draw();
};