#pragma once

#include <SFML/Graphics.hpp>
#include "FrameContainer.h"
#include <iostream>

class AnimationContainer
{
public:
	AnimationContainer();
	~AnimationContainer();
	void copy(const AnimationContainer& orig);
	void nextFrame();
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
	void setPos(sf::Vector2f p);
	void addFrame(const FrameContainer& fc);
private:
	sf::Sprite sprite;
	std::vector<FrameContainer> frames;
	int currentFrame;
	int frameCount;
	int totalFrames;
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/