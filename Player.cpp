#include "Player.h"
#include<iostream>

Player::Player()
{	
}

Player::Player(const sf::RenderWindow& window)
	:shotFired(false), totalBullets(2)
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



sf::Vector2f Player::getScopePosition() const
{
	return scopePosition;
}

void Player::shoot()
{
	// for the scope maybe use a smallblack circle place in center of scope
	// if the small circle intersects bird and mouseisclicked
	// 
	// In the update part on click we will shoot the gun
	//
	// // shotFired = true
	// bird dies and falls of map (along with this)
	// totalBullets -= 1;

	/* if (mousecliked)
	* player->shoot() sets shotfired to true
	* if(shotFired)
	*	if(if the crosshairs allign and interact with bird pixels)
	*		bird->die();
	*		totalBullets -= 1;
	*		check if game is won
	*	else if(bullet MISSES and doesnt interact with pixels)
	*		totalBullets -= 1;
	*		check if game is over
	* 
	* */
	
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(scopeSprite);
}
