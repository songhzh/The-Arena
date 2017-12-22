#include "FrameContainer.h"

FrameContainer::FrameContainer()
{
}

FrameContainer::FrameContainer(std::string loc, int hNum, int vNum, int hIdx, int vIdx)
{
	texture.loadFromFile(loc);
	frame.setTexture(texture);
	int textureWidth = texture.getSize().x / hNum;
	int textureHeight = texture.getSize().y / vNum;
	sf::IntRect textureRect(textureWidth * hIdx, textureHeight * vIdx, textureWidth, textureHeight);
	frame.setTextureRect(textureRect);
}

FrameContainer::FrameContainer(const FrameContainer& orig)
{
	texture = orig.texture;
	frame = orig.frame;
	for (auto it : orig.hitbox)
	{
		Hitbox* hb = new Hitbox;
		*hb = *it;
		hitbox.push_back(hb);
	}
}

FrameContainer::~FrameContainer()
{
	for (Hitbox* it : hitbox)
		delete it;
	hitbox.clear();
}

void FrameContainer::addHitbox(Hitbox* h)
{
	hitbox.push_back(h);
}

