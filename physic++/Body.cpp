#include "Body.hpp"

#include "Material.hpp"
#include "Shape.hpp"

namespace physic
{
    void Body::setShape(const Shape &s)
    {
        shape = &s;
    }

    void Body::setMaterial(const Material &m)
    {
        material = &m;

        double volume = shape->getVolume();
        mass = Mass(volume * material->m_density);
    }

    void Body::update(double dt)
    {
        velocity += (force / mass) * dt;
        position += velocity * dt;

        force.fill(0);
    }

} // namespace physic