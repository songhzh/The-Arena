#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

class InputManager
{
public:
	enum Control { UP, DOWN, LEFT, RIGHT, B1, B2, ERROR };

	int up_m	= 1 << UP;
	int down_m	= 1 << DOWN;
	int left_m	= 1 << LEFT;
	int right_m = 1 << RIGHT;
	int b1_m	= 1 << B1;
	int b2_m	= 1 << B2;

	InputManager();
	~InputManager();
	void init(int r);
	void update(float df);
	void getInput();
	bool hasCommand(int c);
private:
	struct Input { int keys; float frame; };

	int getCurrentInput();

	sf::Keyboard::Key input[6];
	float COMBO_LIMIT = 30;
	float cooldown;
	float COOLDOWN_MAX = 2;
	std::deque<Input> prevInput;
};

