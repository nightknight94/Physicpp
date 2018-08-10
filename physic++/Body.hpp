#pragma once

#include "Object.hpp"

namespace physic
{
    class Shape;

    class Body : public Object
    {
      public:
        void setMaterial(const Material &m) override;
        void setShape(const Shape &s) override;

        void update(double dt) override;
    };

} // namespace physic