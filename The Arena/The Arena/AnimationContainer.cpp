#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	animationDelay = ANIMATIONDELAY_MAX;
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::nextFrame()
{
	currentFrame = (currentFrame + 1) % frames.size();
	sprite = frames[currentFrame].frame;
}

sf::Sprite AnimationContainer::getCurrentSprite()
{
	return sprite;
}

void AnimationContainer::setPos(sf::Vector2f p)
{
	sprite.setPosition(p);
}

void AnimationContainer::addFrame(FrameContainer fc, int amt)
{
	for (int i = 0; i < amt; i++)
	{
		frames.push_back(fc);
	}
}