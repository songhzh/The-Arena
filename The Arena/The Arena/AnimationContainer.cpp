#include "AnimationContainer.h"
#include <SFML/Graphics/Rect.hpp>

AnimationContainer::AnimationContainer(sf::Texture texture1) {
	this->texture = texture1;
	sprite = sf::Sprite(texture);

	verticalTextureInterval = texture.getSize().y / verticalTextureNum;
}

void AnimationContainer::animationIdle(int textureNum1) {
	textureNum = textureNum1;

	textureInterval = texture.getSize().x / textureNum;
}

void AnimationContainer::setCurrentAnimation(int choice)
{
	this->currentAnimation = choice;
}

void AnimationContainer::getFrame()
{
	for (int i = 0; i < textureNum; i++) {
		rectangle = sf::IntRect(i * textureInterval, currentAnimation * verticalTextureInterval, textureInterval, verticalTextureInterval);
		sprite.setTextureRect(rectangle);
	}
}

sf::Sprite AnimationContainer::getCurrentSprite() {
	return sprite;
}