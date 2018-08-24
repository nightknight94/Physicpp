#include "Particle.hpp"
#include "World.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <random>
#include <vector>

constexpr int SI_PX_CONVERT = 100;

template <typename T>
constexpr auto si2px(T si)
{
	return si * SI_PX_CONVERT;
}

template <typename T>
constexpr auto px2si(T px)
{
	return px / SI_PX_CONVERT;
}

// TODO: Make sure everywhere SI is used
// TODO: Converter between SI and pixels
// TODO: Interfaces (Collidable, physics object, etc)
// TODO: Test coverage!
int main()
{
	physic::World w;
	// w.setGravity(physic::utils::Vector<2>({0.0, 9.81}));

	sf::RenderWindow window(sf::VideoMode(800, 600), "");

	constexpr double framerate = 100;
	w.setUpdateRate(framerate);

	constexpr int particleNumber = 500;
	std::vector<physic::Particle> Particles(particleNumber);

	for(size_t i = 0; i < particleNumber; ++i)
	{
		Particles[i].setMaterial(materials::Bouncy);
		Particles[i].setPosition(physic::utils::Vector<2>({(std::rand() % 400) + 200, (std::rand() % 300) + 100})); // px2si

		constexpr int veloAmp = 100;
		auto velo             = physic::utils::Vector<2>({std::rand() % veloAmp, std::rand() % veloAmp});
		velo                  = (std::rand() % 100) > 50 ? velo : -1 * velo;
		Particles[i].setVelocity(velo);
	}

	w.addParticles(Particles);

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

		for(size_t i = 0; i < Particles.size(); ++i)
		{
			sf::CircleShape c;
			c.setRadius(Particles[i].getRadius());
			c.setPosition(Particles[i].getPosition()(0),
			              Particles[i].getPosition()(1)); // si2px
			window.draw(c);
		}

		window.display();
	}
	return 0;
}
