#include "flying_object.hpp"
#pragma once

class Small_Asteroid : public Flying_Object
{
private:
    SDL_Rect mover, src;

public:
    void fly();
    Small_Asteroid();
};