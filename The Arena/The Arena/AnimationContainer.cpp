#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
	currentFrame = 0;
	frameCount = 0;
	totalFrames = 0;
	spdMult = 1.0f;
	hbt = FOLLOWER;
	offset = sf::Vector2f(0, 0);
	loop = true;
}

AnimationContainer::~AnimationContainer()
{
}

AnimationContainer* AnimationContainer::clone()
{
	AnimationContainer* clone = new AnimationContainer;
	clone->owner = this->owner;
	clone->sprite = this->sprite;
	for (auto it : frames)
		clone->frames.push_back(it->clone());
	clone->pos = this->owner->getPos() + this->offset;
	clone->offset = this->offset;
	clone->hbt = this->hbt;
	clone->currentFrame = this->currentFrame;
	clone ->frameCount = this->frameCount;
	clone->totalFrames = this->totalFrames;
	clone->loop = this->loop;
	clone->spdMult = this->spdMult;
	return clone;
}

void AnimationContainer::setOwner(Player* p)
{
	owner = p;
}

void AnimationContainer::setOffset(sf::Vector2f ofs)
{
	offset = ofs;
}

void AnimationContainer::setLoop(bool l)
{
	loop = l;
}

void AnimationContainer::setSpdMult(float sm)
{
	spdMult = sm;
}

void AnimationContainer::setHitboxType(HitboxType h)
{
	hbt = h;
}

void AnimationContainer::updatePos()
{
	switch (hbt)
	{
	case FOLLOWER:
		pos = owner->getPos();
		break;
	case VISHNU_PROJECTILE:
		pos.x += 10;
		break;
	default:
		break;
	}
	sprite.setPosition(pos);
	updateHitbox();
}

AnimationContainer* AnimationContainer::resetPtr()
{
	currentFrame = 0;
	sprite = frames[currentFrame]->frame;
	updateHitbox();
	return this;
}

void AnimationContainer::updateHitbox()
{
	frames[currentFrame]->updateHitbox(owner->getPos());
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

void AnimationContainer::addFrame(FrameContainer* fc)
{
	totalFrames += fc->dispLen;
	frames.push_back(fc);
	sprite = frames[0]->frame;
}

float AnimationContainer::getSpdMult()
{
	return spdMult;
}

int AnimationContainer::getCurrentFrame()
{
	return frameCount == 0 ? currentFrame : -1;
}