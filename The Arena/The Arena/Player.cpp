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

void Player::update(int dir, float sm)
{
	walk((float) dir, sm);

	vel += acc;
	pos += vel;
	
	updateAnimation();
}

void Player::updateAnimation()
{
}

void Player::walk(float dir, float sm)
{
	vel.x = walkSpd * dir * sm;
}

sf::Vector2f Player::getPos()
{
	return pos;
}