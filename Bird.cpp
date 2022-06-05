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
			birdSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			break;
			
			
		case BirdType::Blue:
			if (!birdText.loadFromFile("Sprites/BlueBirdSheet.png"))
			{
				std::cout << "Could not load Blue Birds" << std::endl;
				return;
			}
			birdSprite.setTexture(birdText);
			birdSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			break;

		case BirdType::Red:
			if (!birdText.loadFromFile("Sprites/BirdSheet1.png"))
			{
				std::cout << "Could not load Red Birds" << std::endl;
				return;
			}
			birdSprite.setTexture(birdText);
			birdSprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
			break;
			
	}


}


void Bird::draw(sf::RenderWindow& window)
{
	//window.draw(birdSprite);
}

void Bird::fly()
{
	/*
	if (frameCounter == 5)
	{
		frame = (frame + 1) % 8;
		frameCounter = 0;
	}
	*/
	//++frameCounter;
	//birdSprite.setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
	//position.x -= birdVelX;
	
}

void Bird::setBirdPosition(sf::Vector2f pos)
{
	birdSprite.setPosition(pos);
}




sf::Sprite& Bird::getSprite()
{
	return birdSprite;
}

float Bird::getVelocity() const
{
	return birdVelX;
}
