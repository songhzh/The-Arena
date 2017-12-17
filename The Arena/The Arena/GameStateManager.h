#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow* w);
	~GameStateManager();
private:
	sf::RenderWindow* window;
};

