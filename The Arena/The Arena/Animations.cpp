#include "Animations.h"

namespace anim
{
	FrameContainer vishnu_idle_0("Resources/Textures/vishnu_idle.png", 4, 1, 0, 0, 3, true);
	FrameContainer vishnu_idle_1("Resources/Textures/vishnu_idle.png", 4, 1, 1, 0, 3, true);
	FrameContainer vishnu_idle_2("Resources/Textures/vishnu_idle.png", 4, 1, 2, 0, 3, true);
	FrameContainer vishnu_idle_3("Resources/Textures/vishnu_idle.png", 4, 1, 3, 0, 3, true);
	AnimationContainer vishnu_idle_ac;
	FrameContainer vishnu_punch_0("Resources/Textures/vishnu_punch.png", 7, 1, 0, 0, 4, false);
	FrameContainer vishnu_punch_1("Resources/Textures/vishnu_punch.png", 7, 1, 1, 0, 4, false);
	FrameContainer vishnu_punch_2("Resources/Textures/vishnu_punch.png", 7, 1, 2, 0, 2, false);
	FrameContainer vishnu_punch_3("Resources/Textures/vishnu_punch.png", 7, 1, 3, 0, 2, false);
	FrameContainer vishnu_punch_4("Resources/Textures/vishnu_punch.png", 7, 1, 4, 0, 2, false);
	FrameContainer vishnu_punch_5("Resources/Textures/vishnu_punch.png", 7, 1, 5, 0, 3, false);
	FrameContainer vishnu_punch_6("Resources/Textures/vishnu_punch.png", 7, 1, 6, 0, 3, true);
	AnimationContainer vishnu_punch_ac;

	void load_vishnu_idle_ac()
	{
		
		/*
		Hurtbox hb;
		//hb.init(sf::Vector2f(50, 120));
		vishnu_idle_0.addHitbox(hb);
		//hb.init(sf::Vector2f(-10, -20));
		vishnu_idle_1.addHitbox(hb);
		vishnu_idle_2.addHitbox(hb);
		vishnu_idle_3.addHitbox(hb);
		*/

		vishnu_idle_ac.setLoop(true);

		vishnu_idle_ac.addFrame(vishnu_idle_0);
		vishnu_idle_ac.addFrame(vishnu_idle_1);
		vishnu_idle_ac.addFrame(vishnu_idle_2);
		vishnu_idle_ac.addFrame(vishnu_idle_3);
	}

	void load_vishnu_punch_ac()
	{
		vishnu_punch_ac.setLoop(false);
		vishnu_punch_ac.addFrame(vishnu_punch_0);
		vishnu_punch_ac.addFrame(vishnu_punch_1);
		vishnu_punch_ac.addFrame(vishnu_punch_2);
		vishnu_punch_ac.addFrame(vishnu_punch_3);
		vishnu_punch_ac.addFrame(vishnu_punch_4);
		vishnu_punch_ac.addFrame(vishnu_punch_5);
		vishnu_punch_ac.addFrame(vishnu_punch_6);
	}
}


