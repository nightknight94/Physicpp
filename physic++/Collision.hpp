#pragma once

#include "Matrix.hpp"

namespace physic
{
    class Object;

    class Collision
    {
      private:
        Object &A;
        Object &B;
        math::Vector<2> collisionNormal;
        double depth;
        math::Vector<2> relativeVelocity;
        double velocityNormal;

        bool detected();
        void resolve();
        void correctPosition();
      public:
        Collision(Object &a, Object &b);
    };

} // namespace physic