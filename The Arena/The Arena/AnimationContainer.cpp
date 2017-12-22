#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	frameCount = 0;
	totalFrames = 0;
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::copy(const AnimationContainer& orig)
{
	currentFrame = 0;
	sprite = orig.sprite;
	
	for (auto& it : orig.frames)
	{
		FrameContainer fc(it);
		frames.push_back(fc);
		std::cout << frames.back().dispLen << std::endl;
	}
}

void AnimationContainer::nextFrame()
{
	std::cout << frames[currentFrame].dispLen << std::endl;
	std::cout << frameCount << std::endl;
	std::cout << std::endl;
	if (frameCount > frames[currentFrame].dispLen)
	{
		frameCount = 0;
		currentFrame = (currentFrame + 1) % frames.size();
		sprite = frames[currentFrame].frame;
	}
		
	frameCount++;
	
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
	//std::cout << frames.back().dispLen << std::endl;
	//sprite = frames[0].frame;
}