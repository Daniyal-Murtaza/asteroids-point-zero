#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero()
{
    spaceship = new Spaceship();
}

void asteroids_point_zero::draw_spaceship()
{
    spaceship->draw();
}

void asteroids_point_zero::draw_small_asteroid()
{
    for (auto &a : small_asteroid)
    {
        a->draw();
        a->fly();
    }
}

void asteroids_point_zero::draw_medium()
{
    for (auto &m : medium)
    {
        m.draw();
        m.fly();
    }
}

void asteroids_point_zero::draw_hard()
{
    for (auto &h : hard)
    {
        h.draw();
        h.fly();
    }
}

void asteroids_point_zero::draw_bullets()
{
    for (auto &b : bullets)
    {
        b->draw();
        // b->fly();
        for (auto &a : small_asteroid)
        {
            SDL_Rect b1 = b->getMov();
            SDL_Rect a1 = a->getMov();
            if (SDL_HasIntersection(&a1, &b1))
            {
                a->exploded = true;
                b->exploded = true;
            }
            b->fly();
        }
    }
}

void asteroids_point_zero::create_small_asteroid()
{
    int n = rand() % 550;
    int p = rand() % 10;
    if (p == 1)
    {
        Small_Asteroid *s1 = new Small_Asteroid(n);
        small_asteroid.push_back(s1);
    }
}

void asteroids_point_zero::create_bullets(int x, int y)
{
    Bullet *b1 = new Bullet(x, y);
    bullets.push_back(b1);
}

void asteroids_point_zero::create_medium()
{
    int n = rand() % 550;
    int p = rand() % 10;
    if (p == 1)
    {
        Medium s1(n);
        medium.push_back(s1);
    }
}

void asteroids_point_zero::create_hard()
{
    int n = rand() % 550;
    int p = rand() % 10;
    if (p == 1)
    {
        Hard s1(n);
        hard.push_back(s1);
    }
}

void asteroids_point_zero::checkMouseClick(int x, int y)
{
    spaceship->setMov(x, y);
}
