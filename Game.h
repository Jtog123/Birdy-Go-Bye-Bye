#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"

#ifndef  GAME_H
#define GAME_H

class Game
{
	public:
		Game();
		virtual ~Game();
		void run();

	private:
		sf::RenderWindow window;
		sf::Clock clock;
		//std::unique_ptr<Player> player;
		//std::unique_ptr<Bird> birdPtr;
		bool gameWon;
		bool gameOver;
		bool timeRemaning;

		// FUNCTIONS

		void displayGameOver();

		void displayGameWon();

		void pollWindowEvents(sf::Event&);

		void handleInputs();

		void handleButtonEvents(sf::Event&);

		void updateObjects();

		void drawObjects();

		void startTime();

};


#endif // ! GAME_H

