#pragma once

#include "utils/Matrix.hpp"

namespace physic
{
namespace primitives
{
class Movable
{
  protected:
	utils::Vector<2> position{};
	utils::Vector<2> velocity{};
	utils::Vector<2> acceleration{};

	virtual void calculateMovement(double dt)
	{
		velocity += acceleration * dt;
		position += velocity * dt;
	}

  public:
	virtual ~Movable() = default;

	virtual const utils::Vector<2> & getPosition() const { return position; };
	virtual const utils::Vector<2> & getVelocity() const { return velocity; };
	virtual const utils::Vector<2> & getAcceleration() const { return acceleration; };

	virtual void setPosition(const utils::Vector<2> & i_position) { position = i_position; };
	virtual void setVelocity(const utils::Vector<2> & i_velocity) { velocity = i_velocity; };
	virtual void setAcceleration(const utils::Vector<2> & i_acceleration) { acceleration = i_acceleration; };
};
} // namespace primitives
} // namespace physic