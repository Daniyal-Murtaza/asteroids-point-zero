#include <SDL.h>
#include "drawing.hpp"
#include "spaceship.hpp"
#include "small_asteroid.hpp"
#include <vector>
#include "score.hpp"
#include "bullet.hpp"
#include <SDL_ttf.h>
#include "medium.hpp"
#include "hard.hpp"
using namespace std;
#include <string>

using namespace std;
#pragma once

class asteroids_point_zero
{
private:
    Spaceship *spaceship;
    vector<Small_Asteroid *> small_asteroid;
    vector<Bullet *> bullets;
    vector<Medium *> medium;
    vector<Hard *> hard;

public:
    asteroids_point_zero();
    void draw_spaceship();
    void draw_small_asteroid();
    void draw_bullets();
    void draw_medium();
    void draw_hard();
    void create_small_asteroid();
    void create_medium();
    void create_hard();
    void create_bullets(int x, int y);
    void checkMouseClick(int, int);
};
