#include "Player.h"

Player::Player()
{
	pos = { 100, 200 };
	vel = { 0, 0 };
	acc = { 0, 0 };
}

Player::~Player()
{
}

void Player::init(int r)
{	
	/*
	Projectile* proj = new Projectile(this);
	projectile.push_back(proj);
	*/
}

void Player::update(int dir)
{
	walk(dir);

	vel += acc;
	pos += vel;
	
	updateAnimation();
}

void Player::updateAnimation()
{
}

void Player::walk(int dir)
{
	vel.x = walkSpd * dir;
}

sf::Vector2f Player::getPos()
{
	return pos;
}