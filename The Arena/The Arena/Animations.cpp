#include "Animations.h"

namespace anim
{
	FrameContainer vishnu_idle_0("Resources/Textures/vishnu_idle.png", 4, 1, 0, 0, 6, true);
	FrameContainer vishnu_idle_1("Resources/Textures/vishnu_idle.png", 4, 1, 1, 0, 6, true);
	FrameContainer vishnu_idle_2("Resources/Textures/vishnu_idle.png", 4, 1, 2, 0, 6, true);
	FrameContainer vishnu_idle_3("Resources/Textures/vishnu_idle.png", 4, 1, 3, 0, 6, true);
	AnimationContainer vishnu_idle_ac;

	FrameContainer vishnu_walk_0("Resources/Textures/vishnu_walk.png", 4, 1, 0, 0, 6, true);
	FrameContainer vishnu_walk_1("Resources/Textures/vishnu_walk.png", 4, 1, 1, 0, 6, true);
	FrameContainer vishnu_walk_2("Resources/Textures/vishnu_walk.png", 4, 1, 2, 0, 6, true);
	FrameContainer vishnu_walk_3("Resources/Textures/vishnu_walk.png", 4, 1, 3, 0, 6, true);
	AnimationContainer vishnu_walk_ac;

	
	//FrameContainer vishnu_punch_0("Resources/Textures/vishnu_punch.png", 7, 1, 0, 0, 5, false);
	FrameContainer vishnu_punch_1("Resources/Textures/vishnu_punch.png", 7, 1, 1, 0, 5, false);
	FrameContainer vishnu_punch_2("Resources/Textures/vishnu_punch.png", 7, 1, 2, 0, 2, false);
	//FrameContainer vishnu_punch_3("Resources/Textures/vishnu_punch.png", 7, 1, 3, 0, 1, false);
	//FrameContainer vishnu_punch_4("Resources/Textures/vishnu_punch.png", 7, 1, 4, 0, 2, false);
	FrameContainer vishnu_punch_5("Resources/Textures/vishnu_punch.png", 7, 1, 5, 0, 4, true);
	FrameContainer vishnu_punch_6("Resources/Textures/vishnu_punch.png", 7, 1, 6, 0, 3, true);
	AnimationContainer vishnu_punch_ac;
	

	//FrameContainer vishnu_kick_0("Resources/Textures/vishnu_kick.png", 12, 1, 0, 0, 6, false);
	//FrameContainer vishnu_kick_1("Resources/Textures/vishnu_kick.png", 12, 1, 1, 0, 5, false);
	FrameContainer vishnu_kick_2("Resources/Textures/vishnu_kick.png", 12, 1, 2, 0, 4, false);
	//FrameContainer vishnu_kick_3("Resources/Textures/vishnu_kick.png", 12, 1, 3, 0, 6, false);
	FrameContainer vishnu_kick_4("Resources/Textures/vishnu_kick.png", 12, 1, 4, 0, 3, false);
	//FrameContainer vishnu_kick_5("Resources/Textures/vishnu_kick.png", 12, 1, 5, 0, 6, false);
	FrameContainer vishnu_kick_6("Resources/Textures/vishnu_kick.png", 12, 1, 6, 0, 6, false);
	FrameContainer vishnu_kick_7("Resources/Textures/vishnu_kick.png", 12, 1, 7, 0, 4, true);
	//FrameContainer vishnu_kick_8("Resources/Textures/vishnu_kick.png", 12, 1, 8, 0, 6, false);
	//FrameContainer vishnu_kick_9("Resources/Textures/vishnu_kick.png", 12, 1, 9, 0, 6, false);
	FrameContainer vishnu_kick_10("Resources/Textures/vishnu_kick.png", 12, 1, 10, 0, 7, true);
	//FrameContainer vishnu_kick_11("Resources/Textures/vishnu_kick.png", 12, 1, 11, 0, 4, false);
	AnimationContainer vishnu_kick_ac;



	void load_vishnu_idle_ac(Player* p)
	{
		vishnu_idle_ac.setOwner(p);
		vishnu_idle_ac.setLoop(true);
		vishnu_idle_ac.setSpdMult(1.0f);
		vishnu_idle_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(150, 50)));
		vishnu_idle_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_idle_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(90, 270)));
		vishnu_idle_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 320)), sf::Vector2f(80, 370)));
		vishnu_idle_ac.addFrame(&vishnu_idle_0);
		vishnu_idle_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(150, 50)));
		vishnu_idle_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_idle_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(140, 100)), sf::Vector2f(100, 270)));
		vishnu_idle_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 320)), sf::Vector2f(80, 370)));
		vishnu_idle_ac.addFrame(&vishnu_idle_1);
		vishnu_idle_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(160, 50)));
		vishnu_idle_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_idle_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(100, 270)));
		vishnu_idle_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(180, 160)), sf::Vector2f(80, 370)));
		vishnu_idle_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 170)), sf::Vector2f(80, 530)));
		vishnu_idle_ac.addFrame(&vishnu_idle_2);
		vishnu_idle_3.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(150, 50)));
		vishnu_idle_3.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_idle_3.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(90, 270)));
		vishnu_idle_3.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 320)), sf::Vector2f(80, 370)));
		vishnu_idle_ac.addFrame(&vishnu_idle_3);
	}

	void load_vishnu_walk_ac(Player* p)
	{
		vishnu_walk_ac.setOwner(p);
		vishnu_walk_ac.setLoop(true);
		vishnu_walk_ac.setSpdMult(1.0f);
		vishnu_walk_ac.addFrame(&vishnu_walk_0);
		vishnu_walk_ac.addFrame(&vishnu_walk_1);
		vishnu_walk_ac.addFrame(&vishnu_walk_2);
		vishnu_walk_ac.addFrame(&vishnu_walk_3);
	}

	void load_vishnu_punch_ac(Player* p)
	{
		vishnu_punch_ac.setOwner(p);
		vishnu_punch_ac.setLoop(false);
		vishnu_punch_ac.setSpdMult(0.2f);
		//vishnu_punch_ac.addFrame(&vishnu_punch_0);
		vishnu_punch_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(150, 50)));
		vishnu_punch_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_punch_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(90, 270)));
		vishnu_punch_1.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 320)), sf::Vector2f(80, 370)));
		vishnu_punch_1.addHitbox(new Vishnu_punch(sf::RectangleShape(sf::Vector2f(130, 100)), sf::Vector2f(330, 170)));
		vishnu_punch_ac.addFrame(&vishnu_punch_1);
		vishnu_punch_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(160, 50)));
		vishnu_punch_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(190, 100)), sf::Vector2f(90, 170)));
		vishnu_punch_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(90, 270)));
		vishnu_punch_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 320)), sf::Vector2f(80, 370)));
		vishnu_punch_2.addHitbox(new Vishnu_punch(sf::RectangleShape(sf::Vector2f(180, 80)), sf::Vector2f(370, 160)));
		vishnu_punch_ac.addFrame(&vishnu_punch_2);
		//vishnu_punch_ac.addFrame(&vishnu_punch_3);
		//vishnu_punch_ac.addFrame(&vishnu_punch_4);
		vishnu_punch_5.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(90, 120)), sf::Vector2f(160, 50)));
		vishnu_punch_5.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 100)), sf::Vector2f(90, 170)));
		vishnu_punch_5.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(130, 100)), sf::Vector2f(100, 270)));
		vishnu_punch_5.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 320)), sf::Vector2f(80, 370)));
		vishnu_punch_ac.addFrame(&vishnu_punch_5);
		vishnu_punch_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(90, 120)), sf::Vector2f(160, 50)));
		vishnu_punch_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 100)), sf::Vector2f(90, 170)));
		vishnu_punch_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(130, 100)), sf::Vector2f(100, 270)));
		vishnu_punch_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 320)), sf::Vector2f(80, 370)));
		vishnu_punch_ac.addFrame(&vishnu_punch_6);
	}

	void load_vishnu_kick_ac(Player* p)
	{
		vishnu_kick_ac.setOwner(p);
		vishnu_kick_ac.setLoop(false);
		vishnu_kick_ac.setSpdMult(0.1f);
		//vishnu_kick_ac.addFrame(&vishnu_kick_0);
		//vishnu_kick_ac.addFrame(&vishnu_kick_1);
		vishnu_kick_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(90, 120)), sf::Vector2f(170, 50)));
		vishnu_kick_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(110, 170)));
		vishnu_kick_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(130, 100)), sf::Vector2f(120, 270)));
		vishnu_kick_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 160)), sf::Vector2f(120, 370)));
		vishnu_kick_2.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 170)), sf::Vector2f(110, 530)));
		vishnu_kick_ac.addFrame(&vishnu_kick_2);
		//vishnu_kick_ac.addFrame(&vishnu_kick_3);
		vishnu_kick_4.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(170, 50)));
		vishnu_kick_4.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(110, 210)), sf::Vector2f(140, 170)));
		vishnu_kick_4.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(130, 150)), sf::Vector2f(170, 380)));
		vishnu_kick_4.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(50, 170)), sf::Vector2f(230, 530)));
		vishnu_kick_4.addHitbox(new Vishnu_kick(sf::RectangleShape(sf::Vector2f(90, 100)), sf::Vector2f(330, 380)));
		vishnu_kick_ac.addFrame(&vishnu_kick_4);
		//vishnu_kick_ac.addFrame(&vishnu_kick_5);
		vishnu_kick_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(170, 50)));
		vishnu_kick_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(110, 190)), sf::Vector2f(140, 170)));
		vishnu_kick_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(130, 90)), sf::Vector2f(180, 360)));
		vishnu_kick_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(80, 90)), sf::Vector2f(220, 450)));
		vishnu_kick_6.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(50, 160)), sf::Vector2f(240, 540)));
		vishnu_kick_6.addHitbox(new Vishnu_kick(sf::RectangleShape(sf::Vector2f(230, 80)), sf::Vector2f(380, 310)));
		vishnu_kick_ac.addFrame(&vishnu_kick_6);
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(90, 120)), sf::Vector2f(170, 50)));
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(110, 100)), sf::Vector2f(130, 170)));
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(120, 90)), sf::Vector2f(140, 270)));
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(110, 90)), sf::Vector2f(180, 360)));
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(70, 90)), sf::Vector2f(220, 450)));
		vishnu_kick_7.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(50, 160)), sf::Vector2f(240, 540)));
		vishnu_kick_ac.addFrame(&vishnu_kick_7);
		//vishnu_kick_ac.addFrame(&vishnu_kick_8);
		//vishnu_kick_ac.addFrame(&vishnu_kick_9);
		vishnu_kick_10.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(90, 120)), sf::Vector2f(170, 50)));
		vishnu_kick_10.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(140, 210)), sf::Vector2f(120, 170)));
		vishnu_kick_10.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 150)), sf::Vector2f(120, 380)));
		vishnu_kick_10.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(180, 170)), sf::Vector2f(100, 530)));
		vishnu_kick_ac.addFrame(&vishnu_kick_10);
		//vishnu_kick_ac.addFrame(&vishnu_kick_11);
	}
}


