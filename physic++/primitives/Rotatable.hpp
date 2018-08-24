#pragma once

#include "Matrix.hpp"

namespace physic
{
namespace primitives
{
class Rotatable
{
  protected:
	double angle{};
	double angularVelocity{};
	double angularAcceleration{};

	virtual void calculateRotation(double dt)
	{
		angularVelocity += angularAcceleration * dt;
		angle += angularVelocity * dt;
	}

  public:
	virtual ~Rotatable() = default;

	virtual double getAngle() const { return angle; };
	virtual double getAngularVelocity() const { return angularVelocity; };
	virtual double getAngularAcceleration() const { return angularAcceleration; };

	virtual void setAngle(const double & i_angle) { angle = i_angle; };
	virtual void setAngularVelocity(const double & i_angularVelocity) { angularVelocity = i_angularVelocity; };
	virtual void setAngularAcceleration(const double & i_angularAcceleration) { angularAcceleration = i_angularAcceleration; };
};
} // namespace primitives
} // namespace physic
