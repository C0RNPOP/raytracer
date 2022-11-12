#include <iostream>

#include "point.hpp"
#include "vector.hpp"

struct Projectile
{
    Point position;
    Vector velocity;
};

struct Environment
{
    Vector gravity;
    Vector wind;
};

Projectile tick(Projectile proj, Environment env)
{
    Point position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;

    return Projectile{ position, velocity };
}

int main()
{
    Projectile proj{ Point{ 0, 1, 0 }, Vector{ 1, 1, 0 }.Normalized() };
    Environment env{ Vector{ 0, -0.1, 0 }, Vector{ -0.01, 0, 0 } };

    unsigned int turn = 0;
    while(proj.position.Y() > 0)
    {
        std::cout << "Turn " << turn << ": " << proj.position << "\n"; proj = tick(proj, env);
        turn++;
    }
}
