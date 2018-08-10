// Copyright 2018

#include "Circle.hpp"
#include "Mass.hpp"

namespace physic {
Circle::Circle(double r) : radius(r) {}

double Circle::getDistanceToCenter() const { return radius; }

double Circle::getVolume() const { return 2.0 * 3.1415 * (radius * radius); }

double Circle::getMomentOfInertia(const Mass &mass) const {
  return (1.0 / 2.0) * mass * (radius * radius);
}

}  // namespace physic
