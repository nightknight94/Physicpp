#include "Body.hpp"
#include "Collision.hpp"
#include "Matrix.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "");
    window.setFramerateLimit(100);

    physic::Body circles[2];
    circles[0].m_position = math::Vector<2>({400, 0});
    circles[1].m_position = math::Vector<2>({400, 200});

    circles[0].setMaterial(materials::Bouncy);
    circles[1].setMaterial(materials::Wood);

    while(window.isOpen())
    {
        circles[0].m_force += math::Vector<2>({0.0, 9.81 * circles[0].m_mass});

        physic::collision(circles[0], circles[1]);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();
        for(auto &c : circles)
        {
            c.update(0.01);
            window.draw(c.m_shape);
        }

        window.display();
    }
    return 0;
}
