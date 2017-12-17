#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
	enum { UP, DOWN, LEFT, RIGHT, B1, B2 };

public:
	Player();
	~Player();
	void init(int role);
	void update(float df);
private:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::Keyboard::Key input[6];

	void move();
	void updateAnimation(float df);

	float walkSpd = 20;
};

