#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include <iostream>

class InputManager
{
public:
	enum Control { UP, DOWN, LEFT, RIGHT, B1, B2 };
	enum Role { PL, PR };

	const int up_m		= 1 << UP;
	const int down_m	= 1 << DOWN;
	const int left_m	= 1 << LEFT;
	const int right_m	= 1 << RIGHT;
	const int b1_m		= 1 << B1;
	const int b2_m		= 1 << B2;

	const int isolated	= 1 << 0; // only compares bits in c (otherwise all bits in keys), not needed for single keys
	const int ignored	= 1 << 1; // ignores other bits (otherwise all bits not in c must be off), mutually exclusive with isolated
	const int matchall	= 1 << 2; // all bits must match (otherwise at least one), not needed for single keys

	InputManager();
	~InputManager();
	void init(Role r);
	void update();
	void getInput();
	bool hasCommand(int c, int idx, int cond); 
	/*
	bool hasCommandBsc(int c, int idx); // input has at least 1 bit in c, overrides med and adv
	bool hasCommandMed(int c, int idx); // input has only & at least 1 bit in c, overrides adv
	bool hasCommandAdv(int c, int idx); // input has exactly all bits in c
	*/
	int getDir();
	bool getCrouch();
private:
	struct Input { int keys; float frame; };

	int getCurrentInput();
	void printInput();

	sf::Keyboard::Key input[6];
	const float COMBO_LIMIT = 30;
	float inputTime;
	const float INPUT_TIME_MAX = 1;
	std::deque<Input> prevInput;
	int lastDir;
};

