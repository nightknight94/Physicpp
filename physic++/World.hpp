#pragma once

#include "Matrix.hpp"

#include <vector>

namespace physic
{
    class Object;

    // TODO: Add unit tests
    class World
    {
      private:
        std::vector<Object*> objects;
        math::Vector<2> gravity;

      public:
        void setGravity(math::Vector<2> g);

        void addObject(Object &o);

        void update(double dt);
    };

} // namespace physic