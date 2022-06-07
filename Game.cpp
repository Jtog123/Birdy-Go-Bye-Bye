#include <iostream>
#include<vector>
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include "Game.h"




Game::Game()
{
    // EMPTY
}

Game::Game(const int width, const int height)
    : window(sf::VideoMode(width, height), "Speed Hunter"),
    player(std::make_unique<Player>(window)),
    birdPtr(std::make_unique<Bird>())
{
    window.setFramerateLimit(60);
    initVariables();

    // Set initial Position for first vector of birds
    for (int i = 0; i < birdVectOne.size(); ++i)
    {
        birdVectOne[i].getSprite().setPosition(vectOnePos.x, vectOnePos.y);
        birdVectOne[i].getSprite().setScale(1.75, 1.75);
        vectOnePos.x -= 70.f;
    }


    // Set initial Position for second vector of birds
    for (int i = 0; i < birdVectTwo.size(); ++i)
    {
        birdVectTwo[i].getSprite().setPosition(vectTwoPos); // set pos
        birdVectTwo[i].getSprite().setScale(-1.75, 1.75);
        vectTwoPos.x -= 70.f;
    }

    /* Load first cloud */ // Create load clouds function that moves them?
    if (!cloudText1.loadFromFile("Sprites/cloud1.png"))
    {
        std::cout << "Couldn't load cloud1" << std::endl;
    }
    cloudSprite1.setTexture(cloudText1);

    /* Load second cloud*/
    if (!cloudText1.loadFromFile("Sprites/cloud2.png"))
    {
        std::cout << "Couldn't load cloud2" << std::endl;
    }
    cloudSprite2.setTexture(cloudText2);

    cloudSprite1.setScale(7, 7);
    cloudSprite1.setPosition(-200, 80);



}

void Game::initVariables()

{
    gameWon = false;
    gameOver = false;
    timeRemaning = true;
    shotFired = false;
    birdVectOne = createBirdVector(10, 3, 1); // why does this not function properly?
    birdVectTwo = createBirdVector(13, 1, 0);

    vectOnePos.x = 1675;
    vectOnePos.y = 150;

    vectTwoPos.x = -100;
    vectTwoPos.y = 350;




}



void Game::displayGameOver()
{

}

void Game::displayGameWon()
{
}

void Game::pollWindowEvents(sf::Event& event)
{
}

void Game::handleInputs()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
                handleButtonEvents(event);
                break;
                   
        }
    }
}

void Game::handleButtonEvents(sf::Event& ev)
{
    switch (ev.mouseButton.button)
    {
        case sf::Mouse::Left:
            playerShoots(ev);
            break;
    }
}

void Game::updateObjects()
{


    //Set the position of the scope to that of the mouse
    player->setScopePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

    // Keeps Scope in bounds on Left Side
    // EXTRA 15 PIXELS FOR BUFFER
    if (player->getScopePosition().x < 15)
    {
        player->setScopePosition(15, player->getScopePosition().y);
    }

    // Keeps Scope in bounds on Right Side
    if (player->getScopePosition().x > window.getSize().x - 15)
    {
        player->setScopePosition(window.getSize().x - 15, player->getScopePosition().y);
    }

    // Keeps Scope in bounds on top
    if (player->getScopePosition().y < 15)
    {
        player->setScopePosition(player->getScopePosition().x, 15);
    }

    // Keeps Scope in bounds at Bottom
    if (player->getScopePosition().y > window.getSize().y - 15)
    {
        player->setScopePosition(player->getScopePosition().x, window.getSize().y - 15);
    }

    cloudSprite1.move(.4f, 0);

    startBirdFlight();
    // Doesnt stop bird flight because it keeps looping around needs
    // only start once
    //seperate something from the function the animation or the 
    // or load up a new sprite once its clicked and loop throuh that?
    // a ball of feathers or something.
    //then pop it out of the vector
    // we call birdVect[i].getSprite().die()
    // it loads up each individual feathers based on type.


}

void Game::drawObjects()
{
    window.clear(sf::Color(112,202,250));

    window.draw(cloudSprite1);
    window.draw(cloudSprite2);

    for (int i = 0; i < birdVectOne.size(); ++i)
    {
        window.draw(birdVectOne[i].getSprite());
    }

    for (int i = 0; i < birdVectTwo.size(); ++i)
    {
        window.draw(birdVectTwo[i].getSprite());
    }

    player->draw(window);

    window.display();

}

void Game::startTimer()
{
}

void Game::run()
{
    //Add texture here?



    while (window.isOpen())
    {

        handleInputs();

        updateObjects();

        if (gameOver)
        {
            displayGameOver();
            return;
        }

        if (gameWon)
        {
            displayGameWon();
            return;
        }


        drawObjects();


    }

}

std::vector<Bird> Game::createBirdVector(int numOfBrown, int numOfBlue, int numOfRed)
{

    std::vector<Bird> birdVect;

    for (int i = 0; i < numOfRed; ++i)
    {
        birdVect.push_back(redBird);
    }

    for (int i = 0; i < numOfBlue; ++i)
    {
        birdVect.push_back(blueBird);
    }

    for (int i = 0; i < numOfBrown; ++i)
    {
        birdVect.push_back(brownBird);
    }

    std::random_shuffle(birdVect.begin(), birdVect.end());

    return birdVect;
}

void Game::startBirdFlight()
{

    if (frameCounter == 5)
    {
        frame = (frame + 1) % 8;
        frameCounter = 0;
    }
    ++frameCounter;

    /* SETS TEXTURE RECT AND MOVES FIRST VECTOR OF BIRDS ACROSS SCREEN */
    for (int i = 0; i < birdVectOne.size(); ++i)
    {
        birdVectOne[i].getSprite().setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
    }

    for (int i = 0; i < birdVectOne.size(); ++i)
    {
        birdVectOne[i].getSprite().move(-1.5, 0);
    }


    /* SETS TEXTURE RECT AND MOVES SECOND VECTOR OF BIRDS ACROSS SCREEN */
    for (int i = 0; i < birdVectTwo.size(); ++i)
    {
        birdVectTwo[i].getSprite().setTextureRect(sf::IntRect(frame * 32, 0, 32, 32));
    }

    for (int i = 0; i < birdVectTwo.size(); ++i)
    {
        birdVectTwo[i].getSprite().move(1.5, 0);
    }


}

void Game::playerShoots( const sf::Event& ev)
{
    //std::cout << "Mouse position x is : " << ev.mouseButton.x << std::endl;
    //std::cout << "Mouse position y is : " << ev.mouseButton.y<< std::endl;
    //std::cout << "First bird pos x is : " << birdVectOne[birdVectOne.size() - 1].getSprite().getPosition().x << std::endl;
    //std::cout << "First bird pos y is : " << birdVectOne[birdVectOne.size() - 1].getSprite().getPosition().y << std::endl;

    
        //ev.mouseButton.x == birdVectOne[i].getSprite().getPosition().x

    /* Range of these two things? gives me 56*/
    //std::cout << birdVectOne[0].getSprite().getGlobalBounds().width << std::endl; // birdWidth
    //std::cout << birdVectOne[0].getSprite().getGlobalBounds().height << std::endl;

    //If the click happens in range one one spot to the next
    // if(ev.MouseButon.x >= )

    // front point -- birdVectOne[i].getSprite().getPosition().x
    // coords of click -- ev.MouseButon.x
    // back point -- birdVectOne[i].getSprite().getPosition().x + birdVectOne[i].getSprite().getGlobalBounds().width

    // top point -- birdVectOne[i].getSprite().getPosition().y
    // coords of click -- ev.MouseButon.y
    // bottom point -- birdVectOne[i].getSprite().getPosition().y + birdVectOne[i].getSprite().getGlobalBounds().height



    //being offset in the range of 20-40 pixels

    shotFired = true;
    if (shotFired)
    {
        for (int i = 0; i < birdVectOne.size(); ++i)
        {
            
            if (ev.mouseButton.x >= birdVectOne[i].getSprite().getPosition().x && 
                ev.mouseButton.x <= (birdVectOne[i].getSprite().getPosition().x + birdVectOne[i].getSprite().getGlobalBounds().width)
                && ev.mouseButton.y >= birdVectOne[i].getSprite().getPosition().y && 
                (ev.mouseButton.y <= birdVectOne[i].getSprite().getPosition().y + birdVectOne[i].getSprite().getGlobalBounds().height)
                )
            {

                std::cout << "Hit" << std::endl;
                
                birdVectOne[i].die(birdVectOne[i].getSprite().getPosition()); // call function pass in a position// with this position we
                //send it to the function, load up the new texture animate through it
                // then erase bird from teh vector

                // pop it out of the vector.
               
                //event.mouseButton.x and event.mouseButton.y

                        //make bird die
                        // bullets -= 1;
                    //else
                    ///{
                    //    gameOver = true;
                    //}
            }
        }

        // For vector 2
        for (int i = 0; i < birdVectTwo.size(); ++i)
        {
            if (ev.mouseButton.x >= birdVectTwo[i].getSprite().getPosition().x &&
                ev.mouseButton.x <= (birdVectTwo[i].getSprite().getPosition().x + birdVectTwo[i].getSprite().getGlobalBounds().width)
                && ev.mouseButton.y >= birdVectTwo[i].getSprite().getPosition().y &&
                (ev.mouseButton.y <= birdVectTwo[i].getSprite().getPosition().y + birdVectTwo[i].getSprite().getGlobalBounds().height)
                )
            {
                std::cout << "hit" << std::endl;
            }

        }

          
    }


        // for the scope maybe use a smallblack circle place in center of scope?
// putt small black circle in center of sprite
// if the small circle intersects bird and mouseisclicked
// 
// In the update part on click we will shoot the gun
//
// // shotFired = true
// bird dies and falls of map (along with this)
// totalBullets -= 1;

/* if (mousecliked)
* player->shoot() sets shotfired to true
* if(shotFired)
*	if(if the crosshairs allign and interact with bird pixels)
*		bird->die();
*		totalBullets -= 1;
*		check if game is won
*	else if(bullet MISSES and doesnt interact with pixels)
*		totalBullets -= 1;
*		check if game is over
*
* */

//contains()
}
