#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::init(std::string loc, int duration, int vtn)
{
	texture.loadFromFile(loc);
	sprite.setTexture(texture);
	textureNum = duration;

	verticalTextureNum = vtn;
	textureWidth = texture.getSize().x / textureNum;
	textureHeight = texture.getSize().y / verticalTextureNum;
}

void AnimationContainer::setCurrentAnimation(int choice)
{
	currentAnimation = choice;
}

void AnimationContainer::nextFrame()
{
	/*
	currentFrame += df;

	if (currentFrame > textureNum - 1)
	{
		currentFrame -= textureNum - 1;
	}
	*/
	currentFrame = (currentFrame + 1) % 2;

	sf::IntRect textureRect(textureWidth * currentFrame, 0, textureWidth, textureHeight);

	//sf::RectangleShape rectangle(size);
	sprite.setTextureRect(textureRect);
}

sf::Sprite AnimationContainer::getCurrentSprite() {
	return sprite;
}