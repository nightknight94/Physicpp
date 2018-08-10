#include "Object.hpp"

namespace physic
{
    void Object::resolvePhysics(double dt)
    {
        velocity += (force / mass) * dt;
        position += velocity * dt;

        force.fill(0);
    }
} // namespace physic