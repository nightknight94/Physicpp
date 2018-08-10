// Copyright 2018

#pragma once

namespace physic {
class Mass;

class Shape {
 public:
  virtual ~Shape(){};

  virtual double getDistanceToCenter() const = 0;
  virtual double getVolume() const = 0;

  virtual double getMomentOfInertia(const Mass &mass) const = 0;
};

}  // namespace physic