#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero()
{
    spaceship = new Spaceship();
    small_asteroid = new Small_Asteroid();
}

void asteroids_point_zero::draw_spaceship()
{
    spaceship->draw();
}

void asteroids_point_zero::draw_small_asteroid()
{
    small_asteroid->draw();
    small_asteroid->fly();
}

void asteroids_point_zero::checkMouseClick(int x, int y)
{
    spaceship->setMov(x, y);
}