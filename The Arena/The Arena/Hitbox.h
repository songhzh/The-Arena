#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"

class Hitbox
{
public:
	Hitbox();
	virtual ~Hitbox();
	virtual Hitbox* clone();
	virtual void draw(sf::RenderWindow* w);
	virtual void update(Player* owner);
	virtual void onHit(Player* target);
	virtual void setPos(sf::Vector2f pos);
	virtual void dbTest() {}
protected:
	sf::Vector2f offset;
	sf::RectangleShape box;
};

class Hurtbox : public Hitbox
{
public:
	Hurtbox(sf::RectangleShape b, sf::Vector2f ofs);
	//Hurtbox* clone();
	//void update(Player* owner);
};

class Vishnu_punch : public Hitbox
{
public:
	Vishnu_punch(sf::RectangleShape b, sf::Vector2f sf);
	void onHit(Player* target) {}
	void draw(sf::RenderWindow* w);

};

class Vishnu_kick : public Hitbox
{
public:
	Vishnu_kick(sf::RectangleShape b, sf::Vector2f sf);
	void onHit(Player* target) {}
	void draw(sf::RenderWindow* w);
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
