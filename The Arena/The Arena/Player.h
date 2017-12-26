#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
public:
	Player();
	~Player();
	void init(sf::Vector2f p);
	void update(int dir, float sm, int dlock);
	bool onGround();
	void jump();
	sf::Vector2f getPos();
	bool useUlt();
private:
	void walk(float dir, float sm);
	
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;
	void updateAnimation();
	float walkSpd = 20;
	float jumpSpd = -50;
	float ground;
	int ultCharge;
	const int ultCharge_max = 300;
};

