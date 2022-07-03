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
		Bird(BirdType);
		void draw(sf::RenderWindow&);
		BirdType getBirdType();
		void setBirdPosition(sf::Vector2f pos);
		sf::Sprite& getSprite();
		float getVelocity() const;


	private:
		sf::Vector2f position;
		float birdVelX = 1.5f;
		sf::Texture birdText;
		sf::Sprite birdSprite;
		BirdType _birdType;

};


#endif // !BIRD_H

