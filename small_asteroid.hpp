#include "flying_object.hpp"
#pragma once

class Small_Asteroid : public Flying_Object
{
private:
    SDL_Rect mover, src;
    int frame = 0;

public:
    void fly();
    Small_Asteroid(int);
};