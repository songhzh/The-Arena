#pragma once

#include <SFML/Graphics.hpp>
#include "FrameContainer.h"
#include <iostream>

class AnimationContainer
{
public:
	AnimationContainer();
	~AnimationContainer();
	void nextFrame();
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
	void setPos(sf::Vector2f p);
	void addFrame(FrameContainer fc, int amt);
private:
	sf::Sprite sprite;
	std::vector<FrameContainer> frames;
	int animationDelay;
	const int ANIMATIONDELAY_MAX = 10;
	int currentFrame;
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/