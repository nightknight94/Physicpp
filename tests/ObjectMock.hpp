#pragma once

#include <gmock/gmock.h>
#include "Object.hpp"

#include "Material.hpp"
#include "Shape.hpp"

namespace physic
{
    class ObjectMock : public Object
    {
      public:
        MOCK_METHOD1(setMaterial, void(const Material &));
        MOCK_METHOD1(setShape, void(const Shape &));
        MOCK_METHOD1(update, void(double));
    };
} // namespace physic