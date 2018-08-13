// Copyright 2018

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Body.hpp"
#include "World.hpp"

namespace physic {
TEST(WorldTest, WorldBasicTest) {
  World world;
  Body body;

  world.addObject(body);
  world.setGravity(math::Vector<2>({0, 0}));
  world.update(0.01);
}
}  // namespace physic
