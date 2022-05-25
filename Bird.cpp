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


REMINDER 
Each Bird instance I create is one individual Bird

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


Where am I going to need this vector?
How do i position the vector?
Do i position the vector or the collection of sprites?

Stegger the position of each bird in BirdVectTest


*/



Bird::Bird()
{
}

Bird::Bird(const sf::RenderWindow& window)
{
	
}

Bird::Bird(BirdType bird_type)
	:position(700,150)
	// vector 1 position, where to create vector and use them?
{
	switch (bird_type)
	{
		case BirdType::Brown:
			if (!birdText.loadFromFile("Sprites/BrownBirdSheet.png"))
			{
				std::cout << "Could not load Brown Birds" << std::endl;
				return;
			}
			birdSprite.setTexture(birdText);
			birdSprite.setScale(1.75, 1.75);
			break;

		case BirdType::Blue:
			if (!birdText.loadFromFile("Sprites/BlueBirdSheet.png"))
			{
				std::cout << "Could not load Blue Birds" << std::endl;
				return;
			}
			birdSprite.setTexture(birdText);
			birdSprite.setScale(1.75, 1.75);
			break;

		case BirdType::Red:
			if (!birdText.loadFromFile("Sprites/BirdSheet1.png"))
			{
				std::cout << "Could not load Red Birds" << std::endl;
				return;
			}
			birdSprite.setTexture(birdText);
			birdSprite.setScale(1.75, 1.75);
			break;
	}


}

std::vector<Bird> Bird::createBirdVector(int numOfBrown, int numOfBlue, int numOfRed)
{
	std::vector<Bird> birdVect;

	Bird brownBird(BirdType::Brown);
	Bird blueBird(BirdType::Blue);
	Bird redBird(BirdType::Red);

	for (int i = 0; i < numOfBrown; ++i)
	{
		birdVect.push_back(brownBird);
	}

	for (int i = 0; i < numOfBlue; ++i)
	{
		birdVect.push_back(blueBird);
	}

	for (int i = 0; i < numOfRed; ++i)
	{
		birdVect.push_back(redBird);
	}

	return birdVect;

}




void Bird::draw(sf::RenderWindow& window)
{
	window.draw(birdSprite);

}

void Bird::fly()
{


	if (frameCounter == 5)
	{
		frame = (frame + 1) % 8;
		frameCounter = 0;
	}
	++frameCounter;
	birdSprite.setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
	position.x -= birdVelX;
	birdSprite.setPosition(position);

	//Setting the bird sprite in two different positions.
	

	//Create frame counter and row iterate through the frames and half the birds fly

	/*Keeps reseting its position every time though the loop need it to
	1. set initial position
	2. decrement pixels from that position*/
}

void Bird::setBirdPosition(sf::Vector2f pos)
{
	// blueBird.setPosition(position)
	// 
	//brownBirdSprite.setPosition(x, y);
}

sf::Vector2f Bird::getPosition() const
{
	return position;
}


sf::Sprite Bird::getSprite() const
{
	return birdSprite;
}
