#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player;
	im = new InputManager;
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::init(Role r)
{
	player->init(r);
	im->init(r);
}

void PlayerManager::update(float df)
{
	player->update(df);
	im->update(df);
	getInput();
}

void PlayerManager::keyPressed()
{
	im->getInput();
}

int PlayerManager::getInput()
{
	if (im->hasCommand(im->up_m | im->left_m))
	{
		std::cout << "TL" << std::endl;
	}
	return 1;
}