#include "Bird.h"

Bird::Bird()
{
	if (!brownBirdText.loadFromFile("Sprites/BrownBirdSheet"))
	{
		std::cout << "Could not load Brown Birds" << std::endl;
		return;
	}
	brownBirdSprite.setTexture(brownBirdText);

	if (!blueBirdText.loadFromFile("Sprites/BlueBirdSheet"))
	{
		std::cout << "Could not load Blue Birds" << std::endl;
		return;
	}
	blueBirdSprite.setTexture(blueBirdText);

	if (!redBirdText.loadFromFile("Sprites/BirdSheet1"))
	{
		std::cout << "Could not load Red Birds" << std::endl;
		return;
	}
	redBirdSprite.setTexture(redBirdText);
}

void Bird::draw(sf::RenderWindow& window)
{
	// Draw Bird Sprite here? Or in indivdual class?
	window.draw(brownBirdSprite);
	window.draw(blueBirdSprite);
	window.draw(redBirdSprite);
}

void Bird::setPosition(const sf::Vector2f& pos)
{
	this->position = pos;
}

void Bird::setSpeed(const float& sp)
{
	this->speed = sp;
}

float Bird::getSpeed() const
{
	return speed;
}
