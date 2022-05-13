#include <iostream>
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
//#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include"Entity.h"

#ifndef  PLAYER_H
#define PLAYER_H

class Player 
{
	public:
		Player();
		Player(const sf::RenderWindow&);
		void shoot();
		//void setScopePosition(const sf::Sprite&);
		void setScopePosition(float x, float y);
		sf::Vector2f getScopePosition() const;
		sf::Sprite getSprite() const;

		//void draw(const sf::RenderTarget& window, sf::RenderStates) const override;

		void draw(sf::RenderWindow&); // VIRTUAL FUNCTION

	private:
		sf::Texture texture;
		sf::Sprite scopeSprite;
		bool shotFired;
		sf::Vector2f scopePosition;
		int totalBullets;

		// functions init variables? setCircle size and pos? set lines?

};


#endif // ! PLAYER_H

