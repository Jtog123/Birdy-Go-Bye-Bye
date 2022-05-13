#include "Bird.h"

/*
For birds
Mixed vector of Birds?
Various colors speeds
Two rows of Brown Birds and Blue birds.
One row flying right. The other row flying left.
Positions?
Enums the solution to various birds? or enum classes? Get rid of inheritance. only one bird type changing its color and speed based on the enumeration.



If you would use enum there would only be one type Bird, not BlueBird RedBird etc.

But still, you can switch the texture by using the enum class above, instead of doing it in inheritance
and that one bird type would contain BirdColor color;
and in its draw, it'd do something like if(color == BirdColor::Red) {   ...set texture to red... }  else if { ...}

Yeah, but then it's semantically not only about the appearance so I'd name it a bit different:  enum class BirdType { Red, Brown, Blue}

*/



/*
* 



//Return to dynamically allocated redBirds?
//dynamically allocated vector of birds unique ptr;





int main()
{
	Bird redBird(BirdType::Red);
	//redBird.setSprite(png image?);


	vector<Bird> redBirdVect(50);
	for (int i = 0; i < redBirdVect.size(); ++i)
	{
		redBirdVect[i] = redBird;
	}

	return 0;
}

*/

Bird::Bird(BirdType bird_type)
{
	switch (bird_type)
	{
		case BirdType::Brown:
			if (!brownBirdText.loadFromFile("Sprites/BrownBirdSheet"))
			{
				std::cout << "Could not load Brown Birds" << std::endl;
				return;
			}
			brownBirdSprite.setTexture(brownBirdText);
			speed = 10;
			break;

		case BirdType::Blue:
			if (!blueBirdText.loadFromFile("Sprites/BlueBirdSheet"))
			{
				std::cout << "Could not load Blue Birds" << std::endl;
				return;
			}
			blueBirdSprite.setTexture(blueBirdText);
			speed = 25;
			break;

		case BirdType::Red:
			if (!redBirdText.loadFromFile("Sprites/BirdSheet1"))
			{
				std::cout << "Could not load Red Birds" << std::endl;
				return;
			}
			redBirdSprite.setTexture(redBirdText);
			speed = 50;
			break;
	}

}

void Bird::draw(sf::RenderWindow& window)
{
	window.draw(brownBirdSprite);
	//window.draw(blueBirdSprite);
	//window.draw(redBirdSprite);

}

void Bird::setPosition(const sf::Vector2f& pos)
{
	// blueBird.setPosition(position)
	// 
	position = pos;
}

void Bird::setSpeed(const float& sp)
{
	speed = sp;
}

float Bird::getSpeed() const
{
	return speed;
}
