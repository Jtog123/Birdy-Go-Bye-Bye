#include "Player.h"
#include<iostream>

Player::Player()
{	
}

Player::Player(const sf::RenderWindow& window)
	:shotFired(false), totalBullets(1)
{

	if (!texture.loadFromFile("Sprites/Scope.png"))
	{
		std::cout << "Could not load texture" << std::endl;
		return;
	}

	scopeSprite.setTexture(texture);
	scopeSprite.setScale(.75, .75);
	scopeSprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);

}

//Function that gets the scope center?


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




/*
void Player::draw(const sf::RenderTarget& window, sf::RenderStates) const
{
	window.draw(scopeSprite);
}
*/

void Player::shoot()
{
	// Pass pointer to bird object? or do shooting in game class
	// 
	// for the scope maybe use a smallblack circle place in center of scope?
	// putt small black circle in center of sprite
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





