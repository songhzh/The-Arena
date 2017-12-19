#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

class InputManager
{
public:
	enum Control { UP, DOWN, LEFT, RIGHT, B1, B2, ERROR };

	const int up_m		= 1 << UP;
	const int down_m	= 1 << DOWN;
	const int left_m	= 1 << LEFT;
	const int right_m	= 1 << RIGHT;
	const int b1_m		= 1 << B1;
	const int b2_m		= 1 << B2;

	InputManager();
	~InputManager();
	void init(int r);
	void update(float df);
	void getInput();
	bool hasCommand(int c);
	int getDir();
private:
	struct Input { int keys; float frame; };

	int getCurrentInput();

	sf::Keyboard::Key input[6];
	float COMBO_LIMIT = 30;
	float cooldown;
	float COOLDOWN_MAX = 3;
	std::deque<Input> prevInput;
};

