#pragma once

#include "Object.hpp"

namespace physic
{
    class Shape;

    // TODO: Should update be implemented here?
    class Body : public Object
    {
      public:
        ~Body() = default;

        void setMaterial(const Material &m) override;
        void setShape(const Shape &s) override;

        void update(double dt) override;
    };

} // namespace physic