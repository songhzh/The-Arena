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


FrameContainer* FrameContainer::clone()
{
	FrameContainer* clone = new FrameContainer;
	clone->texture = this->texture;
	clone->frame = this->frame;
	for (auto it : this->hitbox)
		clone->hitbox.push_back(it->clone());
	clone->dispLen = this->dispLen;
	clone->canReset = this->canReset;
	return clone;
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

void FrameContainer::addHitbox(Hitbox* h)
{
	hitbox.push_back(h);
}

void FrameContainer::updateHitbox(sf::Vector2f pos)
{
	for (auto it : hitbox)
		it->updatePos(pos);
}

void FrameContainer::drawHitbox(sf::RenderWindow* w)
{
	for (auto it : hitbox)
	{
		it->draw(w);
	}
		
}



