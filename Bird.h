#include"Entity.h"

#ifndef BIRD_H
#define BIRD_H

enum class BirdType
{
	Brown,
	Blue,
	Red,
};


class Bird
{
	public:
		Bird();
		Bird(const sf::RenderWindow& window);
		Bird(BirdType);
		void draw(sf::RenderWindow&);
		void fly(); // PURE VIRTUAL?
		void die(const sf::Vector2f& position); // Stop animating the bird, have it fall off the screen,, rotate it on its head
		BirdType getBirdType();


		void setBirdPosition(sf::Vector2f pos);
		sf::Vector2f getBirdPosition();
		sf::Sprite& getSprite();
		sf::Sprite& getFlippedSprite();
		float getVelocity() const;


	private:
		sf::Vector2f position; //all birds need a position on the screen
		//int frame = 0;
		//int frameCounter = 0;
		float birdVelX = 1.5f;
		sf::Texture birdText;
		sf::Sprite birdSprite;
		BirdType _birdType;
		//sf::Texture birdBloodText;
		//sf::Sprite birdBloodSprite;


};

//BlueBird blueBird;
//blueBird.setSpeed(blueBirdSpeed)

#endif // !BIRD_H

