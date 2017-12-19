#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	Player();
	~Player();
	void init(int r);
	void update(float df);
private:
	enum Control { UP, DOWN, LEFT, RIGHT, B1, B2, ERROR };

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::Keyboard::Key input[6];

	void move();
	void updateAnimation(float df);

	float walkSpd = 20;
};

