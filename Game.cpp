#include <iostream>
#include<vector>
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include "Game.h"

/*
*     Bird brownB(BirdType::Brown);
    std::vector<Bird> birdVect(50);
    for (int i = 0; i < birdVect.size(); ++i)
    {
        birdVect[i] = brownB;
    }

    You don't need to colour them
Just load a different file depending on the bird type

you also have 3 sets of the same variable, one for each color type, but a single bird should only have 1 color, 
so it makes sense it should only have 1 of each of those variables and they just be agnostic to what color it is since that is defined by the BirdType
The Bird class should not know nor care how many birds you create nor whether you make a container of them.
then in the game (outside of the Bird class) you can do something like std::vector<Bird> birds to create multiple birds
*/


Game::Game()
{
    // EMPTY
}

Game::Game(const int width, const int height)
    : window(sf::VideoMode(width,height), "Speed Hunter"),
    player(std::make_unique<Player>(window)),
    birdPtr(std::make_unique<Bird>())
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
    levelOneBirdVect = birdPtr->createBirdVector(5, 0, 0); // levelOneBirdVect add to class?

    // Loop through the vector to draw?

    
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


    birdPtr->fly();

}

void Game::drawObjects()
{
    window.clear(sf::Color::White);

    player->draw(window); //this should draw scope
   // birdPtr->draw(window);


    //ALL BIRDS ARE BEING DRAW NOW STAGGER THEIR POSITIONS. IN UPDATEOBJECTS?
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




