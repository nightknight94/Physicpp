// Copyright 2018

#pragma once

#include <gmock/gmock.h>
#include "IShape.hpp"

namespace physic {
class IShapeMock : public IShape {
 public:
  MOCK_CONST_METHOD0(getDistanceToCenter, double());
  MOCK_CONST_METHOD0(getVolume, double());
  MOCK_CONST_METHOD1(getMomentOfInertia, double(const Mass &));
};
}  // namespace physic