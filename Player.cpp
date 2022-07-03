#include "Player.h"
#include<iostream>

Player::Player()
{	
}

Player::Player(const sf::RenderWindow& window)
	:shotFired(false), totalBullets(1)
{

	if (!texture.loadFromFile("Sprites/ScopeRedone6.png"))
	{
		std::cout << "Could not load texture" << std::endl;
		return;
	}

	scopeSprite.setTexture(texture);
	scopeSprite.setScale(.75, .75);
	scopeSprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);

}


void Player::setScopePosition(float x, float y)
{
	scopeSprite.setPosition(x, y);
}

sf::Vector2f Player::getScopePosition() const
{
	return scopeSprite.getPosition();
}

sf::Sprite Player::getSprite() const
{
	return scopeSprite;
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(scopeSprite);
}











