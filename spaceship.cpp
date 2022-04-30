#pragma once
#include "spaceship.hpp"

// inheriting from flying object
Spaceship::Spaceship() : Flying_Object({133, 196, 80, 59}, {280, 530, 70, 70}) {}


void Spaceship::fly() {}

// move the spaceship freely all over the screen
void Spaceship::setMov(int x, int y)
{
    moverRect.x = x; //moving the spaceship on x coordinates
    moverRect.y = y; //moving the spaceship of y coordinates
}
