#pragma once

#include "Matrix.hpp"

#include <vector>

namespace physic
{
    class Object;

    class World
    {
      private:
        std::vector<Object*> objects;
        math::Vector<2> gravity;

        void resolveCollisions();

      public:
        void setGravity(const math::Vector<2> &i_gravity);

        void addObject(Object &i_object);

        void update(double dt);
    };

} // namespace physic