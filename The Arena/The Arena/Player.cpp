#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(sf::Vector2f p)
{	
	pos = p;
	ground = pos.y;
	vel = { 0, 0 };
	acc = { 0, 3 };
	ultCharge = 0;
}

void Player::update(int dir, float sm, int dlock)
{
	walk(dlock == 0 ? dir : dlock, sm);
	vel += acc;
	pos += vel;
	if (pos.y > ground)
		pos.y = ground;
	updateAnimation();
	if (ultCharge < ultCharge_max)
		ultCharge++;
}

void Player::updateAnimation()
{
}

void Player::walk(float dir, float sm)
{
	vel.x = walkSpd * dir * sm;
}

void Player::jump()
{
	vel.y = jumpSpd;
}

bool Player::onGround()
{
	return pos.y == ground;
}

sf::Vector2f Player::getPos()
{
	return pos;
}

bool Player::useUlt()
{
	if (ultCharge == ultCharge_max)
	{
		ultCharge = 0;
		return true;
	}
	return false;
}