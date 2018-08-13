// Copyright 2018

#include "AABB.hpp"
#include "Mass.hpp"

namespace physic {
AABB::AABB(math::Vector<2> i_minPoint, math::Vector<2> i_maxPoint)
    : minPoint(i_minPoint), maxPoint(i_maxPoint) {}

double AABB::getDistanceToCenter() const {
  return (maxPoint(0) - minPoint(0)) / 2;
}

double AABB::getVolume() const {
  const double x = maxPoint(0) - minPoint(0);
  const double y = maxPoint(1) - minPoint(1);

  return x * y;
}

double AABB::getMomentOfInertia(const Mass &mass) const { return 1.0 * mass; }

}  // namespace physic
