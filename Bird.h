#include"Entity.h"

#ifndef BIRD_H
#define BIRD_H

enum class BirdType
{
	Brown,
	Blue,
	Red,
};

class Bird : public Entity
{
	public:
		Bird();
		Bird(BirdType);
		void draw(sf::RenderWindow&);
		void fly(); // PURE VIRTUAL?
		void die(); // PURE VIRTUAL?
		void setPosition(const sf::Vector2f&);
		sf::Vector2f getPosition() const;
		void setWidth(const int&);
		int getWidth() const;
		void setHeight(const int&);
		int getHeight() const;
		void setSpeed(const float&);
		float getSpeed() const;

	private:
		float speed;
		sf::Vector2f position;
		int width;
		int height;
		sf::Texture brownBirdText;
		sf::Texture blueBirdText;
		sf::Texture redBirdText;
		sf::Sprite brownBirdSprite;
		sf::Sprite blueBirdSprite;
		sf::Sprite redBirdSprite;


};

//BlueBird blueBird;
//blueBird.setSpeed(blueBirdSpeed)

#endif // !BIRD_H

