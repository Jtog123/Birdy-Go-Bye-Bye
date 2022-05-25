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
		std::vector<Bird> createBirdVector(int numOfBrown, int numOfBlue, int numOfRed);
		void draw(sf::RenderWindow&);
		void fly(); // PURE VIRTUAL?
		void die(); // Stop animating the bird, have it fall off the screen,, rotate it on its head
		void setInitialBirdPosition(float,float);
		sf::Vector2f getPosition() const;
		void setWidth(const int&);
		int getWidth() const;
		void setHeight(const int&);
		int getHeight() const;
		void setSpeed(const float&);
		float getSpeed() const;
		sf::Sprite getSprite() const;

	private:
		float speed;
		sf::Vector2f vectOnePosition;
		int width;
		int height;
		int frame = 0;
		int frameCounter = 0;
		float birdVelX = 1.5f;
		sf::Texture birdText;
		sf::Sprite birdSprite;



		//sf::Texture blueBirdText;
		//sf::Texture redBirdText;
		
		//sf::Sprite blueBirdSprite;
		//sf::Sprite redBirdSprite;


};

//BlueBird blueBird;
//blueBird.setSpeed(blueBirdSpeed)

#endif // !BIRD_H

