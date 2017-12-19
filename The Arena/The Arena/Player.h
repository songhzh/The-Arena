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
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	void move();
	void updateAnimation(float df);

	float walkSpd = 20;
};

