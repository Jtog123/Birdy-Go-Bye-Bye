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
	:birdVect1Position(700,150) // vector 1 position, where to create vector and use them?
{
	switch (bird_type)
	{
		case BirdType::Brown:
			if (!brownBirdText.loadFromFile("Sprites/BrownBirdSheet.png"))
			{
				std::cout << "Could not load Brown Birds" << std::endl;
				return;
			}
			brownBirdSprite.setTexture(brownBirdText);
			brownBirdSprite.setScale(1.75, 1.75);
			//brownBirdSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			//brownBirdSprite.setPosition(position);
			speed = 10;
			break;

		case BirdType::Blue:
			if (!blueBirdText.loadFromFile("Sprites/BlueBirdSheet.png"))
			{
				std::cout << "Could not load Blue Birds" << std::endl;
				return;
			}
			blueBirdSprite.setTexture(blueBirdText);
			blueBirdSprite.setScale(1.75, 1.75);
			speed = 25;
			break;

		case BirdType::Red:
			if (!redBirdText.loadFromFile("Sprites/BirdSheet1.png"))
			{
				std::cout << "Could not load Red Birds" << std::endl;
				return;
			}
			redBirdSprite.setTexture(redBirdText);
			redBirdSprite.setScale(1.75, 1.75);
			speed = 50;
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
	//window.draw(brownBirdSprite);
	//window.draw(blueBirdSprite);
	//window.draw(redBirdSprite);


	/*trying to draw each indivdual bird in the vector to the screen
	But im cimparing two different type Bird and BirdType*/


	levelOneBirdVect = createBirdVector(15, 0, 1);
	for (int i = 0; i < levelOneBirdVect.size(); ++i)
	{
		if (levelOneBirdVect[i] == BirdType::Brown)
		{
			//window.draw(brownBirdSprite)
		}
	}

}

void Bird::fly()
{

	//Stagger the position of each bird in BirdVectTest
	//How do i access each individual bird sprite within the vector?

	//std::vector<Bird> birdVectTest = createBirdVector(35, 0, 0);

	//for (int i = 0; i < birdVectTest.size(); ++i)
	//{

	//}


	if (frameCounter == 5)
	{
		frame = (frame + 1) % 8;
		frameCounter = 0;
	}
	++frameCounter;
	brownBirdSprite.setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
	birdVect1Position.x -= brownBirdVelX;
	brownBirdSprite.setPosition(birdVect1Position);
	

	//Create frame counter and row iterate through the frames and half the birds fly

	/*Keeps reseting its position every time though the loop need it to
	1. set initial position
	2. decrement pixels from that position*/
}

void Bird::setInitialBirdPosition(float x, float y)
{
	// blueBird.setPosition(position)
	// 
	//brownBirdSprite.setPosition(x, y);
}

void Bird::setSpeed(const float& sp)
{
	speed = sp;
}

float Bird::getSpeed() const
{
	return speed;
}
