#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include"Entity.h"

#ifndef  PLAYER_H
#define PLAYER_H

class Player : public Entity
{
	public:
		Player();
		Player(const sf::RenderWindow&);
		void shoot();
		//void setScopePosition(const sf::Sprite&);
		sf::Vector2f getScopePosition() const;
		void draw(sf::RenderWindow&) override;

	private:
		sf::Texture texture;
		sf::Sprite scopeSprite;
		bool shotFired;
		sf::Vector2f scopePosition;
		int totalBullets;

		// functions init variables? setCircle size and pos? set lines?

};


#endif // ! PLAYER_H

