#pragma once

#include <SFML/Graphics.hpp>
#include "Hitbox.h"

class Hitbox;

class Player
{
	enum { UP, DOWN, LEFT, RIGHT, B1, B2 };
	enum animationFrame { STILL_1, STILL_2};

public:
	Player();
	~Player();
	void init(int role);
	void updateAll(float df);
private:
	void move();
	void updateAnimation(float df);

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	animationFrame currentAnimationFrame;
	float framesToUpdate;
	
	std::vector<Hitbox> hurt;
	std::vector<Hitbox> proj; // Projectile, detached from player
	std::vector<Hitbox> flow; // Follows player

	sf::Keyboard::Key input[6];

	float walkSpd = 20;
};

