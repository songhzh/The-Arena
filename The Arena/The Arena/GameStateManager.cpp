#include "GameStateManager.h"

GameStateManager::GameStateManager(sf::RenderWindow* w) : window(w)
{
	playerList[InputManager::Role::PL].init(InputManager::Role::PL);
	//playerList[Player::Role::PR].init(Player::Role::PR);
	//playerList[P2].init(P2);
	paused = false;
}

GameStateManager::~GameStateManager()
{
}

void GameStateManager::update()
{
	if (!paused)
		playerList[InputManager::Role::PL].update();
	playerList[InputManager::Role::PL].draw(window);
}

void GameStateManager::keyPressed(sf::Keyboard::Key k)
{
	if (k == sf::Keyboard::W ||
		k == sf::Keyboard::S ||
		k == sf::Keyboard::A ||
		k == sf::Keyboard::D ||
		k == sf::Keyboard::C ||
		k == sf::Keyboard::V)
			playerList[InputManager::Role::PL].keyPressed();
	else if (
		k == sf::Keyboard::I ||
		k == sf::Keyboard::K ||
		k == sf::Keyboard::J ||
		k == sf::Keyboard::L ||
		k == sf::Keyboard::Period ||
		k == sf::Keyboard::Slash)
			playerList[InputManager::Role::PR].keyPressed();
}

void GameStateManager::setPause(bool s)
{
	paused = s;
}