#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	frameCount = 0;
	totalFrames = 0;
	loop = false;
	frames.reserve(1);
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::copy(const AnimationContainer& orig)
{
	*this = orig;
	sprite = frames[0].frame;
}

void AnimationContainer::setLoop(bool l)
{
	loop = l;
}

bool AnimationContainer::nextFrame()
{
	if (frameCount > frames[currentFrame].dispLen)
	{
		frameCount = 0;
		currentFrame = (currentFrame + 1) % frames.size();

		std::cout << currentFrame << std::endl;
		if (!loop && currentFrame == 0)
			return true;

		sprite = frames[currentFrame].frame;
	}
	frameCount++;
	return false;
}

bool AnimationContainer::canReset()
{
	return frames[currentFrame].canReset;
}

sf::Sprite AnimationContainer::getCurrentSprite()
{
	return sprite;
}

void AnimationContainer::setPos(sf::Vector2f p)
{
	sprite.setPosition(p);
}

void AnimationContainer::addFrame(const FrameContainer& fc)
{
	totalFrames += fc.dispLen;
	frames.push_back(fc);
	//sprite = frames[0].frame;
}