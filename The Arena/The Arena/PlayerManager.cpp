#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player;
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::init(int role)
{
	player->init(role);
}

void PlayerManager::update(float df)
{
	player->update(df);
}