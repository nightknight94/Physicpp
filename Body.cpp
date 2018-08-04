#include "Body.hpp"

namespace physic
{
    Body::Body()
    {
        setMaterial(m_material);
    }

    void Body::setMaterial(const Material &material)
    {
        double volume = 2 * 3.1415 * m_shape.getRadius(); // shape.getVolume()

        m_material = material;
        m_mass = Mass(volume * m_material.m_density);
    }

    void Body::update(double dt)
    {
        m_velocity += (m_force / m_mass) * dt;
        m_position += m_velocity * dt;

        m_shape.setPosition(m_position(0), m_position(1));

        m_force.fill(0);
    }

} // namespace physic