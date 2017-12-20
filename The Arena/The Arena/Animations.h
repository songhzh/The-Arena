#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationContainer.h"

namespace anim {
	static FrameContainer vishnu_idle_1("Resources/Textures/vish_sheet.png", 2, 1, 0, 0);
	static FrameContainer vishnu_idle_2("Resources/Textures/vish_sheet.png", 2, 1, 1, 0);

	void load_vishnu_idle(AnimationContainer& ac);
}


