// Copyright 2018

#pragma once

#include "Matrix.hpp"

namespace physic {
class IBody;

class Collision {
 private:
  IBody &A;
  IBody &B;
  math::Vector<2> collisionNormal;
  double depth;
  math::Vector<2> relativeVelocity;
  double velocityNormal;

  bool detected();
  void resolve();
  void correctPosition();

 public:
  Collision(IBody &a, IBody &b);
};

}  // namespace physic