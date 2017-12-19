#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>

class AnimationContainer
{
	sf::Texture texture;
	sf::Sprite sprite;

	int currentAnimation; // Chooses which animation is needed (vertical choice)
	// 0 - idle, 1 - movement, 2 - etc...
	
	int verticalTextureNum; // How many total animations the texture has.
	int textureNum; // How many sprites are in the selected texture string.
	
	double textureInterval; // Calculated value needed for "for loop"
	double verticalTextureInterval; // Calculated value needed for "for loop". This technically should be a constant but is still calculated just incase.

	sf::IntRect rectangle = sf::IntRect(); // Needed to cycle through sprites

	public:
		AnimationContainer(sf::Texture texture);
		void getFrame();

		void animationIdle(int textureNum1); // void Animation... (); this method can be removed if all sprites are same width.

		void setCurrentAnimation(int choice); // Choose animation, index starts at zero.

		sf::Sprite getCurrentSprite(); // This is what you want to show on screen.
};

//extern AnimationContainer still_1(Player* p);

/* 

	How to test this:
	Give constructor the texture.
	setCurrentAnimation(0);
	animationIdle(2); since the idle animation has 2 frames.
	then use getCurrentSprite(); to display current frame.

*/