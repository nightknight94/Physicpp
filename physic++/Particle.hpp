#pragma once

#include "primitives/Movable.hpp"
#include "primitives/Touchable.hpp"

namespace physic
{
class Material;

class Particle final
    : public Movable
    , public Touchable
{
  protected:
	utils::Vector<2> force;
	double radius{5.0};

  public:
	Particle() { volume = 3.1415 * radius * radius; }

	void setRadius(double i_radius);
	double getRadius();

	void addForce(const utils::Vector<2> & i_force) { force += i_force; };
	void update(double dt);
};
} // namespace physic