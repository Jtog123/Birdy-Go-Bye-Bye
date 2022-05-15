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
*/


Game::Game()
{
    // EMPTY
}

Game::Game(const int width, const int height)
    : window(sf::VideoMode(width,height), "Speed Hunter"),
    player(std::make_unique<Player>(window)),
    birdPtr(std::make_unique<Bird>(BirdType::Brown))
{
    window.setFramerateLimit(60);
    initVariables();

}

void Game::initVariables()
{
    gameWon = false;
    gameOver = false;
    timeRemaning = true;

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

    std::vector<Bird> bridVect = { BirdType::Brown, BirdType::Red };
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

    //Set Bird Row 1 position
    birdPtr->setBirdPosition(window.getSize().x - 100, window.getSize().y - 450);

}

void Game::drawObjects()
{
    window.clear(sf::Color::White);
    player->draw(window); //this should draw scope
    birdPtr->draw(window);

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




