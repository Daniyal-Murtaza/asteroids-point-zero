#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero()
{
    spaceship = new Spaceship();
    // Life = new Lives();
    // ML = new Mid_Life();
    // EL = new End_Life();
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

void asteroids_point_zero::draw_ufo()
{
    for (auto &u : ufo)
    {
        u->draw();
        u->fly();
    }
}

void asteroids_point_zero::draw_tiny()
{
    for (auto &t : tiny)
    {
        t->draw();
        t->fly();
    }
}

void asteroids_point_zero::draw_bonus()
{
    for (auto &b : bonus)
    {
        b->draw();
        b->fly();
    }
}

void asteroids_point_zero::draw_heart()
{
    Life.draw();
}

// void asteroids_point_zero::draw_Mid_Life()
// {
//     ML->draw();
// }

// void asteroids_point_zero::draw_End_Life()
// {
//     EL->draw();
// }

void asteroids_point_zero::draw_medium()
{
    for (auto &m : medium)
    {
        m->draw();
        m->fly();
    }
}

void asteroids_point_zero::draw_hard()
{
    for (auto &h : hard)
    {
        h->draw();
        h->fly();
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
                if (b->exploded)
                {
                    b->removeBullet();
                }
                if (a->exploded)
                {
                    a->removeSmall_Asteroid();
                }
            }
            b->fly();
        }
        for (auto &m : medium)
        {
            SDL_Rect b1 = b->getMov();
            SDL_Rect m1 = m->getMov();
            if (SDL_HasIntersection(&m1, &b1))
            {
                m->exploded = true;
                b->exploded = true;
                if (b->exploded)
                {
                    b->removeBullet();
                }
                if (m->exploded)
                {
                    m->removeMedium();
                }
            }
            b->fly();
        }
        for (auto &h : hard)
        {
            SDL_Rect b1 = b->getMov();
            SDL_Rect h1 = h->getMov();
            if (SDL_HasIntersection(&h1, &b1))
            {
                h->exploded = true;
                b->exploded = true;
                if (b->exploded)
                {
                    b->removeBullet();
                }
                if (h->exploded)
                {
                    h->removeHard();
                }
            }
            b->fly();
        }
        for (auto &u : ufo)
        {
            SDL_Rect b1 = b->getMov();
            SDL_Rect u1 = u->getMov();
            if (SDL_HasIntersection(&u1, &b1))
            {
                u->exploded = true;
                b->exploded = true;
                if (b->exploded)
                {
                    b->removeBullet();
                }
                if (u->exploded)
                {
                    u->remove_UFO();
                }
            }
            b->fly();
        }
        for (auto &t : tiny)
        {
            SDL_Rect b1 = b->getMov();
            SDL_Rect t1 = t->getMov();
            if (SDL_HasIntersection(&t1, &b1))
            {
                t->exploded = true;
                b->exploded = true;
                if (b->exploded)
                {
                    b->removeBullet();
                }
                if (t->exploded)
                {
                    t->removeTiny();
                }
            }
            b->fly();
        }
    }
}

void asteroids_point_zero::collision()
{
    spaceship->draw();
    Life.draw();
    for (auto &a : small_asteroid)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect a1 = a->getMov();
        if (SDL_HasIntersection(&a1, &s1))
        {
            a->exploded = true;
            spaceship->exploded = true;
            --Life;
            // cout << Life.n << " ";
            if (a->exploded)
            {
                a->removeSmall_Asteroid();
            }
        }
        if (a->end)
            a->removeSmall_Asteroid();
        a->draw();
        a->fly();
    }

    for (auto &m : medium)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect m1 = m->getMov();
        if (SDL_HasIntersection(&m1, &s1))
        {
            m->exploded = true;
            spaceship->exploded = true;
            --Life;
            // cout << Life.n << " ";
            if (m->exploded)
            {
                m->removeMedium();
            }
        }
        if (m->end)
            m->removeMedium();
        m->draw();
        m->fly();
    }

    for (auto &h : hard)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect h1 = h->getMov();
        if (SDL_HasIntersection(&h1, &s1))
        {
            h->exploded = true;
            spaceship->exploded = true;
            --Life;
            // cout << Life.n << " ";
            if (h->exploded)
            {
                h->removeHard();
            }
        }
        if (h->end)
            h->removeHard();
        h->draw();
        h->fly();
    }

    for (auto &u : ufo)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect u1 = u->getMov();
        if (SDL_HasIntersection(&u1, &s1))
        {
            u->exploded = true;
            spaceship->exploded = true;
            --Life;
            // cout << Life.n << " ";
            if (u->exploded)
            {
                u->remove_UFO();
            }
        }
        if (u->end)
            u->remove_UFO();
        u->draw();
        u->fly();
    }
    for (auto &t : tiny)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect t1 = t->getMov();
        if (SDL_HasIntersection(&t1, &s1))
        {
            t->exploded = true;
            spaceship->exploded = true;
            --Life;
            // cout << Life.n << " ";
            if (t->exploded)
            {
                t->removeTiny();
            }
        }
        if (t->end)
            t->removeTiny();
        t->draw();
        t->fly();
    }
    for (auto &b : bonus)
    {
        SDL_Rect s1 = spaceship->getMov();
        SDL_Rect b1 = b->getMov();
        if (SDL_HasIntersection(&b1, &s1))
        {
            b->exploded = true;
            spaceship->exploded = true;
            if (b->exploded)
            {
                b->remove_Bonus();
                score += 10;
                cout << "Score: " << score << endl;
            }
        }
        if (b->end)
        {
            b->remove_Bonus();
        }
        b->draw();
        b->fly();
    }
}

// ******************************************************************************

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

void asteroids_point_zero::create_ufo()
{
    int n = rand() % 550;
    int p = rand() % 40;
    if (p == 1)
    {
        UFO *u1 = new UFO(n);
        ufo.push_back(u1);
    }
}

void asteroids_point_zero::create_tiny()
{
    int n = rand() % 550;
    int p = rand() % 50;
    if (p == 1)
    {
        Tiny *t1 = new Tiny(n);
        tiny.push_back(t1);
    }
}

void asteroids_point_zero::create_bonus()
{
    int n = rand() % 550;
    int p = rand() % 60;
    if (p == 1)
    {
        Bonus *b1 = new Bonus(n);
        bonus.push_back(b1);
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
        Medium *s1 = new Medium(n);
        medium.push_back(s1);
    }
}

void asteroids_point_zero::create_hard()
{
    int n = rand() % 550;
    int p = rand() % 10;
    if (p == 1)
    {
        Hard *s1 = new Hard(n);
        hard.push_back(s1);
    }
}

void asteroids_point_zero::checkMouseClick(int x, int y)
{
    spaceship->setMov(x, y);
}

// *************************************************************************************

void asteroids_point_zero::deleteObjects()
{
    SDL_Rect ObjectMov;
    for (auto &b : bullets)
    {
        ObjectMov = b->getMov();
        if (ObjectMov.y < 0)
        {
            delete b;
            bullets.remove(b);
            // cout << "bullet removed";
        }
    }
    for (auto &a : small_asteroid)
    {
        ObjectMov = a->getMov();
        if (ObjectMov.y > 700)
        {
            delete a;
            small_asteroid.remove(a);
            // cout << "small asteroid removed";
        }
    }
    for (auto &m : medium)
    {
        ObjectMov = m->getMov();
        if (ObjectMov.y > 700)
        {
            delete m;
            medium.remove(m);
        }
    }
    for (auto &h : hard)
    {
        ObjectMov = h->getMov();
        if (ObjectMov.y > 700)
        {
            delete h;
            hard.remove(h);
        }
    }
    for (auto &u : ufo)
    {
        ObjectMov = u->getMov();
        if (ObjectMov.y > 700)
        {
            delete u;
            ufo.remove(u);
        }
    }
    for (auto &b : bonus)
    {
        ObjectMov = b->getMov();
        if (ObjectMov.y > 700)
        {
            delete b;
            bonus.remove(b);
        }
    }
    for (auto &t : tiny)
    {
        ObjectMov = t->getMov();
        if (ObjectMov.y > 700)
        {
            delete t;
            tiny.remove(t);
        }
    }
}

asteroids_point_zero::~asteroids_point_zero()
{
    for (auto &b : bullets)
    {
        delete b;
    }
    for (auto &a : small_asteroid)
    {
        delete a;
    }
    for (auto &m : medium)
    {
        delete m;
    }
    for (auto &h : hard)
    {
        delete h;
    }
    for (auto &u : ufo)
    {
        delete u;
    }
    for (auto &b : bonus)
    {
        delete b;
    }
    for (auto &t : tiny)
    {
        delete t;
    }
    bullets.clear();
}

void asteroids_point_zero::display_score()
{
    TTF_Init();
    // this opens a font style and sets a size
    TTF_Font *font = TTF_OpenFont("arial.ttf", 24);

    SDL_Color White = {255, 255, 255};
    string tmp = to_string(score);
    num_char = tmp.c_str();

    SDL_Surface *surfaceMessage =
        TTF_RenderText_Solid(font, num_char, White);

    // now you can convert it into a texture
    SDL_Texture *Message = SDL_CreateTextureFromSurface(Drawing::gRenderer, surfaceMessage);

    SDL_Rect Message_rect; // create a rect
    Message_rect.x = 350;  // controls the rect's x coordinate
    Message_rect.y = 200;  // controls the rect's y coordinte
    Message_rect.w = 70;   // controls the width of the rect
    Message_rect.h = 70;   // controls the height of the rect

    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}