#pragma once

#include <SFML/Graphics.hpp>

#include "AnimationContainer.h"
#include "InputManager.h"
#include "Hitbox.h"
#include "Player.h"

class PlayerManager
{
public:
	enum Role { LEFT, RIGHT, ERROR };

	PlayerManager();
	~PlayerManager();
	void init(Role r);
	void update();
	void draw(sf::RenderWindow* w);
	void keyPressed();
private:
	int getCombo();

	Player player;
	InputManager im;
	AnimationContainer currentFrame;
	std::vector<Hitbox*> hurtbox;
	std::vector<Hitbox*> follower;
	std::vector<Hitbox*> projectile;
};

