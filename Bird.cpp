#include "Bird.h"

/*
REMINDER 
Each Bird instance I create is one individual Bird

*/





Bird::Bird()
{
}

Bird::Bird(const sf::RenderWindow& window)
{
	
}

/*


5/27/22

If you create the bird texture outside of the Bird object, you can keep it around indefinitely and just assign each bird to use the texture
you should probably also be creating the vector of birds outside of the Bird object rather than in a method of Bird

probably won't even need the bird type if all that's changing is the color, just use a different texture or modify the color of the sprite

void StartGame() {
  sf::Texture birdTexture;
  birdTexture.loadFromFile("./bird.png");

  vector<Bird> birds;
  for (int i=0; i<numBrownBirds; i++)
	birds.emplace_back(BirdType::Brown, birdTexture);
  // blue birds...
  // red birds...

  // do game loop
}

*/

Bird::Bird(BirdType bird_type)
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
			birdSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
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
	//birdSprite.setPosition(position);
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
