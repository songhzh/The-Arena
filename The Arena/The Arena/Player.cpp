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
	switch (r)
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