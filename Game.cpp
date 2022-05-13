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
    //sscopeSprite.setPoition(Mouse::getposition(window).x,Mouse::getposition(window).y)
    player->setScopePosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

    //Hits 0,0 when center of the scope is in top left corner
    std::cout << "X: " << player->getScopePosition().x << std::endl;
    std::cout << "Y: " << player->getScopePosition().y << std::endl;
}

void Game::drawObjects()
{
    window.clear(sf::Color::White);
    player->draw(window); //this should draw scope

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




