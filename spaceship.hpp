#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "flying_object.hpp"

class Spaceship : public Flying_Object //child class of flying object 
{
private:
    SDL_Rect mover, src;
public:
    bool exploded = false; //end and exploded both will be false in the start
    bool end = false;
    void fly(); //fly function from the flying object which has to be present in every child class
    Spaceship();
    void setMov(int x,int y);
};
