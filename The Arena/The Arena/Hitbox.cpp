#include "Hitbox.h"

Hitbox::Hitbox(Player* p, hitboxType h) : owner(p), hbt(h)
{
	std::cout << "Hitbox created" << std::endl;
	pos = { 600, 100 };
	vel = { 0 ,0 };
	acc = { 0, 0 };
}

Hitbox::~Hitbox()
{
}

void Hitbox::update()
{
	switch (hbt)
	{
	case PROJECTILE:
		std::cout << "Projectile update" << std::endl;
		break;
	case FOLLOWER:
		std::cout << "Follower update" << std::endl;
		break;
	default:
		break;
	}
}

void Hitbox::onHit(Player* target)
{
	switch (hbt)
	{
	case PROJECTILE:
		std::cout << "Projectile hit" << std::endl;
		break;
	case FOLLOWER:
		std::cout << "Follower hit" << std::endl;
		break;
	default:
		break;
	}
}