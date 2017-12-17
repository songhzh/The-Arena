#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

class Player;

class Hitbox
{
public:
	Hitbox();
	virtual ~Hitbox();
	virtual void update(float df);
	virtual void onHit(Player* target);
	virtual void dbTest() {}
protected:
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::RectangleShape box;
};

class Projectile : public Hitbox
{
public:
	void update(float df);
	void onHit(Player* target);
	void dbTest();
private:
	void inc();
};
