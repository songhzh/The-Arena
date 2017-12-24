#include "PlayerManager.h"

PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
}

void PlayerManager::loadAnimations()
{
	anim::load_vishnu_projectile_ac(&player);
	anim::load_vishnu_idle_ac(&player);
	anim::load_vishnu_walk_ac(&player);
	anim::load_vishnu_punch_ac(&player);
	anim::load_vishnu_kick_ac(&player);
}

void PlayerManager::init(InputManager::Role r)
{
	comboCd = 0;
	loadAnimations();
	currentAnim = anim::vishnu_idle_ac.resetPtr();

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
	moveEffect();
	im.update();
	player.update(im.getDir(), currentAnim->getSpdMult());
	if (currentAnim->nextFrame() || im.getDir() && currentAnim == &anim::vishnu_idle_ac)
		currentAnim = anim::vishnu_walk_ac.resetPtr();
	else if (currentAnim == &anim::vishnu_walk_ac && !im.getDir())
		currentAnim = anim::vishnu_idle_ac.resetPtr();
	currentAnim->updatePos();
	for (auto it : projectile)
	{
		it->nextFrame();
		it->updatePos();
	}
}

void PlayerManager::moveEffect()
{
	if (currentAnim == &anim::vishnu_punch_ac)
	{
		switch (currentAnim->getCurrentFrame())
		{
		case 0:
			projectile.push_back(anim::vishnu_projectile_ac.clone());
			break;
		default:
			break;
		}
	}
}

void PlayerManager::draw(sf::RenderWindow* w)
{
	w->draw(currentAnim->getCurrentSprite());
	currentAnim->drawHitbox(w);
	for (auto it : projectile)
	{
		w->draw(it->getCurrentSprite());
		it->drawHitbox(w);
	}
}

void PlayerManager::keyPressed()
{
	if (!currentAnim->canReset()) return;
	im.getInput();
	switch (getMoveBsc())
	{
	case PUNCH:
		if (currentAnim != &anim::vishnu_punch_ac)
			currentAnim = anim::vishnu_punch_ac.resetPtr();
		break;
	case KICK:
		if (currentAnim != &anim::vishnu_kick_ac)
			currentAnim = anim::vishnu_kick_ac.resetPtr();
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
