#include "flying_object.hpp"
#pragma once

class Fire : public Flying_Object
{
private:
    SDL_Rect mover, src;
    int frame = 0;

public:
    bool end = false;
    bool exploded = false;
    void fly();
    Fire(int);
    void removeFire();
};