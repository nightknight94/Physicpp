#pragma once

#include "Matrix.hpp"

#include <vector>

namespace physic
{
    class IBody;

    class World
    {
      private:
        std::vector<IBody*> bodies;
        math::Vector<2> gravity;

        void resolveCollisions();

      public:
        void setGravity(const math::Vector<2> &i_gravity);

        void addObject(IBody &i_body);

        void update(double dt);
    };

} // namespace physic