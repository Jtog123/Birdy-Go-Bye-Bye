#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

class Entity //: public sf::Drawable
{
	public:
		Entity() {};
		//void draw(const sf::RenderTarget& target, sf::RenderStates) const override;
		// if redo REMOVE THHIS FUNCTION

		virtual void draw(sf::RenderWindow&) = 0; //commented out

	private:
};
#endif // !1
