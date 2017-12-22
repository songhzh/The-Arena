#include "Hitbox.h"

Hitbox::Hitbox()
{
	//std::cout << "Hitbox created" << std::endl;
	offset = { 0, 0 };
	pos = { 0, 0 };
	vel = { 0 ,0 };
	acc = { 0, 0 };
}

Hitbox::~Hitbox()
{
}

Hitbox* Hitbox::clone()
{
	return new Hitbox(*this);
}

void Hitbox::update(Player* owner)
{
	std::cout << "Hitbox update" << std::endl;
}

void Hitbox::onHit(Player* target)
{
}

Hurtbox* Hurtbox::clone()
{
	return new Hurtbox(*this);
}

void Hurtbox::init(sf::Vector2f ofs)
{
	offset = ofs;
}

void Hurtbox::update(Player* owner)
{
	pos = owner->getPos() + offset;
}

Projectile* Projectile::clone()
{
	return new Projectile(*this);
}

void Projectile::update(Player* owner)
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