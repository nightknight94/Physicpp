#pragma once

#include "Mass.hpp"
#include "Matrix.hpp"

namespace physic
{
class IShape;
class Material;

class IBody
{
  public:
    math::Vector<2> position{};
    math::Vector<2> velocity{};
    math::Vector<2> force{};

    Mass mass{};
    const Material *material{nullptr};
    const IShape *shape{nullptr};

    virtual void resolvePhysics(double dt);

  public:
    virtual ~IBody() = default;

    virtual void setMaterial(const Material &m) = 0;
    virtual void setShape(const IShape &s) = 0;

    virtual void update(double dt) = 0;
};

} // namespace physic