#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationContainer.h"
#include "Hitbox.h"
#include "Player.h"

class PlayerManager
{
	enum { UP, DOWN, LEFT, RIGHT, B1, B2 };

public:
	PlayerManager();
	~PlayerManager();
	void init(int role);
	void update(float df);
private:
	Player* player;
	AnimationContainer currentFrame;
	std::vector<Hitbox*> hurtbox;
	std::vector<Hitbox*> follower;
	std::vector<Hitbox*> projectile;
};

