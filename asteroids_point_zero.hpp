#include <SDL.h>
#include "spaceship.hpp"
#include "small_asteroid.hpp"
#include <vector>

using namespace std;
#pragma once

class asteroids_point_zero
{
private:
    Spaceship *spaceship;
    vector<Small_Asteroid> small_asteroid;

public:
    asteroids_point_zero();
    void draw_spaceship();
    void draw_small_asteroid();
    void create_objects();
    void checkMouseClick(int, int);
};
