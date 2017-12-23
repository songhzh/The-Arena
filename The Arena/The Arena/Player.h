#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	Player();
	~Player();
	void init(int r);
	void update(int dir, float sm);
	sf::Vector2f getPos();
private:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	void walk(float dir, float sm);
	void updateAnimation();

	float walkSpd = 20;
};

