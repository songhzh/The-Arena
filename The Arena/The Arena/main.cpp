#include <SFML/Graphics.hpp>
#include "GameStateManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1600, 900), "The Arena", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	GameStateManager gsm(&window);
	
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
				gsm.setPause(true);
				break;
			case sf::Event::GainedFocus:
				gsm.setPause(false);
				break;
			default:
				break;
			}
		}

		window.clear(sf::Color(100, 155, 100, 255));
		gsm.update();
		window.display();
		//sf::sleep(sf::milliseconds(100));
	}

	return 0;
}