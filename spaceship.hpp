#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include "flying_object.hpp"

class Spaceship : public Flying_Object
{

public:
    void fly();
    Spaceship();
};
