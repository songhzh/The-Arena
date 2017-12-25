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
	anim::load_vishnu_gate_ac(&player);
	anim::load_vishnu_idle_ac(&player);
	anim::load_vishnu_walk_ac(&player);
	anim::load_vishnu_jump_ac(&player);
	anim::load_vishnu_crouch_ac(&player);
	anim::load_vishnu_punch_ac(&player);
	anim::load_vishnu_kick_ac(&player);
	anim::load_vishnu_backstep_ac(&player);
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

bool rmFromLayer(AnimationContainer* acp)
{
	if (acp->nextFrame())
		return true;
	else {
		acp->updatePos();
		return false;
	}
}

void PlayerManager::update()
{
	moveEffect();
	im.update();
	player.update(im.getDir(), currentAnim->getSpdMult(), fwd_m == im.right_m ? currentAnim->getDirLock() : -currentAnim->getDirLock());
	checkAnim();
	currentAnim->updatePos();
	layer_bck.erase(std::remove_if(layer_bck.begin(), layer_bck.end(), rmFromLayer), layer_bck.end());
	layer_fnt.erase(std::remove_if(layer_fnt.begin(), layer_fnt.end(), rmFromLayer), layer_fnt.end());
}

void PlayerManager::checkAnim()
{
	if (currentAnim->nextFrame() || !im.getDir() && currentAnim == &anim::vishnu_walk_ac
		|| player.onGround() && currentAnim == &anim::vishnu_jump_ac || !im.getCrouch() && currentAnim == &anim::vishnu_crouch_ac)
		currentAnim = anim::vishnu_idle_ac.resetPtr();
		
	if (currentAnim == &anim::vishnu_idle_ac)
		if (im.getDir() ^ im.getCrouch())
			currentAnim = im.getDir() ? anim::vishnu_walk_ac.resetPtr() : anim::vishnu_crouch_ac.resetPtr();
}

void PlayerManager::moveEffect()
{
	if (currentAnim == &anim::vishnu_punch_ac)
	{
		switch (currentAnim->getCurrentFrame())
		{
		case 0:
			//layer_bck.push_back(anim::vishnu_gate_ac.clone());
			//layer_fnt.push_back(anim::vishnu_projectile_ac.clone());
			break;
		default:
			break;
		}
	}
}

void PlayerManager::draw(sf::RenderWindow* w)
{
	for (auto it : layer_bck)
	{
		w->draw(it->getCurrentSprite());
		it->drawHitbox(w);
	}

	w->draw(currentAnim->getCurrentSprite());
	currentAnim->drawHitbox(w);

	for (auto it : layer_fnt)
	{
		w->draw(it->getCurrentSprite());
		it->drawHitbox(w);
	}
}

void PlayerManager::keyPressed()
{
	im.getInput();
	if (!currentAnim->canReset() || !player.onGround()) return;
	
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
		currentAnim = anim::vishnu_jump_ac.resetPtr();
		break;
	case CROUCH:
		if (currentAnim != &anim::vishnu_crouch_ac)
			currentAnim = anim::vishnu_crouch_ac.resetPtr();
		break;
	case WALK:
		if (currentAnim != &anim::vishnu_walk_ac)
			currentAnim = anim::vishnu_walk_ac.resetPtr();
		break;
	default:
		break;
	}
	switch (getMoveAdv())
	{
	case BACKSTEP:
		if (currentAnim != &anim::vishnu_backstep_ac)
			currentAnim = anim::vishnu_backstep_ac.resetPtr();
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
	else if (im.hasCommandBsc(down_m, 0))
		return CROUCH;
	else if (im.hasCommandBsc(back_m | fwd_m, 0))
		return WALK;
	return NOBSC;
}

PlayerManager::MoveAdv PlayerManager::getMoveAdv()
{
	if (im.hasCommandAdv(down_m, 1) && im.hasCommandAdv(back_m | down_m, 0))
		return BACKSTEP;
	else if (im.hasCommandAdv(fwd_m, 3) && im.hasCommandAdv(fwd_m, 2) && im.hasCommandAdv(fwd_m, 1) && im.hasCommandAdv(fwd_m | b1_m, 0))
		return TRIPLE;
	return NOADV;
}
