#include "AnimationContainer.h"

AnimationContainer::AnimationContainer()
{
}

AnimationContainer::~AnimationContainer()
{
}

void AnimationContainer::init(sf::Texture texture1, int duration)
{
	texture = texture1;
	sprite = sf::Sprite(texture);
	textureNum = duration;
}

void AnimationContainer::setCurrentAnimation(int choice)
{
	currentAnimation = choice;
}

void AnimationContainer::getFrame()
{
	int textureInterval = texture.getSize().x / textureNum;
	int verticalTextureInterval = texture.getSize().y / verticalTextureNum;

	for (int i = 0; i < textureNum; i++) {
		sf::IntRect rectangle(i * textureInterval, currentAnimation * verticalTextureInterval, textureInterval, verticalTextureInterval);
		sprite.setTextureRect(rectangle);
	}
}

sf::Sprite AnimationContainer::getCurrentSprite() {
	return sprite;
}