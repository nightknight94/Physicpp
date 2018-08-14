#include <gtest/gtest.h>

#include "Collision.hpp"

#include "mocks/IShapeMock.hpp"

#include "Body.hpp"

namespace physic
{
TEST(CollisionTest, CollisionBasicTest)
{
    IShapeMock s1;
    IShapeMock s2;

    ON_CALL(s1, getDistanceToCenter()).WillByDefault(testing::Return(10));
    ON_CALL(s1, getDistanceToCenter()).WillByDefault(testing::Return(20));

    Body b1;
    Body b2;

    b1.setShape(s1);
    b2.setShape(s2);

    Collision(b1, b2);
}

} // namespace physic
