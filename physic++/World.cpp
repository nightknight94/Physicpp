#include "World.hpp"

#include "Particle.hpp"

namespace physic
{

void World::addParticles(std::vector<Particle> &i_particles)
{
    for(auto &p : i_particles)
    {
        particles.push_back(&p);
    }
}


void World::setUpdateRate(double i_rate)
{
    updateRateInv = (i_rate == 0) ? 0 : 1 / i_rate;
}

void World::resolveCollisions()
{
    for(auto &particle1 : particles)
    {
        for(auto &particle2 : particles)
        {
            collisionSolver((*particle1), (*particle2));
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

    for(auto &particle : particles)
    {
        particle->addForce(gravity * particle->getMass());
        particle->update(updateTimer);
    }
    std::cout << 1 / updateTimer << "\n";
    updateTimer = 0;
}

} // namespace physic
