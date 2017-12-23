#pragma once

#include <SFML/Graphics.hpp>
#include "Hitbox.h"

struct FrameContainer
{
	FrameContainer();
	FrameContainer(std::string loc, int hNum, int vNum, int hIdx, int vIdx, int d, bool cr);
	FrameContainer(const FrameContainer& orig);
	~FrameContainer();
	void addHitbox(Hitbox* h);
	void updateHitbox(Player* owner);
	void drawHitbox(sf::RenderWindow* w);

	sf::Texture texture;
	sf::Sprite frame;
	std::vector<Hitbox*> hitbox;
	int dispLen;
	bool canReset; // if animation-cancelling allowed
};

