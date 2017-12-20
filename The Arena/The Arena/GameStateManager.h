#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerManager.h"

class GameStateManager
{
public:
	GameStateManager(sf::RenderWindow* w);
	~GameStateManager();
	void update();
	void keyPressed(sf::Keyboard::Key k);
private:
	sf::RenderWindow* window;
	PlayerManager playerList[2];
};

