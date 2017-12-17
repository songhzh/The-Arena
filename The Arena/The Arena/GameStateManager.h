#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerManager.h"

class GameStateManager
{
	enum { LEFT, RIGHT };

public:
	GameStateManager(sf::RenderWindow* w);
	~GameStateManager();
	void update(float dt);
private:
	sf::RenderWindow* window;
	PlayerManager playerList[2];
};

