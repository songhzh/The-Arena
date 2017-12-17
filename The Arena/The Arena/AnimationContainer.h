#pragma once

#include <SFML/Graphics.hpp>

struct AnimationContainer
{
	sf::Texture texture;
	sf::Sprite sprite;

	float framesToNext;
};

//extern AnimationContainer still_1(Player* p);