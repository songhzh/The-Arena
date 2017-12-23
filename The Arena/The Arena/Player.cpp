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
	acc = { 0, 7 };
}

void Player::update(int dir, float sm)
{
	walk((float) dir, sm);

	vel += acc;
	pos += vel;
	if (pos.y > ground)
		pos.y = ground;

	updateAnimation();
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
	if (pos.y == ground)
		vel.y = jumpSpd;
}

sf::Vector2f Player::getPos()
{
	return pos;
}