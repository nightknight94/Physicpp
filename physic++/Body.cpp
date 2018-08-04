#include "Body.hpp"
#include "Shape.hpp"

namespace physic
{
    Body::Body(const Shape & s)
    :
        shape(s)
    {
        setMaterial(m_material);
    }

    void Body::setMaterial(const Material &material)
    {
        double volume = shape.getVolume();

        m_material = material;
        m_mass = Mass(volume * m_material.m_density);
    }

    void Body::update(double dt)
    {
        m_velocity += (m_force / m_mass) * dt;
        m_position += m_velocity * dt;

        m_force.fill(0);
    }

} // namespace physic