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
		bool levelWon;
		bool gameOver;
		bool timeRemaning;
		std::vector<Bird> birdVectOne;
		Bird brownBird = BirdType::Brown;
		Bird blueBird = BirdType::Blue;
		Bird redBird = BirdType::Red;
		int frame = 0;
		int frameCounter = 0;
		float xPosVect1;
		sf::Vector2f vectOnePos;
		std::vector<Bird> birdVectTwo;
		sf::Vector2f vectTwoPos;
		sf::Texture cloudText1;
		sf::Texture cloudText2;

		sf::Sprite cloudSprite1;
		sf::Sprite cloudSprite2;

		sf::Texture birdBloodText;
		sf::Sprite birdBloodSprite;

		bool shotFired;
		sf::Font font;
		sf::RectangleShape nextLevelRect;
		sf::Text nextLevelText;

		BirdType targetBird;

		int score;
		sf::Text currentLevelText1;
		sf::Text currentLevelText2;
		int currentLevel = 1;



		// FUNCTIONS
		std::vector<Bird> createBirdVector(int numOfBrown, int numOfBlue, int numOfRed);

		void startBirdFlight();

		

		void birdDeath(const sf::Vector2f& position);

		void playerShoots(const sf::Event& event);

		void initVariables();

		void displayGameOver();

		void displayNextLevel();

		void pollWindowEvents(sf::Event&);

		void handleInputs();

		void handleButtonEvents(sf::Event&);

		void updateObjects();

		void drawObjects();

		void startTimer();


};



#endif // ! GAME_H

