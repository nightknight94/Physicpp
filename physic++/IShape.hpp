#pragma once

namespace physic
{
class Mass;

class IShape
{
  public:
    virtual ~IShape() = default;

    virtual double getDistanceToCenter() const = 0;
    virtual double getVolume() const = 0;

    virtual double getMomentOfInertia(const Mass &mass) const = 0;
};

} // namespace physic