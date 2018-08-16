#pragma once

#include "Matrix.hpp"

namespace physic
{
class IBody;

class CollisionSolver
{
  private:
    IBody *A{nullptr};
    IBody *B{nullptr};
    math::Vector<2> collisionNormal{};
    double depth{};
    math::Vector<2> relativeVelocity{};
    double velocityNormal{};

    bool detected();
    void resolve();
    void correctPosition();

  public:
    CollisionSolver() = default;
    void operator()(IBody &a, IBody &b);
};

} // namespace physic