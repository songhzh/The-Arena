#include "Player.h"

Player::Player()
{
	pos = { 100, 350 };
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

void Player::update(float df, int dir)
{
	walk(dir);
	vel += acc * df;
	pos += vel * df;
	
	updateAnimation(df);
}

void Player::updateAnimation(float df)
{
}

void Player::walk(int dir)
{
	pos.x += walkSpd * dir;
}

sf::Vector2f Player::getPos()
{
	return pos;
}