#include "World.hpp"

#include "CollisionSolver.hpp"
#include "IBody.hpp"

namespace physic
{

void World::setUpdateRate(double i_rate)
{
    updateRateInv = (i_rate == 0) ? 0 : 1 / i_rate;
}

void World::resolveCollisions()
{
    for(auto &body1 : bodies)
    {
        for(auto &body2 : bodies)
        {
            collisionSolver((*body1), (*body2));
        }
    }
}

void World::update(double dt)
{
    updateTimer += dt;
    if(updateTimer < updateRateInv)
    {
        return;
    }

    resolveCollisions();

    for(auto &body : bodies)
    {
        body->force += (gravity * body->mass);
        body->update(updateTimer);
    }
    updateTimer = 0;
}

} // namespace physic
