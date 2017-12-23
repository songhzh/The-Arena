#include "Hitbox.h"

Hitbox::Hitbox()
{
}

Hitbox::~Hitbox()
{
}

Hitbox* Hitbox::clone()
{
	return new Hitbox(*this);
}

void Hitbox::draw(sf::RenderWindow* w)
{
	box.setFillColor(sf::Color(255, 255, 255, 100));
	w->draw(box);
}

void Hitbox::update(Player* owner)
{
	box.setPosition(owner->getPos() + offset);
}

void Hitbox::onHit(Player* target)
{
}

void Hitbox::setPos(sf::Vector2f pos)
{
	box.setPosition(pos);
}

Hurtbox::Hurtbox(sf::RectangleShape b, sf::Vector2f ofs)
{
	box = b;
	offset = ofs;
}
/*
Hurtbox* Hurtbox::clone()
{
	return new Hurtbox(*this);
}

void Hurtbox::update(Player* owner)
{
	//std::cout << "hurtbox" << std::endl;
	box.setPosition(owner->getPos() + offset);
}
*/

Vishnu_punch::Vishnu_punch(sf::RectangleShape b, sf::Vector2f ofs)
{
	box = b;
	offset = ofs;
}

void Vishnu_punch::draw(sf::RenderWindow* w)
{
	box.setFillColor(sf::Color(255, 0, 0, 100));
	w->draw(box);
}

Vishnu_kick::Vishnu_kick(sf::RectangleShape b, sf::Vector2f ofs)
{
	box = b;
	offset = ofs;
}

void Vishnu_kick::draw(sf::RenderWindow* w)
{
	box.setFillColor(sf::Color(255, 0, 255, 100));
	w->draw(box);
}

Projectile* Projectile::clone()
{
	return new Projectile(*this);
}

void Projectile::update(Player* owner)
{
	//std::cout << "Projectile update" << std::endl;
}

void Projectile::onHit(Player* target)
{
}

void Projectile::dbTest()
{
	//std::cout << pos.x << std::endl;
}

void Projectile::inc()
{
	//pos.x++;
}