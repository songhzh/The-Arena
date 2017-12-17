#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

class Player;

enum hitboxType { PROJECTILE, FOLLOWER };

class Hitbox
{
public:
	Hitbox(Player* p, hitboxType h);
	~Hitbox();
	void update(float df);
	void onHit(Player* target);
private:
	hitboxType hbt;
	Player* owner;
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::RectangleShape box;
};
