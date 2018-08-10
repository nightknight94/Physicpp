#pragma once

#include "Mass.hpp"
#include "Matrix.hpp"

namespace physic
{
    class Shape;
    class Material;

    class Object
    {
      public:
        math::Vector<2> position{};
        math::Vector<2> velocity{};
        math::Vector<2> force{};

        Mass mass{};
        const Material *material{nullptr};
        const Shape *shape{nullptr};

        virtual void resolvePhysics(double dt);

      public:
        virtual ~Object() = default;

        virtual void setMaterial(const Material &m) = 0;
        virtual void setShape(const Shape &s) = 0;

        virtual void update(double dt) = 0;
    };

} // namespace physic