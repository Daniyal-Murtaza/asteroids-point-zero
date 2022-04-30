#pragma once
#include <iostream>
#include <SDL.h>
#include "drawing.hpp"
using namespace std;

class Lives
{
protected:
    SDL_Rect srcRect; //srcRect and moverRect 
    SDL_Rect moverRect;

public:
    int n = 3; //we have a total of 3 lifes
    Lives();
    void draw(); //draw function
    void operator--(); //operator overloading
};