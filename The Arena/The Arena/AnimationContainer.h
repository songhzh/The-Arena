#pragma once

#include <SFML/Graphics.hpp>
#include "FrameContainer.h"
#include <iostream>

class AnimationContainer
{
public:
	AnimationContainer();
	~AnimationContainer();
	void setOwner(Player* p);
	AnimationContainer* resetPtr();
	void updateHitbox();
	void drawHitbox(sf::RenderWindow* w);
	void setLoop(bool l);
	bool nextFrame();
	bool canReset();
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
	void setPos(sf::Vector2f pos);
	void addFrame(FrameContainer* fc);
	void setSpdMult(float sm);
	float getSpdMult();
private:
	Player* owner;
	sf::Sprite sprite;
	std::vector<FrameContainer*> frames;
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