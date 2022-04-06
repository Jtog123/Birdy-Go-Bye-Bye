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
		Player(sf::Vector2f& pos);
		void shoot();
		void setPosition(const sf::Vector2f&);
		sf::Vector2f getPosition() const;
		void draw(sf::RenderWindow&) override;

	private:
		sf::CircleShape scope;
		bool shotFired;
		sf::Vector2f position;

		// functions init variables? setCircle size and pos? set lines?

};


#endif // ! PLAYER_H

