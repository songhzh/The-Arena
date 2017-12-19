#include "InputManager.h"

InputManager::InputManager()
{
	cooldown = 0;
}


InputManager::~InputManager()
{
}

void InputManager::init(int r)
{
	switch (r)
	{
	case 0:
		input[UP]		= sf::Keyboard::W;
		input[DOWN]		= sf::Keyboard::S;
		input[LEFT]		= sf::Keyboard::A;
		input[RIGHT]	= sf::Keyboard::D;
		input[B1]		= sf::Keyboard::C;
		input[B2]		= sf::Keyboard::V;
		break;
	case 1:
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

void InputManager::update(float df)
{
	std::cout << prevInput.size() << std::endl;
	for (std::deque<Input>::iterator it = prevInput.begin(); it != prevInput.end(); it++)
	{
		it->frame -= df;
		
		if (it->frame < 0)
		{
			prevInput.erase(it, prevInput.end());
			return;
		}
	}

	cooldown > 0 ? cooldown -= df : cooldown = 0;
}

void InputManager::getInput()
{
	if (cooldown == 0)
	{
		Input i = { getCurrentInput(), COMBO_LIMIT };
		prevInput.push_front(i);
		cooldown = COOLDOWN_MAX;
	}
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

bool InputManager::hasCommand(int c)
{
	if (prevInput.size() < 1) return false;
	/*
	for (int i = 5; i >= 0; i--)
	{
		std::cout << ((prevInput.front().keys >> i) & 1) ;
	}
	std::cout << std::endl;
	*/

	//std::cout << c << " " << (prevInput.front().keys | c) << " " << prevInput.front().keys << std::endl;
	if ((prevInput.front().keys | c) == prevInput.front().keys)
	{
		prevInput.pop_front();
		return true;
	}
	return false;
}