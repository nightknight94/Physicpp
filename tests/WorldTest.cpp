// Copyright 2018

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "IBodyMock.hpp"
#include "World.hpp"

namespace physic {
TEST(WorldTest, WorldBasicTest) {
  IBodyMock ibodyMock;
  World world;

  world.addObject(ibodyMock);
  world.setGravity(math::Vector<2>({0, 0}));
  world.update(0.01);
}
}  // namespace physic
