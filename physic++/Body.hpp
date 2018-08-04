#pragma once

#include "Mass.hpp"
#include "Material.hpp"
#include "Matrix.hpp"

namespace physic
{
    class Shape;

    class Body
    {
      public:
        math::Vector<2> m_position;
        math::Vector<2> m_velocity;
        math::Vector<2> m_force;

        Mass m_mass{0};
        Material m_material{materials::Bouncy};

        const Shape & shape;

        Body(const Shape & s);
        void setMaterial(const Material &material);

        void update(double dt);
    };

} // namespace physic