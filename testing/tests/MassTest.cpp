#include <gtest/gtest.h>

#include "Mass.hpp"

namespace physic
{
TEST(MassTest, MassOperatorsTest)
{
    Mass m1(100);
    Mass m2(0);

    EXPECT_EQ(100, 1 * m1);
    EXPECT_FLOAT_EQ(0.01, 1 / m1);

    EXPECT_EQ(0, 1 * m2);
    EXPECT_EQ(0, 1 / m2);
}
} // namespace physic