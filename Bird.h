#include"Entity.h"

#ifndef BIRD_H
#define BIRD_H

class Bird : public Entity
{
	public:
		Bird();
		void draw(sf::RenderWindow&) override;
		virtual void fly() = 0; // PURE VIRTUAL
		virtual void die() = 0; // PURE VIRTUAL
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

