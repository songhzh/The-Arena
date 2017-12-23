#include "Animations.h"

namespace anim
{
	FrameContainer vishnu_idle_0("Resources/Textures/vishnu_idle.png", 4, 1, 0, 0, 6, true);
	FrameContainer vishnu_idle_1("Resources/Textures/vishnu_idle.png", 4, 1, 1, 0, 6, true);
	FrameContainer vishnu_idle_2("Resources/Textures/vishnu_idle.png", 4, 1, 2, 0, 6, true);
	FrameContainer vishnu_idle_3("Resources/Textures/vishnu_idle.png", 4, 1, 3, 0, 6, true);
	AnimationContainer vishnu_idle_ac;
	
	
	FrameContainer vishnu_punch_0("Resources/Textures/vishnu_punch.png", 7, 1, 0, 0, 5, false);
	FrameContainer vishnu_punch_1("Resources/Textures/vishnu_punch.png", 7, 1, 1, 0, 3, false);
	FrameContainer vishnu_punch_2("Resources/Textures/vishnu_punch.png", 7, 1, 2, 0, 1, false);
	//FrameContainer vishnu_punch_3("Resources/Textures/vishnu_punch.png", 7, 1, 3, 0, 1, false);
	//FrameContainer vishnu_punch_4("Resources/Textures/vishnu_punch.png", 7, 1, 4, 0, 2, false);
	FrameContainer vishnu_punch_5("Resources/Textures/vishnu_punch.png", 7, 1, 5, 0, 4, false);
	FrameContainer vishnu_punch_6("Resources/Textures/vishnu_punch.png", 7, 1, 6, 0, 3, true);
	
	/*
	FrameContainer vishnu_punch_0("Resources/Textures/vishnu_punch.png", 7, 1, 0, 0, 1, false);
	FrameContainer vishnu_punch_1("Resources/Textures/vishnu_punch.png", 7, 1, 1, 0, 1, false);
	FrameContainer vishnu_punch_2("Resources/Textures/vishnu_punch.png", 7, 1, 2, 0, 1000, false);
	//FrameContainer vishnu_punch_3("Resources/Textures/vishnu_punch.png", 7, 1, 3, 0, 1, false);
	//FrameContainer vishnu_punch_4("Resources/Textures/vishnu_punch.png", 7, 1, 4, 0, 1, false);
	FrameContainer vishnu_punch_5("Resources/Textures/vishnu_punch.png", 7, 1, 5, 0, 1, false);
	FrameContainer vishnu_punch_6("Resources/Textures/vishnu_punch.png", 7, 1, 6, 0, 1, true);
	*/
	AnimationContainer vishnu_punch_ac;

	void load_vishnu_idle_ac(Player* p)
	{
		vishnu_idle_ac.setOwner(p);
		vishnu_idle_ac.setLoop(true);
		vishnu_idle_ac.setSpdMult(1);
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

	void load_vishnu_punch_ac(Player* p)
	{
		vishnu_punch_ac.setOwner(p);
		vishnu_punch_ac.setLoop(false);
		vishnu_punch_ac.setSpdMult(0.3f);
		vishnu_punch_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(100, 120)), sf::Vector2f(150, 50)));
		vishnu_punch_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(170, 100)), sf::Vector2f(90, 170)));
		vishnu_punch_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(150, 100)), sf::Vector2f(90, 270)));
		vishnu_punch_0.addHitbox(new Hurtbox(sf::RectangleShape(sf::Vector2f(160, 320)), sf::Vector2f(80, 370)));
		vishnu_punch_ac.addFrame(&vishnu_punch_0);
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
}


