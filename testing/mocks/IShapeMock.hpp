#pragma once

#include <gmock/gmock.h>

#include "Shape.hpp"

namespace physic
{
class ShapeMock : public Shape
{
    //  MOCK_CONST_METHOD0(getDistanceToCenter, double());
    // MOCK_CONST_METHOD0(getVolume, double());
    // MOCK_CONST_METHOD1(getMomentOfInertia, double(const Mass &));
};
} // namespace physic