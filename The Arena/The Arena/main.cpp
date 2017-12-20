#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "The Arena", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);

	GameStateManager gsm(&window);
	window.setKeyRepeatEnabled(false);

	//sf::Clock clock;
	//float deltaTime;

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::TextEntered:
				//std::cout << evt.text.unicode << std::endl;;
				break;
			case sf::Event::KeyPressed:
				gsm.keyPressed(evt.key.code);
				//std::cout << evt.key.code << std::endl;
				break;
			case sf::Event::LostFocus:
				break;
			case sf::Event::GainedFocus:
				break;
			default:
				break;
			}
		}

		window.clear();
		//deltaTime = clock.restart().asSeconds();
		gsm.update();
		window.display();
	}

	return 0;
}