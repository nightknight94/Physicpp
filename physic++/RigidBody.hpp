#pragma once

#include "primitives/Movable.hpp"
#include "primitives/Rotatable.hpp"
#include "primitives/Touchable.hpp"

namespace physic
{
// Provides minimal implementation needed for rigid body
class RigidBody
    : public Movable
    , public Rotatable
    , public Touchable
{
  public:
	virtual ~RigidBody() = default;

	virtual void update(double dt) = 0;
};

} // namespace physic