#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();
	~Player();
private:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::RectangleShape hurtBox;
};

