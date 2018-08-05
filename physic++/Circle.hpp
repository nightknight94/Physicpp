#pragma once

#include "Shape.hpp"

namespace physic
{
    class Circle : public Shape
    {
      private:
        double radius;

      public:
        explicit Circle(double r);
        virtual ~Circle(){};

        virtual double getDistanceToCenter() const;
        virtual double getVolume() const;

        virtual double getMomentOfInertia(const Mass &mass) const;
    };

} // namespace physic