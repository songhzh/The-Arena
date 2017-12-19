#include "Player.h"

Player::Player()
{
	pos = { 100, 100 };
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

void Player::move()
{
	/*
	bool left = sf::Keyboard::isKeyPressed(input[LEFT]);
	bool right = sf::Keyboard::isKeyPressed(input[RIGHT]);

	if (left ^ right)
	{
		vel.x = left ? -walkSpd : walkSpd;
	}
	*/
}

void Player::update(float df)
{
	move();
	pos += vel * df;
	vel += acc * df;

	updateAnimation(df);
}

void Player::updateAnimation(float df)
{
}