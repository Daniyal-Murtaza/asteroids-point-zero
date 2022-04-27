#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero()
{
    spaceship = new Spaceship();
    // small_asteroid = new Small_Asteroid();
}

void asteroids_point_zero::draw_spaceship()
{
    spaceship->draw();
}

void asteroids_point_zero::draw_small_asteroid()
{
    for (auto &a : small_asteroid)
    {
        a.draw();
        a.fly();
    }
}

void asteroids_point_zero::create_objects()
{
    int n = rand() % 550;
    int p = rand() % 10;
    if (p == 1)
    {
        Small_Asteroid s1(n);
        small_asteroid.push_back(s1);
    }
}

void asteroids_point_zero::checkMouseClick(int x, int y)
{
    spaceship->setMov(x, y);
}