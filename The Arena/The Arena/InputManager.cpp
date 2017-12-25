#include "InputManager.h"

InputManager::InputManager()
{
	inputTime = 0;
}


InputManager::~InputManager()
{
}

void InputManager::init(Role r)
{
	switch (r)
	{
	case PL:
		input[UP]		= sf::Keyboard::W;
		input[DOWN]		= sf::Keyboard::S;
		input[LEFT]		= sf::Keyboard::A;
		input[RIGHT]	= sf::Keyboard::D;
		input[B1]		= sf::Keyboard::C;
		input[B2]		= sf::Keyboard::V;
		break;
	case PR:
		input[UP]		= sf::Keyboard::I;
		input[DOWN]		= sf::Keyboard::K;
		input[LEFT]		= sf::Keyboard::J;
		input[RIGHT]	= sf::Keyboard::L;
		input[B1]		= sf::Keyboard::Period;
		input[B2]		= sf::Keyboard::Slash;
		break;
	default:
		break;
	}
}

void InputManager::update()
{
	if (inputTime > 0)
		inputTime--;

	for (std::deque<Input>::iterator it = prevInput.begin(); it != prevInput.end(); it++)
	{	
		if (it->frame < 0)
		{
			prevInput.erase(it, prevInput.end());
			return;
		}
		it->frame--;
	}

	//std::cout << prevInput.size() << std::endl;
}

void InputManager::printInput()
{
	if (prevInput.size() < 1) return;

	int k = prevInput.front().keys;
	int up = (k | up_m) == k;
	int down = (k | down_m) == k;
	int left = (k | left_m) == k;
	int right = (k | right_m) == k;
	int b1 = (k | b1_m) == k;
	int b2 = (k | b2_m) == k;

	printf("[%d][%d][%d][%d][%d][%d]\n", up, down, left, right, b1, b2);
}

void InputManager::getInput()
{
	if (inputTime == 0)
	{
		inputTime = INPUT_TIME_MAX;
		Input i = { 0 , 0 };
		prevInput.push_front(i);
	}
		
	prevInput.front() = { prevInput.front().keys | getCurrentInput(), COMBO_LIMIT };

	if (prevInput.size() < 1) return;
	if (prevInput.front().keys | left_m | right_m)
	{
		switch (lastDir)
		{
		case -1:
			lastDir = prevInput.front().keys & right_m ? 1 : -1;
			break;
		case 1:
			lastDir = prevInput.front().keys & left_m ? -1 : 1;
			break;
		default:
			lastDir = -1;
			break;
		}
	}

	//printInput();
}

int InputManager::getCurrentInput()
{
	return
		sf::Keyboard::isKeyPressed(input[UP]) * up_m |
		sf::Keyboard::isKeyPressed(input[DOWN]) * down_m |
		sf::Keyboard::isKeyPressed(input[LEFT]) * left_m |
		sf::Keyboard::isKeyPressed(input[RIGHT]) * right_m |
		sf::Keyboard::isKeyPressed(input[B1]) * b1_m |
		sf::Keyboard::isKeyPressed(input[B2]) * b2_m;
}

bool InputManager::hasCommandBsc(int c, int idx)
{
	if (prevInput.size() <= idx) return false;

	return prevInput[idx].keys & c;
}


bool InputManager::hasCommandAdv(int c, int idx)
{
	if (prevInput.size() <= idx) return false;
	return prevInput[idx].keys == c;
}

int InputManager::getDir()
{
	bool left = sf::Keyboard::isKeyPressed(input[LEFT]);
	bool right = sf::Keyboard::isKeyPressed(input[RIGHT]);
	if (left ^ right)
		lastDir = left ? -1 : 1;
	return left || right ? lastDir : 0;
}

bool InputManager::getCrouch()
{
	return sf::Keyboard::isKeyPressed(input[DOWN]);
}