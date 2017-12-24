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

void Hitbox::updatePos(sf::Vector2f pos)
{
	box.setPosition(pos + offset);
}

void Hitbox::onHit(Player* target)
{
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

Vishnu_projectile::Vishnu_projectile(sf::RectangleShape b, sf::Vector2f ofs)
{
	box = b;
	offset = ofs;
}

Vishnu_projectile* Vishnu_projectile::clone()
{
	return new Vishnu_projectile(*this);
}

void Vishnu_projectile::onHit(Player* target)
{
}

void Vishnu_projectile::draw(sf::RenderWindow* w)
{
	box.setFillColor(sf::Color(0, 255, 255, 100));
	w->draw(box);
}