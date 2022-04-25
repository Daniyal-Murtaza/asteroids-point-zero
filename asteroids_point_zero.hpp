#include <SDL.h>
#include "spaceship.hpp"
#include "small_asteroid.hpp"
using namespace std;
#pragma once

class asteroids_point_zero
{
private:
    Spaceship *spaceship;
    Small_Asteroid *small_asteroid;

public:
    asteroids_point_zero();
    void draw_spaceship();
    void draw_small_asteroid();
    void checkMouseClick(int, int);
};
