#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::init(int role)
{
	switch (role)
	{
	case 0:
		input[UP]	 = sf::Keyboard::W;
		input[DOWN]  = sf::Keyboard::S;
		input[LEFT]  = sf::Keyboard::A;
		input[RIGHT] = sf::Keyboard::D;
		input[B1]	 = sf::Keyboard::C;
		input[B2]	 = sf::Keyboard::V;
		break;
	case 1:
		input[UP]	 = sf::Keyboard::I;
		input[DOWN]  = sf::Keyboard::K;
		input[LEFT]  = sf::Keyboard::J;
		input[RIGHT] = sf::Keyboard::L;
		input[B1]	 = sf::Keyboard::Period;
		input[B2]	 = sf::Keyboard::Slash;
		break;
	default:
		break;
	}

	currentAnimationFrame = STILL_1;
	framesToUpdate = 30;
}

void Player::move()
{
	bool left = sf::Keyboard::isKeyPressed(input[LEFT]);
	bool right = sf::Keyboard::isKeyPressed(input[RIGHT]);

	if (left ^ right)
	{
		vel.x = left ? -walkSpd : walkSpd;
	}
}

void Player::updateAll(float df)
{
	move();
	pos += vel * df;
	vel += acc * df;

	updateAnimation(df);
}

void Player::updateHitboxes(float df)
{
	for (auto& it : hurt)
	{
		it.update(df);
	}

	for (auto& it : hit)
	{
		it.update(df);
	}
}

void Player::updateAnimation(float df)
{
	if (framesToUpdate > 0) return;

	switch (currentAnimationFrame)
	{
	case STILL_1:
		currentAnimationFrame = STILL_2;
		break;
	case STILL_2:
		currentAnimationFrame = STILL_1;
		break;
	default:
		break;
	}

	framesToUpdate -= df;
}