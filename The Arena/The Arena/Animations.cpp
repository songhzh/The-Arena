#include "Animations.h"

namespace anim
{
	FrameContainer vishnu_idle_1("Resources/Textures/vish_sheet.png", 4, 1, 0, 0);
	FrameContainer vishnu_idle_2("Resources/Textures/vish_sheet.png", 4, 1, 1, 0);
	FrameContainer vishnu_idle_3("Resources/Textures/vish_sheet.png", 4, 1, 2, 0);
	FrameContainer vishnu_idle_4("Resources/Textures/vish_sheet.png", 4, 1, 3, 0);
	AnimationContainer vishnu_idle_ac;

	void load_vishnu_idle_ac()
	{
		vishnu_idle_ac.addFrame(vishnu_idle_1, 6);
		vishnu_idle_ac.addFrame(vishnu_idle_2, 6);
		vishnu_idle_ac.addFrame(vishnu_idle_3, 6);
		vishnu_idle_ac.addFrame(vishnu_idle_4, 6);
	}
}


