#include "Particle.hpp"

#include "Shape.hpp"

namespace physic
{
void Particle::update(double dt)
{
	setAcceleration(force / mass);
	force.fill(0);

	calculateMovement(dt);
}

} // namespace physic
