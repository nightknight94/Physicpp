#pragma once

#include "Mass.hpp"
#include "Matrix.hpp"

namespace physic
{
    class Shape;
    class Material;

    // TODO: Add mock
    class Object
    {
      public:
        math::Vector<2> position{};
        math::Vector<2> velocity{};
        math::Vector<2> force{};

        Mass mass{0};
        const Material *material{nullptr};
        const Shape *shape{nullptr};

      public:
        virtual ~Object() = default;

        virtual void setMaterial(const Material &m) = 0;
        virtual void setShape(const Shape &s) = 0;

        virtual void update(double dt) = 0;
    };

} // namespace physic