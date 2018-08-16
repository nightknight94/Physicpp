#include "Particle.hpp"
#include "Mass.hpp"

#include "IShape.hpp"
#include "Material.hpp"

namespace physic
{
Particle::Particle(double i_radius, const Material &i_material)
    : radius(i_radius)
{
    material = &i_material;

    mass = Mass(this->getVolume() * material->m_density);
}

double Particle::getRadius() const
{
    return radius;
}

double Particle::getVolume() const
{
    return 2.0 * 3.1415 * (radius * radius);
}

void Particle::setMaterial(const Material &m)
{
    material = &m;
}

void Particle::update(double dt)
{
    resolvePhysics(dt);
}

void Particle::resolvePhysics(double dt)
{
    velocity += (force / mass) * dt;
    position += velocity * dt;

    force.fill(0);
}

} // namespace physic
