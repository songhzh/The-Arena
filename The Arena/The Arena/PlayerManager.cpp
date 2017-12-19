#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player;
	//currentFrame = AnimationContainer();
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::init(Role r)
{
	player->init(r);
}

void PlayerManager::update(float df)
{
	player->update(df);
}