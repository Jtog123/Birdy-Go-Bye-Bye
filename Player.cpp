#include "Player.h"
#include<iostream>

Player::Player()
{	
}

Player::Player(const sf::RenderWindow& window)
	:shotFired(false)
{
	/*
		Pass in the game window to set the Players posistion
	*/

	scopePosition.x = window.getPosition().x / 2;
	scopePosition.y = window.getPosition().y / 2;
	//get global bounds?

	if (!texture.loadFromFile("Sprites/Scope.png"))
	{
		std::cout << "Could not load texture" << std::endl;
		return;
	}

	scopeSprite.setTexture(texture);
	scopeSprite.setScale(.25, .25);
	scopeSprite.setPosition(scopePosition.x, scopePosition.y);

}


void Player::setScopePosition(const sf::Sprite& sprite)
{
	// Set scope to the center;
	//sprite.setPosition(position);
}

sf::Vector2f Player::getScopePosition() const
{
	return scopePosition;
}

void Player::shoot()
{
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(scopeSprite);
}
