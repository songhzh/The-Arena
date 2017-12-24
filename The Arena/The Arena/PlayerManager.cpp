#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::loadAnimations()
{
	anim::load_vishnu_idle_ac(&player);
	anim::load_vishnu_walk_ac(&player);
	anim::load_vishnu_punch_ac(&player);
	anim::load_vishnu_kick_ac(&player);
}

void PlayerManager::init(InputManager::Role r)
{
	comboCd = 0;
	loadAnimations();
	currentFrame = anim::vishnu_idle_ac.resetPtr();

	player.init(sf::Vector2f(100, 170));
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
	player.update(im.getDir(), currentFrame->getSpdMult());
	if (currentFrame->nextFrame() || im.getDir() && currentFrame == &anim::vishnu_idle_ac)
		currentFrame = anim::vishnu_walk_ac.resetPtr();
	if (currentFrame == &anim::vishnu_walk_ac && !im.getDir())
		currentFrame = anim::vishnu_idle_ac.resetPtr();

	currentFrame->setPos(player.getPos());
}

void PlayerManager::draw(sf::RenderWindow* w)
{
	w->draw(currentFrame->getCurrentSprite());
	currentFrame->drawHitbox(w);
}

void PlayerManager::keyPressed()
{
	im.getInput();
	if (!currentFrame->canReset()) return;
	switch (getMoveBsc())
	{
	case WALK:
		if (im.getDir())
			currentFrame = anim::vishnu_walk_ac.resetPtr();
		break;
	case PUNCH:
		currentFrame = anim::vishnu_punch_ac.resetPtr();
		break;
	case KICK:
		currentFrame = anim::vishnu_kick_ac.resetPtr();
		break;
	case JUMP:
		player.jump();
		break;
	default:
		break;
	}
}

PlayerManager::MoveBsc PlayerManager::getMoveBsc()
{
	if (im.hasCommandBsc(b1_m, 0))
		return PUNCH;
	else if (im.hasCommandBsc(b2_m, 0))
		return KICK;
	else if (im.hasCommandBsc(up_m, 0))
		return JUMP;
	else if (im.hasCommandBsc(fwd_m | back_m, 0))
		return WALK;
	return NOBSC;
}

PlayerManager::MoveAdv PlayerManager::getMoveAdv()
{
	if (im.hasCommandAdv(down_m, 2) && im.hasCommandAdv(back_m, 1) && im.hasCommandAdv(back_m | down_m, 0))
		return BACKSTEP;
	else if (im.hasCommandAdv(fwd_m, 3) && im.hasCommandAdv(fwd_m, 2) && im.hasCommandAdv(fwd_m, 1) && im.hasCommandAdv(fwd_m | b1_m, 0))
		return TRIPLE;
	return NOADV;
}
