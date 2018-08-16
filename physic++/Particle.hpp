#pragma once

#include "Mass.hpp"
#include "Matrix.hpp"

namespace physic
{
class IShape;
class Material;

class Particle
{
  public:
    double radius;

    math::Vector<2> position{};
    math::Vector<2> velocity{};
    math::Vector<2> force{};

    Mass mass{};
    const Material *material{nullptr};

    virtual void resolvePhysics(double dt);

  public:
    Particle(double i_radius, const Material &i_material);

    virtual double getRadius() const;
    virtual double getVolume() const;

    virtual void setMaterial(const Material &m);

    virtual void update(double dt);
};
} // namespace physic