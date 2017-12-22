#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationContainer.h"

namespace anim
{
	extern FrameContainer vishnu_idle_0;
	extern FrameContainer vishnu_idle_1;
	extern FrameContainer vishnu_idle_2;
	extern FrameContainer vishnu_idle_3;
	extern AnimationContainer vishnu_idle_ac;
	extern FrameContainer vishnu_punch_0;
	extern FrameContainer vishnu_punch_1;
	extern FrameContainer vishnu_punch_2;
	extern FrameContainer vishnu_punch_3;
	extern FrameContainer vishnu_punch_4;
	extern FrameContainer vishnu_punch_5;
	extern FrameContainer vishnu_punch_6;
	extern AnimationContainer vishnu_punch_ac;

	void load_vishnu_idle_ac();
	void load_vishnu_punch_ac();
}


