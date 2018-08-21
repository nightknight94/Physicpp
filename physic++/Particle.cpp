#include "Particle.hpp"

namespace physic
{
void Particle::setRadius(double i_radius)
{
	radius = i_radius;
}

double Particle::getRadius()
{
	return radius;
}

void Particle::update(double dt)
{
	setAcceleration(force / mass);
	force.fill(0);

	calculateMovement(dt);
}

} // namespace physic
