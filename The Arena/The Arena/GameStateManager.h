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
	void setPause(bool s);
private:
	bool paused;
	sf::RenderWindow* window;
	PlayerManager playerList[2];
};

