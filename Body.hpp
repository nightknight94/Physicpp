#pragma once

#include "Mass.hpp"
#include "Material.hpp"
#include "Matrix.hpp"
#include <SFML/Graphics.hpp>

namespace physic
{
    class Body
    {
      public:
        math::Vector<2> m_position;
        math::Vector<2> m_velocity;
        math::Vector<2> m_force;

        Mass m_mass{0};
        Material m_material{materials::Bouncy};

        sf::CircleShape m_shape{10};

        Body();
        void setMaterial(const Material &material);

        void update(double dt);
    };


    // TODO:
    // struct Shape
    // {
    //     // opis geometryczny
    //     // bezwładność
    //     // moment bezwładności
    // };

} // namespace physic