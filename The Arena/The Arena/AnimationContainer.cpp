#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::copy(const AnimationContainer& orig)
{
	currentFrame = 0;
	sprite = orig.sprite;
	
	for (auto it : orig.frames)
	{
		FrameContainer fc(it);
		frames.push_back(fc);
	}
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
	sprite = frames[0].frame;
}