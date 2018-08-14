#include <iostream>
#include <vector>

#include "Body.hpp"
#include "Circle.hpp"
#include "Material.hpp"
#include "Matrix.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
int main()
{
    physic::World w;
    w.setGravity(math::Vector<2>({0.0, 9.81}));

    sf::RenderWindow window(sf::VideoMode(800, 600), "");

    constexpr double framerate = 100;
    window.setFramerateLimit(framerate);
    w.setUpdateRate(framerate);

    std::vector<physic::Circle> circles{
        physic::Circle(10),
        physic::Circle(10),
        physic::Circle(20),
    };

    std::vector<physic::Body> bodies(circles.size());

    for(size_t i = 0; i < bodies.size(); ++i)
    {
        bodies[i].setShape(circles[i]);
        w.addObject(bodies[i]);
    }

    bodies[0].position = math::Vector<2>({400, 0});
    bodies[1].position = math::Vector<2>({400, 200});
    bodies[2].velocity = math::Vector<2>({70, 0});

    bodies[0].setMaterial(materials::Bouncy);
    bodies[1].setMaterial(materials::Static);
    bodies[2].setMaterial(materials::SuperBouncy);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed or
               sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();

        w.update(1 / framerate);

        std::vector<sf::CircleShape> drawCircles{
            sf::CircleShape(10),
            sf::CircleShape(10),
            sf::CircleShape(20),
        };

        for(size_t i = 0; i < circles.size(); ++i)
        {
            drawCircles[i].setPosition(bodies[i].position(0), bodies[i].position(1));
            window.draw(drawCircles[i]);
        }

        window.display();
    }
    return 0;
}
