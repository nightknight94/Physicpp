#include "Particle.hpp"
#include "World.hpp"
#include "physic++/utils/Convert.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <vector>

// TODO: Make sure everywhere SI is used
// TODO: Interfaces (Collidable, physics object, etc)
// TODO: Test coverage!
int main()
{
	physic::utils::Convert convert(100);

	physic::World w;
	// w.setGravity(physic::utils::Vector<2>({0.0, 9.81}));

	sf::RenderWindow window(sf::VideoMode(800, 600), "");

	constexpr double framerate = 100;
	w.setUpdateRate(framerate);

	constexpr int particleNumber = 500;
	std::vector<physic::Particle> particles;

	for(size_t i = 0; i < particleNumber; ++i)
	{
		physic::Particle particle(convert.px2si(5));
		particle.setMaterial(materials::Bouncy);
		particle.setPosition(
		    convert.px2si(physic::utils::Vector<2>({(std::rand() % 400) + 200, (std::rand() % 300) + 100}))); // px2si

		constexpr int veloAmp = 100;
		auto velo             = physic::utils::Vector<2>({std::rand() % veloAmp, std::rand() % veloAmp});
		velo                  = (std::rand() % 100) > 50 ? velo : -1 * velo;
		particle.setVelocity(convert.px2si(velo));

		particles.push_back(particle);
	}

	w.addParticles(particles);

	sf::Clock clock;
	while(window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		float dt             = elapsedTime.asSeconds();
		// std::cout << "FPS: " << std::round(1 / dt) << "\n";

		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
		}

		window.clear();

		w.update(dt);

		for(size_t i = 0; i < particles.size(); ++i)
		{
			sf::CircleShape c;
			c.setRadius(convert.si2px(particles[i].getRadius()));
			c.setPosition(convert.si2px(particles[i].getPosition()(0)),
			              convert.si2px(particles[i].getPosition()(1))); // si2px
			window.draw(c);
		}

		window.display();
	}
	return 0;
}
