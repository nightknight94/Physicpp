// Copyright 2018

#pragma once

#include "IShape.hpp"
#include "Matrix.hpp"

namespace physic {
class AABB : public IShape {
 private:
  math::Vector<2> minPoint;
  math::Vector<2> maxPoint;

 public:
  explicit AABB(math::Vector<2> i_minPoint, math::Vector<2> i_maxPoint);

  virtual double getDistanceToCenter() const;
  virtual double getVolume() const;

  virtual double getMomentOfInertia(const Mass &mass) const;
};
}  // namespace physic