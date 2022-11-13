#include <iostream>

#include "canvas.hpp"
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
    Projectile proj{ Point{ 0, 1, 0 }, Vector{ 1, 1.8, 0 }.Normalized() * 11.25 };
    Environment env{ Vector{ 0, -0.1, 0 }, Vector{ -0.01, 0, 0 } };
    Canvas canvas{ 900, 500 };

    while(proj.position.Y() > 0)
    {
        double x = proj.position.X();
        double y = canvas.Height() - proj.position.Y();
        canvas(x, y) = Color{ x / canvas.Width(), y / canvas.Height(), 1 };
        proj = tick(proj, env);
    }

    std::cout << canvas.ToPPM();
}
