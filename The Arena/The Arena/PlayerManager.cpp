#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::loadAnimations()
{
	anim::load_vishnu_idle_ac();
	anim::load_vishnu_punch_ac();
}

void PlayerManager::init(InputManager::Role r)
{
	comboCd = 0;
	loadAnimations();
	currentFrame = anim::vishnu_punch_ac;
	//currentFrame.copy(anim::vishnu_idle_ac);

	player.init(r);
	im.init(r);

	switch (r)
	{
	case InputManager::PL:
		fwd_m = im.right_m;
		back_m = im.left_m;
		break;
	case InputManager::PR:
		fwd_m = im.left_m;
		back_m = im.right_m;
		break;
	default:
		break;
	}
}

void PlayerManager::update()
{
	im.update();
	player.update(im.getDir());
	currentFrame.nextFrame();
	currentFrame.setPos(player.getPos());
}

void PlayerManager::draw(sf::RenderWindow* w)
{
	//sf::RectangleShape rect(sf::Vector2f(160, 380));
	//rect.setPosition(player.getPos().x, player.getPos().y);
	w->draw(currentFrame.getCurrentSprite());
}

void PlayerManager::keyPressed()
{
	im.getInput();
	getCombo();
}

bool PlayerManager::getCombo()
{
	if (im.hasCommand(down_m, 2) && im.hasCommand(back_m, 1) && im.hasCommand(back_m | down_m, 0))
	{
		std::cout << "Backstep" << std::endl;
		return true;
	}
	if (im.hasCommand(fwd_m, 3) && im.hasCommand(fwd_m, 2) && im.hasCommand(fwd_m, 1) && im.hasCommand(fwd_m | b1_m, 0))
	{
		std::cout << "Triple" << std::endl;
		return true;
	}
	return false;
}
