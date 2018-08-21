#pragma once

#include "utils/Matrix.hpp"

namespace physic
{
class Movable
{
  protected:
	math::Vector<2> position{};
	math::Vector<2> velocity{};
	math::Vector<2> acceleration{};

	virtual void calculateMovement(double dt)
	{
		velocity += acceleration * dt;
		position += velocity * dt;
	}

  public:
	virtual ~Movable() = default;

	virtual const math::Vector<2> & getPosition() const { return position; };
	virtual const math::Vector<2> & getVelocity() const { return velocity; };
	virtual const math::Vector<2> & getAcceleration() const { return acceleration; };

	virtual void setPosition(const math::Vector<2> & i_position) { position = i_position; };
	virtual void setVelocity(const math::Vector<2> & i_velocity) { velocity = i_velocity; };
	virtual void setAcceleration(const math::Vector<2> & i_acceleration)
	{
		acceleration = i_acceleration;
	};
};
} // namespace physic