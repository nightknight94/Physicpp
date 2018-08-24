#pragma once

#include "utils/Matrix.hpp"

namespace physic
{
class Particle;

class CollisionSolver
{
  private:
	Particle * A{nullptr};
	Particle * B{nullptr};
	utils::Vector<2> collisionNormal{};
	double depth{};
	utils::Vector<2> relativeVelocity{};
	double velocityNormal{};

	bool detected();
	void resolve();
	void correctPosition();

  public:
	CollisionSolver() = default;
	void operator()(Particle & a, Particle & b);
};

} // namespace physic