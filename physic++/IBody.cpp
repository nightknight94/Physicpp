// Copyright 2018

#include "IBody.hpp"

namespace physic {
void IBody::resolvePhysics(double dt) {
  velocity += (force / mass) * dt;
  position += velocity * dt;

  force.fill(0);
}
}  // namespace physic
