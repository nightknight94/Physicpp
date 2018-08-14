#pragma once

#include "IShape.hpp"

namespace physic
{
class Circle : public IShape
{
  private:
    double radius;

  public:
    explicit Circle(double r);

    virtual double getDistanceToCenter() const;
    virtual double getVolume() const;

    virtual double getMomentOfInertia(const Mass &mass) const;
};
} // namespace physic