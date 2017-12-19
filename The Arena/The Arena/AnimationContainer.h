#pragma once

#include <SFML/Graphics.hpp>

class AnimationContainer
{
public:
	AnimationContainer();
	~AnimationContainer();
	void init(sf::Texture texture1, int duration);
	void getFrame();
	void setCurrentAnimation(int choice); // Choose animation, index starts at zero.
	sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
private:
	sf::Texture texture;
	sf::Sprite sprite;

	int currentAnimation; // Chooses which animation is needed (vertical choice)
						  // 0 - idle, 1 - movement, 2 - etc...
	int verticalTextureNum; // How many total animations the texture has.
	int textureNum; // How many sprites are in the selected texture string.
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/