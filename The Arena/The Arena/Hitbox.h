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
	virtual Hitbox* clone();
	virtual void update(Player* owner);
	virtual void onHit(Player* target);
	virtual void dbTest() {}
protected:
	sf::Vector2f offset;
	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Vector2f acc;

	sf::RectangleShape box;
};

class Hurtbox : public Hitbox
{
public:
	Hurtbox* clone();
	void init(sf::Vector2f ofs);
	void update(Player* owner);


};

class Projectile : public Hitbox
{
public:
	Projectile* clone();
	void update(Player* owner);
	void onHit(Player* target);
	void dbTest();
private:
	void inc();
};
