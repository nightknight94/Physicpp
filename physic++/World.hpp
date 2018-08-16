#pragma once

#include "CollisionSolver.hpp"
#include "Matrix.hpp"

#include <vector>

namespace physic
{
class IBody;
class Particle;

class World
{
  private:
    std::vector<IBody *> bodies;
    std::vector<Particle *> particles;

    math::Vector<2> gravity;

    double updateRateInv{};
    double updateTimer{};

    CollisionSolver collisionSolver;
    void resolveCollisions();

  public:
    void setGravity(const math::Vector<2> &i_gravity) { gravity = i_gravity; }
    void setUpdateRate(double i_rate);
    void addObject(IBody &i_body) { bodies.push_back(&i_body); }
    void addParticles(std::vector<Particle> &i_particles);

    void update(double dt);
};

} // namespace physic