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
    levelOneBirdVect = createBirdVector(7, 3, 1); // why does this not function properly?
    

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


    int position = 700;
    for(int i = 0 ; i < levelOneBirdVect.size(); ++i)
    {
        levelOneBirdVect[i].getSprite().setPosition(position, 150);
        position -= 60;
    }


    birdPtr->fly();

}

void Game::drawObjects()
{
    window.clear(sf::Color::White);


    //Birds being drawn? Stagger their positions?
    
    for (int i = 0; i < levelOneBirdVect.size(); ++i)
    {
        window.draw(levelOneBirdVect[i].getSprite());
    }

    player->draw(window); //this should draw scope
    
    
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

        //birdPtr->fly();

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




