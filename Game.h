#include <iostream>
#include<vector>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include"Player.h"
#include "Bird.h"


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
		std::unique_ptr<Bird> birdPtr;
		bool gameWon;
		bool gameOver;
		bool timeRemaning;
		std::vector<Bird> levelOneBirdVect;
		Bird brownBird = BirdType::Brown;
		Bird blueBird = BirdType::Blue;
		Bird redBird = BirdType::Red;



		// FUNCTIONS
		std::vector<Bird> createBirdVector(int numOfBrown, int numOfBlue, int numOfRed);

		void startBirdFlight();

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

