#pragma once

#include "Movable.hpp"
#include "Touchable.hpp"

namespace physic
{
class Material;

class Particle final : public Movable, public Touchable
{
  protected:
    math::Vector<2> force{};

  public:
    Particle() = default;

    void addForce(const math::Vector<2> &i_force) { force += i_force; };
    void update(double dt);
};
} // namespace physic