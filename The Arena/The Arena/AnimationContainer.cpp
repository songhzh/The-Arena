#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	animationDelay = ANIMATIONDELAY_MAX;
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
	if (animationDelay == 0)
	{
		currentFrame = (currentFrame + 1) % textureNum;
		animationDelay = ANIMATIONDELAY_MAX;
	}
	else
	{
		animationDelay--;
	}

	//std::cout << currentFrame << std::endl;
	sf::IntRect textureRect(textureWidth * currentFrame, 0, textureWidth, textureHeight);
	sprite.setTextureRect(textureRect);
}

sf::Sprite AnimationContainer::getCurrentSprite()
{
	return sprite;
}

void AnimationContainer::setPos(sf::Vector2f p)
{
	sprite.setPosition(p);
}