#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class AnimationContainer
{
public:
	AnimationContainer();
	~AnimationContainer();
	void init(std::string loc, int duration, int vtn);
	void nextFrame();
	void setCurrentAnimation(int choice); // Choose animation, index starts at zero.
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
	void setPos(sf::Vector2f p);
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int currentFrame;

	int currentAnimation; // Chooses which animation is needed (vertical choice)
						  // 0 - idle, 1 - movement, 2 - etc...
	int verticalTextureNum; // How many total animations the texture has.
	int textureNum; // How many sprites are in the selected texture string.
	
	int animationDelay;
	const int ANIMATIONDELAY_MAX = 10;

	int textureWidth;
	int textureHeight;
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/