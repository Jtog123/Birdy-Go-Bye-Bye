#include <iostream>
#include<vector>
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include "Game.h"


/*
Im not able to make adjustments to the sprite from any other part of the game except for in the constructor

The only part of the code in my game class that actually is doing something is this, where im able to draw the bird.

void Game::drawObjects()
{
    for (int i = 0; i < levelOneBirdVect.size(); ++i)
    {
      window.draw(levelOneBirdVect[i].getSprite());
    }

    window.display();
}


But I cant tell if im actually drawing more than one bird.


Tracing this has been really hard. Things I thought would work aren't for some reason.
Like for instance I put this in my games updateobjects function and it didnt do anything.

    for(int i = 0 ; i < levelOneBirdVect.size(); ++i)
    {
        levelOneBirdVect[i].getSprite().setPosition(700, 150);
    }

Why does the loop above draw the sprite, but the loop here isnt adjusting position? 
I dont know where and (even worse) why I'm losing access to my sprites.
*/


Game::Game()
{
    // EMPTY
}

Game::Game(const int width, const int height)
    : window(sf::VideoMode(width,height), "Speed Hunter"),
    player(std::make_unique<Player>(window))
    //birdPtr(std::make_unique<Bird>())
{
    window.setFramerateLimit(60);
    initVariables();


    //    gl_vec = std::unique_ptr<std::vector<MyClass>>(new std::vector<MyClass>());
    //std::make_unique<std::vector<Bird>>(BirdType::Brown))
    // std::make_unique<Bird>(BirdType::Brown)


    //initial a vector full of birds and view them on the screen

}

void Game::initVariables()

{
    gameWon = false;
    gameOver = false;
    timeRemaning = true;
    levelOneBirdVect = createBirdVector(5, 0, 0); // why does this not function properly?

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
            }
        }
}

void Game::handleButtonEvents(sf::Event&)
{
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

    for(int i = 0 ; i < levelOneBirdVect.size(); ++i)
    {
        levelOneBirdVect[i].getSprite().setPosition(700, 150);
    }

    birdPtr->fly();

}

void Game::drawObjects()
{
    window.clear(sf::Color::Red);

    player->draw(window); //this should draw scope

    //Birds being drawn? Stagger their positions?

    for (int i = 0; i < levelOneBirdVect.size(); ++i)
    {
      window.draw(levelOneBirdVect[i].getSprite());
    }
    
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

        birdPtr->fly();

        drawObjects();


    }

}

std::vector<Bird> Game::createBirdVector(int numOfBrown, int numOfBlue, int numOfRed)
{
    std::vector<Bird> birdVect;

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




