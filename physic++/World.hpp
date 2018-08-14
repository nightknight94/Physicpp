#pragma once

#include "Matrix.hpp"

#include <vector>

namespace physic
{
class IBody;

class World
{
  private:
    std::vector<IBody *> bodies;
    math::Vector<2> gravity;

    double updateRateInv{};
    double updateTimer{};

    void resolveCollisions();

  public:
    void setGravity(const math::Vector<2> &i_gravity) { gravity = i_gravity; }
    void setUpdateRate(double i_rate);
    void addObject(IBody &i_body) { bodies.push_back(&i_body); }

    void update(double dt);
};

} // namespace physic