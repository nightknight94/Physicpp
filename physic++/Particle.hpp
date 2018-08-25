#pragma once

#include "primitives/Movable.hpp"
#include "primitives/Touchable.hpp"

namespace physic
{
class Material;

class Particle final
    : public primitives::Movable
    , public primitives::Touchable
{
  protected:
	utils::Vector<2> force;
	double radius;

	void updateVolume();

  public:
	explicit Particle(double i_radius)
	    : radius(i_radius)
	{
		updateVolume();
	}

	void setRadius(double i_radius);
	double getRadius();

	// TODO: Make sure force is added once per update
	void addForce(const utils::Vector<2> & i_force) { force += i_force; };
	void update(double dt);
};
} // namespace physic