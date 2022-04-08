#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include"Player.h"

#ifndef  GAME_H
#define GAME_H

class Game
{
	public:
		Game();
		Game(const int,const int);
		//virtual ~Game(); // Remove Destructor?
		void run();

	private:
		sf::RenderWindow window;
		sf::Clock clock;
		std::unique_ptr<Player> player;
		//std::unique_ptr<Bird> birdPtr; CREATE BIRD CLASS TOMORROW
		bool gameWon;
		bool gameOver;
		bool timeRemaning;

		// FUNCTIONS
		void initVariables();

		void displayGameOver();

		void displayGameWon();

		void pollWindowEvents(sf::Event&);

		void handleInputs();

		void handleButtonEvents(sf::Event&);

		void updateObjects();

		void drawObjects();

		void startTimer();

};


#endif // ! GAME_H

