#pragma once

#include <SFML/Graphics.hpp>
#include "FrameContainer.h"
#include <iostream>

class AnimationContainer
{
public:
	enum HitboxType { NONE, FOLLOWER, VISHNU_PROJECTILE, VISHNU_GATE };

	AnimationContainer();
	~AnimationContainer();
	AnimationContainer* clone();
	void setOwner(Player* p);
	void setOffset(sf::Vector2f ofs);
	void setLoop(bool l);
	void setSpdMult(float sm);
	void setHitboxType(HitboxType h);
	void updatePos();
	AnimationContainer* resetPtr();
	void updateHitbox();
	void drawHitbox(sf::RenderWindow* w);
	bool nextFrame();
	bool canReset();
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
	void addFrame(FrameContainer* fc);
	float getSpdMult();
	int getCurrentFrame();
private:
	Player* owner;
	sf::Sprite sprite;
	std::vector<FrameContainer*> frames;
	sf::Vector2f pos;
	sf::Vector2f offset;
	HitboxType hbt;
	int currentFrame;
	int frameCount;
	int totalFrames;
	bool loop;
	float spdMult;
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/