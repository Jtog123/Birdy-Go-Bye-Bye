#include "Player.h"
#include<iostream>

Player::Player()
{
}

Player::Player(sf::Vector2f& pos)
{
	//When creating the player pass in the center of the screen to the constructor;
	// May need to adjust as the scope will be onMouseHover
	//But this might be to set its initial position.
	setPosition(pos.x, pos.y);
}

void Player::shoot()
{
}

void Player::setPosition(const float xPos, const float yPos)
{
	// Set scope to the center;
	scopeSprite.setPosition(xPos, yPos);
}

void Player::draw(sf::RenderWindow& window)
{
	if (!texture.loadFromFile("Sprites/Scope.png"))
	{
		std::cout << "Could not load texture" << std::endl;
		return;
	}

	scopeSprite.setTexture(texture);
	scopeSprite.setScale(.25, .25);
	window.draw(scopeSprite);

}
