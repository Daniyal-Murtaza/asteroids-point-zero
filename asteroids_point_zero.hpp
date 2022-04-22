#include <SDL.h>
#include "spaceship.hpp"
using namespace std;

class asteroids_point_zero
{
private:
    Spaceship *spaceship;

public:
    asteroids_point_zero();
    ~asteroids_point_zero();
    draw_spaceship();
};
