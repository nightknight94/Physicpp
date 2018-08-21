#include "World.hpp"

#include "Particle.hpp"

namespace physic
{
void World::addParticles(std::vector<Particle> & i_particles)
{
	for(auto & p : i_particles)
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
	bruteForceCheckOptimized(particles);
}

// 500 particles = 20 fps
void World::bruteForceCheck(std::vector<physic::Particle *> p)
{
	for(size_t i = 0; i < p.size(); ++i)
	{
		for(size_t j = 0; j < p.size(); ++j)
		{
			collisionSolver((*p[i]), (*p[j]));
		}
	}
}

// 500 particles = 36 fps
void World::bruteForceCheckOptimized(std::vector<physic::Particle *> p)
{
	for(size_t i = 0; i < p.size(); ++i)
	{
		for(size_t j = i; j < p.size(); ++j)
		{
			collisionSolver((*p[i]), (*p[j]));
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

	for(auto & particle : particles)
	{
		particle->addForce(gravity * particle->getMass());
		particle->update(updateTimer);
	}
	std::cout << 1 / updateTimer << "\n";
	updateTimer = 0;
}

} // namespace physic
