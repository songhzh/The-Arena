#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 800), "The Arena");
	window.setFramerateLimit(60);

	GameStateManager gsm(&window);
	//window.setKeyRepeatEnabled(false);

	//Clock clock;
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
				//cout << evt.key.code << endl;
				break;
			default:
				break;
			}
		}

		window.clear();
		//deltaTime = clock.restart().asSeconds();
		window.display();
	}

	return 0;
}