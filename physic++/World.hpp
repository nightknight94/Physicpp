#pragma once

#include "CollisionSolver.hpp"
#include "Matrix.hpp"

#include <vector>

namespace physic
{
class Particle;

class World
{
  private:
	std::vector<Particle *> particles;

	math::Vector<2> gravity;

	double updateRateInv{};
	double updateTimer{};

	CollisionSolver collisionSolver;
	void resolveCollisions();
	void bruteForceCheck(std::vector<physic::Particle *> p);
	void bruteForceCheckOptimized(std::vector<physic::Particle *> p);

  public:
	void setGravity(const math::Vector<2> & i_gravity) { gravity = i_gravity; }
	void setUpdateRate(double i_rate);
	void addParticles(std::vector<Particle> & i_particles);

	void update(double dt);
};

} // namespace physic