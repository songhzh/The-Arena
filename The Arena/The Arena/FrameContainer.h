#pragma once

#include <SFML/Graphics.hpp>
#include "Hitbox.h"

struct FrameContainer
{
	FrameContainer();
	FrameContainer(std::string loc, int hNum, int vNum, int hIdx, int vIdx);
	FrameContainer(const FrameContainer& orig);
	~FrameContainer();
	void addHitbox(Hitbox* h);

	sf::Texture texture;
	sf::Sprite frame;
	std::vector<Hitbox*> hitbox;
};

