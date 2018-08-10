#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "World.hpp"
#include "ObjectMock.hpp"

namespace physic
{
    TEST(WorldTest, WorldBasicTest)
    {
        ObjectMock objectMock;
        World world;

        world.addObject(objectMock);
        world.setGravity(math::Vector<2>({0, 0}));
        world.update(0.01);
    }

} // namespace physic