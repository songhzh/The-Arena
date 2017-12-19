#include "GameStateManager.h"

GameStateManager::GameStateManager(sf::RenderWindow* w) : window(w)
{
	playerList[PlayerManager::Role::LEFT].init(PlayerManager::Role::LEFT);
	//playerList[Player::Role::RIGHT].init(Player::Role::RIGHT);
	//playerList[P2].init(P2);
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::update(float df)
{
	playerList[PlayerManager::Role::LEFT].update(df);
}

void GameStateManager::keyPressed(sf::Keyboard::Key k)
{
	
}

PlayerManager::Role GameStateManager::getKeyPlayer(sf::Keyboard::Key k)
{
	if (k == sf::Keyboard::W ||
		k == sf::Keyboard::S ||
		k == sf::Keyboard::A ||
		k == sf::Keyboard::D ||
		k == sf::Keyboard::C ||
		k == sf::Keyboard::V)
		return PlayerManager::Role::LEFT;
	else if (k == sf::Keyboard::I ||
		k == sf::Keyboard::K ||
		k == sf::Keyboard::J ||
		k == sf::Keyboard::L ||
		k == sf::Keyboard::Period ||
		k == sf::Keyboard::Slash)
		return PlayerManager::Role::RIGHT;
	else
		return PlayerManager::Role::ERROR;
}