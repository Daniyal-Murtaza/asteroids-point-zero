#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero()
{
    spaceship = new Spaceship();
}

asteroids_point_zero::draw_spaceship()
{
    spaceship->draw();
}