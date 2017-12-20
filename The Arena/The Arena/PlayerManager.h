#pragma once

#include <SFML/Graphics.hpp>

#include "Animations.h"
#include "InputManager.h"
#include "Hitbox.h"
#include "Player.h"

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();
	void init(InputManager::Role r);
	void update();
	void draw(sf::RenderWindow* w);
	void keyPressed();
private:
	bool getCombo();

	Player player;
	InputManager im;
	AnimationContainer currentFrame;
	std::vector<Hitbox*> hurtbox;
	std::vector<Hitbox*> follower;
	std::vector<Hitbox*> projectile;
	int comboCd;

	const int up_m = im.up_m;
	const int down_m = im.down_m;
	int fwd_m;
	int back_m;
	const int b1_m = im.b1_m;
	const int b2_m = im.b2_m;
};

