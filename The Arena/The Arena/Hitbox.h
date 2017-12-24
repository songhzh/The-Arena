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
	virtual void updatePos(sf::Vector2f pos);
	virtual void onHit(Player* target);
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
	Vishnu_punch(sf::RectangleShape b, sf::Vector2f ofs);
	void onHit(Player* target) {}
	void draw(sf::RenderWindow* w);

};

class Vishnu_kick : public Hitbox
{
public:
	Vishnu_kick(sf::RectangleShape b, sf::Vector2f ofs);
	void onHit(Player* target) {}
	void draw(sf::RenderWindow* w);
};

class Vishnu_projectile : public Hitbox
{
public:
	Vishnu_projectile(sf::RectangleShape b, sf::Vector2f ofs);
	Vishnu_projectile* clone();
	void onHit(Player* target);
	void draw(sf::RenderWindow* w);
};
