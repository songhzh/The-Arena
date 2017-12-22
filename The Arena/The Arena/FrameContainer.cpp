#include "FrameContainer.h"

FrameContainer::FrameContainer()
{
}

FrameContainer::FrameContainer(std::string loc, int hNum, int vNum, int hIdx, int vIdx, int d, bool cr) : dispLen(d), canReset(cr)
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
	hitbox = orig.hitbox;
	dispLen = orig.dispLen;
	canReset = orig.canReset;

	for (auto& it : orig.hitbox)
	{
		hitbox.push_back(it->clone());
	}
}


FrameContainer::~FrameContainer()
{
	/*
	for (Hitbox* it : hitbox)
		//std::cout << "deleting" << std::endl;
		delete it;
	hitbox.clear();
	*/
}

void FrameContainer::addHitbox(Hitbox h)
{
	Hitbox* hb = new Hitbox;
	*hb = h;
	hitbox.push_back(hb);
}

