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
    player(std::make_unique<Player>(window))// ADD PLAYER?
{
    window.setFramerateLimit(60);
    initVariables();

}

void Game::initVariables()
{
    gameWon = false;
    gameOver = false;
    timeRemaning = true;
    //Player playerTest(window);
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
}

void Game::handleButtonEvents(sf::Event&)
{
}

void Game::updateObjects()
{
    
}

void Game::drawObjects()
{
    player->draw(window); //this should draw scope

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




