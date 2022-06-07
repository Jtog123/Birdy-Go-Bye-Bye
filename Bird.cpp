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
	//window.draw(birdBloodSprite);
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

void Bird::die(const sf::Vector2f& position)
{
	//send it to the function, load up the new texture animate through it
// then erase bird from teh vector
	//load up the texture 
	//set its position to the one passed in
	//animate throught
	/*
	int frameCounter = 0;
	int frame = 0;
	if (!birdBloodText.loadFromFile("Sprites/BloodSpurtAnimation.png"))
	{
		std::cout << "Couldnt load blood spurt" << std::endl;
	}
	birdBloodSprite.setTexture(birdBloodText);
	birdBloodSprite.setScale(8, 8);
	birdBloodSprite.setPosition(position);
	if (frameCounter == 5)
	{
		frame = (frame + 1) % 5;
		frameCounter = 0;
	}
	++frameCounter;
	birdBloodSprite.setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
	*/
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
