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
#include "lives.hpp"
#include "mid_life.hpp"
#include "end_life.hpp"
#include "UFO.hpp"
using namespace std;
#include <string>
#include <list>

using namespace std;
#pragma once

class asteroids_point_zero
{
private:
    // Lives *Life;
    // Mid_Life *ML;
    // End_Life *EL;
    Spaceship *spaceship;
    list<Small_Asteroid *> small_asteroid;
    list<UFO *> ufo;
    list<Bullet *> bullets;
    list<Medium *> medium;
    list<Hard *> hard;

public:
    Lives Life;
    asteroids_point_zero();
    void draw_spaceship();
    void draw_small_asteroid();
    void draw_ufo();
    void draw_bullets();
    void draw_medium();
    void draw_hard();
    void draw_heart();
    // void draw_Mid_Life();
    // void draw_End_Life();
    void create_small_asteroid();
    void create_ufo();
    void create_medium();
    void create_hard();
    void create_bullets(int x, int y);
    void checkMouseClick(int, int);
    void collision();
    void deleteObjects();
    ~asteroids_point_zero();
};
