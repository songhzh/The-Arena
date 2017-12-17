#include "GameStateManager.h"

GameStateManager::GameStateManager(sf::RenderWindow* w) : window(w)
{
	playerList[LEFT].init(LEFT);
	//playerList[P2].init(P2);
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::update(float df)
{
	playerList[LEFT].update(df);
}