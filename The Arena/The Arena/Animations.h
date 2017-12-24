#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationContainer.h"

namespace anim
{
	extern AnimationContainer vishnu_projectile_ac;
	extern AnimationContainer vishnu_gate_ac;
	extern AnimationContainer vishnu_idle_ac;
	extern AnimationContainer vishnu_walk_ac;
	extern AnimationContainer vishnu_punch_ac;
	extern AnimationContainer vishnu_kick_ac;

	void load_vishnu_gate_ac(Player* p);
	void load_vishnu_projectile_ac(Player* p);
	void load_vishnu_idle_ac(Player* p);
	void load_vishnu_walk_ac(Player* p);
	void load_vishnu_punch_ac(Player* p);
	void load_vishnu_kick_ac(Player* p);
}


