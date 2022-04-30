#include "asteroids_point_zero.hpp"

asteroids_point_zero::asteroids_point_zero() // constructor of class asteroids_point_zero
{
    spaceship = new Spaceship(); // dynamically creating a spaceship
    // Life = new Lives();
    // ML = new Mid_Life();
    // EL = new End_Life();
}

void asteroids_point_zero::draw_spaceship() // drawing the spaceship here
{
    spaceship->draw(); // calling function draw from the spaceship class
}

void asteroids_point_zero::draw_small_asteroid() // drawing the small asteroids
{
    for (auto &a : small_asteroid) // initializing small asteroids
    {
        a->draw(); // calling the draw functionality in the small asteroids
        a->fly();  // calling the fly functionality in the fly function
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

void asteroids_point_zero::draw_fire()
{
    for (auto &f : fire)
    {
        f->draw();
        f->fly();
    }
}

void asteroids_point_zero::draw_ufo() // drawing the UFO
{
    for (auto &u : ufo) // initializing the UFO
    {
        u->draw(); // calling the draw functionality in the UFO
        u->fly();  // calling the fly functionality in the UFO
    }
}

void asteroids_point_zero::draw_bonus() // drawing the bonus
{
    for (auto &b : bonus) // initializing the bonus
    {
        b->draw(); // calling the draw functionality in the bonus
        b->fly();  // calling the fly functionality in the fly
    }
}

void asteroids_point_zero::draw_heart() // calling the draw heart function here
{
    Life.draw(); // calling the draw functionality for life here
}

// void asteroids_point_zero::draw_Mid_Life()
// {
//     ML->draw();
// }

// void asteroids_point_zero::draw_End_Life()
// {
//     EL->draw();
// }

void asteroids_point_zero::draw_medium() // drawing the medium level asteroids
{
    for (auto &m : medium) // initializing the medium
    {
        m->draw(); // calling the draw functionality in medium asteroids
        m->fly();  // calling the fly functionality in medium asteroids
    }
}

void asteroids_point_zero::draw_hard() // drawing the hard level asteroids
{
    for (auto &h : hard) // intiializing the hard asteroids
    {
        h->draw(); // calling the draw functionality in the hard asteroids
        h->fly();  // calling the fly functionality in the hard asteroids
    }
}

void asteroids_point_zero::draw_bullets() // drawing the bullets here
{
    for (auto &b : bullets) // initialzing the bullets here
    {
        b->draw(); // calling the draw function here
        // b->fly();
        for (auto &a : small_asteroid) // calling for loop
        {
            SDL_Rect b1 = b->getMov(); // initializing b1 with the getMov function and same happens in the next line
            SDL_Rect a1 = a->getMov();
            if (SDL_HasIntersection(&a1, &b1)) // taking memory of the two objects
            {
                a->exploded = true; // if asteroids are exploded
                b->exploded = true; // and the bullets are exploded
                if (b->exploded)
                {
                    b->removeBullet(); // bullets are removed from the screen
                }
                if (a->exploded)
                {
                    a->removeSmall_Asteroid(); // asteroids are removed from the screen
                    score += 10;
                    cout << "Score: " << score << endl;
                }
            }
            b->fly();
        }

        for (auto &m : medium) // if bullets collide with the medium level asteroids
        {
            SDL_Rect b1 = b->getMov(); // initializing b1 and m1 with the getMov function
            SDL_Rect m1 = m->getMov();
            if (SDL_HasIntersection(&m1, &b1)) // taking memory of the two objects
            {
                m->exploded = true; // if medium asteroids are exploded
                b->exploded = true; // bullet is exploded
                if (b->exploded)
                {
                    b->removeBullet(); // removing the bullets from the screen
                }
                if (m->exploded)
                {
                    m->removeMedium(); // removing the medium level asteroids
                    score += 10;
                    cout << "Score: " << score << endl;
                }
            }
            b->fly();
        }
        for (auto &h : hard) // if bullets collide with hard level asteroids
        {
            SDL_Rect b1 = b->getMov(); // initializing b1 and h1 with getMov function
            SDL_Rect h1 = h->getMov();
            if (SDL_HasIntersection(&h1, &b1)) // taking memory of the two objects
            {
                h->exploded = true; // if hard level asteroids are exploded
                b->exploded = true; // and bullet is exploded
                if (b->exploded)
                {
                    b->removeBullet(); // removing the bullets from the screen
                }
                if (h->exploded)
                {
                    h->removeHard(); // removing the hard level asteroids from the screen
                    score += 10;
                    cout << "Score: " << score << endl;
                }
            }
            b->fly();
        }
        for (auto &u : ufo) // if bullets collide with object UFO
        {
            SDL_Rect b1 = b->getMov(); // initializing b1 and u1 with getMov function
            SDL_Rect u1 = u->getMov();
            if (SDL_HasIntersection(&u1, &b1)) // taking memory of the two objects
            {
                u->exploded = true; // if UFO is exploded
                b->exploded = true; // if bullets are exploded
                if (b->exploded)
                {
                    b->removeBullet(); // removing bullets from the screen
                }
                if (u->exploded)
                {
                    u->remove_UFO(); // removing the hard level asteroids from the screen
                    score += 20;
                    cout << "Score: " << score << endl;
                }
            }
            b->fly();
        }
        for (auto &f : fire) // if bullets collide with object UFO
        {
            SDL_Rect b1 = b->getMov(); // initializing b1 and u1 with getMov function
            SDL_Rect f1 = f->getMov();
            if (SDL_HasIntersection(&f1, &b1)) // taking memory of the two objects
            {
                f->exploded = true; // if UFO is exploded
                b->exploded = true; // if bullets are exploded
                if (b->exploded)
                {
                    b->removeBullet(); // removing bullets from the screen
                }
                if (f->exploded)
                {
                    f->removeFire(); // removing the hard level asteroids from the screen
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
                    score += 30;
                    cout << "Score: " << score << endl;
                }
            }
            b->fly();
        }
    }
}

void asteroids_point_zero::collision() // function collision
{
    spaceship->draw();             // drawing the spaceship here
    Life.draw();                   // drawing the life here
    for (auto &a : small_asteroid) // initializing the small asteroids
    {
        SDL_Rect s1 = spaceship->getMov(); // initializing s1 and a1 with getMov
        SDL_Rect a1 = a->getMov();
        if (SDL_HasIntersection(&a1, &s1)) // taking memory of the two objects
        {
            a->exploded = true;
            spaceship->exploded = true;
            --Life;
            if (a->exploded)
            {
                a->removeSmall_Asteroid(); // we remove the small asteroid
            }
        }
        if (a->end)
            a->removeSmall_Asteroid(); // we remove the small asteroid in the end again
        a->draw();                     // call the draw functionality
        a->fly();                      // call the fly functionality
    }

    for (auto &m : medium) // if medium asteroid collides with spaceship
    {
        SDL_Rect s1 = spaceship->getMov(); // initialziing s1 and m1 with getMov function
        SDL_Rect m1 = m->getMov();
        if (SDL_HasIntersection(&m1, &s1)) // taking memory of the two objects
        {
            m->exploded = true;         // if medium asteroids explode
            spaceship->exploded = true; // and spaceship collides with the asteroids
            --Life;                     // life is deducted
            // cout << Life.n << " ";
            if (m->exploded) //
            {
                m->removeMedium(); // removing medium asteroid
            }
        }
        if (m->end)
            m->removeMedium(); // removing medium asteroid
        m->draw();             // calling draw functionality
        m->fly();              // calling fly functionality
    }

    for (auto &h : hard) // if hard asteroid collides with spaceship
    {
        SDL_Rect s1 = spaceship->getMov(); // initializing s1 and h1 with getMov function
        SDL_Rect h1 = h->getMov();
        if (SDL_HasIntersection(&h1, &s1)) // taking memory of the two objects
        {
            h->exploded = true;         // if hard asteroid explodes
            spaceship->exploded = true; // if spaceship collides with the hard asteroid
            --Life;                     // we deduct a life
            // cout << Life.n << " ";
            if (h->exploded)
            {
                h->removeHard(); // removing the hard asteroids
            }
        }
        if (h->end)
            h->removeHard(); // removing the hard asteroids
        h->draw();           // calling the draw functionality
        h->fly();            // calling the fly functionality
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

    for (auto &u : ufo) // collision with UFO
    {
        SDL_Rect s1 = spaceship->getMov(); // intiializing s1 and u1 with the getMov function
        SDL_Rect u1 = u->getMov();
        if (SDL_HasIntersection(&u1, &s1)) // taking memory of the two objects
        {
            u->exploded = true;         // if ufo explodes
            spaceship->exploded = true; // if spaceship collides with the
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
    for (auto &f : fire) // collision with UFO
    {
        SDL_Rect s1 = spaceship->getMov(); // intiializing s1 and u1 with the getMov function
        SDL_Rect f1 = f->getMov();
        if (SDL_HasIntersection(&f1, &s1)) // taking memory of the two objects
        {
            f->exploded = true;         // if ufo explodes
            spaceship->exploded = true; // if spaceship collides with the
            --Life;
            if (f->exploded)
            {
                f->removeFire();
            }
        }
        if (f->end)
            f->removeFire();
        f->draw();
        f->fly();
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
                score += 100;
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

void asteroids_point_zero::create_small_asteroid() //creating objects randomly 
{
    int n = rand() % 550;
    int p = rand() % 20; //probability of generation
    if (p == 1)
    {
        Small_Asteroid *s1 = new Small_Asteroid(n); //dynamically creating objects
        small_asteroid.push_back(s1); //pushing back objects
    }
}

void asteroids_point_zero::create_ufo()
{
    int n = rand() % 550;
    int p = rand() % 30; //probability of generation
    if (p == 1)
    {
        UFO *u1 = new UFO(n); //dynamically creating objects
        ufo.push_back(u1); //pushing back objects
    }
}

void asteroids_point_zero::create_tiny()
{
    int n = rand() % 550;
    int p = rand() % 50; //probability of generation
    if (p == 1)
    {
        Tiny *t1 = new Tiny(n); //dynamically creating objects
        tiny.push_back(t1); //pushing back objects
    }
}

void asteroids_point_zero::create_bonus()
{
    int n = rand() % 550;
    int p = rand() % 60; //probability of generation
    if (p == 1)
    {
        Bonus *b1 = new Bonus(n); //dynamically creating objects
        bonus.push_back(b1);//pushing back objects
    }
}

void asteroids_point_zero::create_fire()
{
    int n = rand() % 550;
    int p = rand() % 60; //probability of generation
    if (p == 1)
    {
        Fire *f1 = new Fire(n); //dynamically creating objects
        fire.push_back(f1); //pushing back objects
    }
}

void asteroids_point_zero::create_bullets(int x, int y)
{
    Bullet *b1 = new Bullet(x, y); //dynamically creating objects
    bullets.push_back(b1);  //pushing back objects
}

void asteroids_point_zero::create_medium()
{
    int n = rand() % 550;
    int p = rand() % 15; //probability of generation
    if (p == 1)
    {
        Medium *s1 = new Medium(n); //dynamically creating objects
        medium.push_back(s1); //pushing back objects
    }
}

void asteroids_point_zero::create_hard()
{
    int n = rand() % 550;
    int p = rand() % 10; //probability of generation
    if (p == 1)
    {
        Hard *s1 = new Hard(n); //dynamically creating objects
        hard.push_back(s1); //pushing back objects
    }
}

void asteroids_point_zero::checkMouseClick(int x, int y)
{
    spaceship->setMov(x, y);
}

// *************************************************************************************

void asteroids_point_zero::deleteObjects() //deleting objects here 
{
    SDL_Rect ObjectMov;
    for (auto &b : bullets) //removing objects
    {
        ObjectMov = b->getMov();
        if (ObjectMov.y < 0)
        {
            delete b;
            bullets.remove(b);
            // cout << "bullet removed";
        }
    }
    for (auto &a : small_asteroid) //removing objects
    {
        ObjectMov = a->getMov();
        if (ObjectMov.y > 700)
        {
            delete a;
            small_asteroid.remove(a);
            // cout << "small asteroid removed";
        }
    }
    for (auto &m : medium) //removing objects
    {
        ObjectMov = m->getMov();
        if (ObjectMov.y > 700)
        {
            delete m;
            medium.remove(m); //removing object from list
        }
    }
    for (auto &h : hard) //removing objects
    {
        ObjectMov = h->getMov();
        if (ObjectMov.y > 700)
        {
            delete h;
            hard.remove(h); //removing object from list
        }
    }
    for (auto &u : ufo) //removing objects
    {
        ObjectMov = u->getMov();
        if (ObjectMov.y > 700)
        {
            delete u;
            ufo.remove(u); //removing object from list
        }
    } 
    for (auto &b : bonus) //removing objects
    {
        ObjectMov = b->getMov();
        if (ObjectMov.y > 700)
        {
            delete b;
            bonus.remove(b); //removing object from list
        }
    }
    for (auto &t : tiny) //removing objects
    {
        ObjectMov = t->getMov();
        if (ObjectMov.y > 700)
        {
            delete t;
            tiny.remove(t); //removing object from list
        }
    }
    for (auto &f : fire) //removing objects
    {
        ObjectMov = f->getMov();
        if (ObjectMov.y > 700)
        {
            delete f;
            fire.remove(f); //removing object from list
        }
    }
}

asteroids_point_zero::~asteroids_point_zero()
{
    for (auto &b : bullets) //deleting objects here
    {
        delete b; //deleted
    }
    for (auto &a : small_asteroid)//deleting objects here
    { 
        delete a; //deleted
    }
    for (auto &m : medium)//deleting objects here
    {
        delete m; //deleted
    }
    for (auto &h : hard)//deleting objects here
    {
        delete h; //deleted
    }
    for (auto &u : ufo)//deleting objects here
    {
        delete u; //deleted
    }
    for (auto &b : bonus)//deleting objects here
    {
        delete b; //deleted
    }
    for (auto &t : tiny)//deleting objects here
    {
        delete t; //deleted
    }
    for (auto &f : fire)//deleting objects here
    {
        delete f; //deleted
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
    Message_rect.x = 15;   // controls the rect's x coordinate
    Message_rect.y = 60;   // controls the rect's y coordinte
    Message_rect.w = 50;   // controls the width of the rect
    Message_rect.h = 25;   // controls the height of the rect

    SDL_RenderCopy(Drawing::gRenderer, Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    TTF_Quit();
}