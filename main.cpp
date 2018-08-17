#include <iostream>
#include <vector>

#include "Body.hpp"
#include "Material.hpp"
#include "Matrix.hpp"
#include "Particle.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <random>

// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
// TODO: Interfaces (Collidable, physics object, etc)
// TODO: Cleanup - directories grouping same funcionality
int main()
{
    physic::World w;
    w.setGravity(math::Vector<2>({0.0, 9.81}));

    sf::RenderWindow window(sf::VideoMode(800, 600), "");

    constexpr double framerate = 100;
    w.setUpdateRate(framerate);

    std::vector<physic::Particle> Particles;

    for(size_t i = 0; i < 200; ++i)
    {
        Particles.push_back(physic::Particle(10, materials::Bouncy));
        Particles[i].position = math::Vector<2>({std::rand() % 800, std::rand() % 600});
        Particles[i].velocity += math::Vector<2>({0, -std::rand() % 80});
    }

    w.addParticles(Particles);

    sf::Clock clock;
    while(window.isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        float dt = elapsedTime.asSeconds();
        std::cout << "FPS: " << std::round(1 / dt) << "\n";

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

        w.update(dt);

        for(size_t i = 0; i < Particles.size(); ++i)
        {
            sf::CircleShape c;
            c.setRadius(Particles[i].getRadius());
            c.setPosition(Particles[i].position(0), Particles[i].position(1));
            window.draw(c);
        }

        window.display();
    }
    return 0;
}
