#include "Body.hpp"
#include "Circle.hpp"
#include "Material.hpp"
#include "Matrix.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>

// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
int main()
{
    physic::World w;
    w.setGravity(math::Vector<2>({0.0, 9.81}));


    sf::RenderWindow window(sf::VideoMode(800, 600), "");
    window.setFramerateLimit(100);

    physic::Circle c1(10);
    physic::Circle c2(10);

    physic::Body b1;
    physic::Body b2;

    w.addObject(b1);
    w.addObject(b2);

    b1.position = math::Vector<2>({400, 0});
    b2.position = math::Vector<2>({400, 200});

    b1.setShape(c1);
    b2.setShape(c2);
    b1.setMaterial(materials::Bouncy);
    b2.setMaterial(materials::Static);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();

        w.update(0.01);

        sf::CircleShape circ1(10);
        sf::CircleShape circ2(10);
        circ1.setPosition(b1.position(0), b1.position(1));
        circ2.setPosition(b2.position(0), b2.position(1));

        window.draw(circ1);
        window.draw(circ2);

        window.display();
    }
    return 0;
}
