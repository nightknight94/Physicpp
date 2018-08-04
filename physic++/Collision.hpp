#pragma once

#include "Matrix.hpp"

namespace physic
{
    class Body;

    class Collision
    {
      private:
        Body &A;
        Body &B;
        math::Vector<2> collisionNormal;
        double depth;
        math::Vector<2> relativeVelocity;
        double velocityNormal;

        bool detected();
        void resolve();
        void correctPosition();
      public:
        Collision(Body &a, Body &b);
    };

} // namespace physic