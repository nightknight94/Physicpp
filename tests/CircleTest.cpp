// Copyright 2018

#include <gtest/gtest.h>
#include "Circle.hpp"
#include "Mass.hpp"

namespace physic {
TEST(CircleTest, CircleBasicTest) {
  constexpr double R = 10;
  physic::Circle c(R);

  EXPECT_FLOAT_EQ(10, c.getDistanceToCenter());
  EXPECT_FLOAT_EQ(2 * 3.1415 * R * R, c.getVolume());

  Mass m(10);
  EXPECT_FLOAT_EQ((R * R) * m / 2, c.getMomentOfInertia(m));
}

}  // namespace physic
