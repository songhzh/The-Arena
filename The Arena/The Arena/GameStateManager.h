#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"

class GameStateManager
{
	enum { LEFT, RIGHT };

public:
	GameStateManager(sf::RenderWindow* w);
	~GameStateManager();
	void update(float dt);
private:
	sf::RenderWindow* window;
	Player playerList[2];
};

