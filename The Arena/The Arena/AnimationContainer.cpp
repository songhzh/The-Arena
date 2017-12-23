#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	frameCount = 0;
	totalFrames = 0;
	loop = false;
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::setOwner(Player* p)
{
	owner = p;
}


AnimationContainer* AnimationContainer::resetPtr()
{
	currentFrame = 0;
	sprite = frames[currentFrame]->frame;
	updateHitbox();
	return this;
}

void AnimationContainer::setLoop(bool l)
{
	loop = l;
}

void AnimationContainer::updateHitbox()
{
	frames[currentFrame]->updateHitbox(owner);
}

void AnimationContainer::drawHitbox(sf::RenderWindow* w)
{
	frames[currentFrame]->drawHitbox(w);
}

bool AnimationContainer::nextFrame()
{
	if (frameCount > frames[currentFrame]->dispLen)
	{
		frameCount = 0;
		currentFrame = (currentFrame + 1) % frames.size();

		//std::cout << currentFrame << std::endl;
		if (!loop && currentFrame == 0)
			return true;

		sprite = frames[currentFrame]->frame;
		updateHitbox();
	}
	frameCount++;
	return false;
}

bool AnimationContainer::canReset()
{
	return frames[currentFrame]->canReset;
}

sf::Sprite AnimationContainer::getCurrentSprite()
{
	return sprite;
}

void AnimationContainer::setPos(sf::Vector2f p)
{
	sprite.setPosition(p);
	updateHitbox();
}

void AnimationContainer::addFrame(FrameContainer* fc)
{
	totalFrames += fc->dispLen;
	frames.push_back(fc);
	sprite = frames[0]->frame;
}

void AnimationContainer::setSpdMult(float sm)
{
	spdMult = sm;
}
float AnimationContainer::getSpdMult()
{
	return spdMult;
}