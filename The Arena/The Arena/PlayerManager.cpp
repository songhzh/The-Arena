#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
	player = new Player;
	im = new InputManager;
	sf::Texture r;
	currentFrame.init(r, 1);
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
	im->update(df);
	player->update(df, im->getDir());
	//getCombo();
}

void PlayerManager::draw(sf::RenderWindow* w)
{
	sf::RectangleShape rect(sf::Vector2f(160, 380));
	rect.setPosition(player->getPos().x, player->getPos().y);
	w->draw(rect);
}

void PlayerManager::keyPressed()
{
	im->getInput();
}

int PlayerManager::getCombo()
{
	if (im->hasCommand(im->up_m | im->left_m))
	{
		std::cout << "TL" << std::endl;
	}
	return 1;
}