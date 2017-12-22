#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationContainer.h"

namespace anim {
	static const FrameContainer vishnu_idle_1("Resources/Textures/vish_sheet.png", 4, 1, 0, 0);
	static const FrameContainer vishnu_idle_2("Resources/Textures/vish_sheet.png", 4, 1, 1, 0);
	static const FrameContainer vishnu_idle_3("Resources/Textures/vish_sheet.png", 4, 1, 2, 0);
	static const FrameContainer vishnu_idle_4("Resources/Textures/vish_sheet.png", 4, 1, 3, 0);
	static AnimationContainer vishnu_idle_ac;

	void load_vishnu_idle_ac(AnimationContainer& ac);
}


