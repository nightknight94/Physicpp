#include "Body.hpp"
#include "Collision.hpp"
#include "Matrix.hpp"
#include "Circle.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>


// TODO: Check test coverage
// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "");
    window.setFramerateLimit(100);

    physic::Circle c1(10);
    physic::Circle c2(10);

    physic::Body b1(c1);
    physic::Body b2(c2);

    b1.m_position = math::Vector<2>({400, 0});
    b2.m_position = math::Vector<2>({400, 200});

    b1.setMaterial(materials::Bouncy);
    b2.setMaterial(materials::Static);

    while(window.isOpen())
    {
        b1.m_force += math::Vector<2>({0.0, 9.81 * b1.m_mass});

        physic::Collision(b1, b2);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();

        b1.update(0.01);
        b2.update(0.01);
        
        sf::CircleShape circ1(10);
        sf::CircleShape circ2(10);
        circ1.setPosition(b1.m_position(0), b1.m_position(1));       
        circ2.setPosition(b2.m_position(0), b2.m_position(1));
        
        window.draw(circ1);
        window.draw(circ2);

        window.display();
    }
    return 0;
}
