#include "Hitbox.h"

Hitbox::Hitbox()
{
	std::cout << "Hitbox created" << std::endl;
	offset = { 0, 0 };
	pos = { 600, 100 };
	vel = { 0 ,0 };
	acc = { 0, 0 };
}

Hitbox::~Hitbox()
{
}

void Hitbox::update()
{
	std::cout << "Hitbox update" << std::endl;
}

void Hitbox::onHit(Player* target)
{
}

void Projectile::update()
{
	std::cout << "Projectile update" << std::endl;
}

void Projectile::onHit(Player* target)
{
}

void Projectile::dbTest()
{
	std::cout << pos.x << std::endl;
}

void Projectile::inc()
{
	pos.x++;
}