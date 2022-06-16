#include <iostream>
#include<vector>
//#include "SFML/System.hpp"
//#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"
#include "Game.h"


/*
Create timer- start it at 10 seconds
while(timer > 0)
{
    if(clock.getElapsedTime.asseconds > 1.f)
    {
        timer -= 1;
        clock.restart
    }
}


*/





Game::Game()
    :menu(800,600)
{
    // EMPTY
   
}

Game::Game(const int width, const int height)
    : window(sf::VideoMode(width, height), "Speed Hunter"),
    player(std::make_unique<Player>(window)),
    birdPtr(std::make_unique<Bird>()),
    menu(800,600)
{
    window.setFramerateLimit(60);
    initVariables();

    displayNextLevel();


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

    if (!font.loadFromFile("Fonts/RoundyRainbows.ttf"))
    {
        std::cout << "Could not load font" << std::endl;
    }

    currentLevelText1.setFont(font);
    currentLevelText1.setString("Current Level: ");
    currentLevelText1.setPosition(20, 20);

    currentLevelText2.setFont(font);
    currentLevelText2.setString(std::to_string(currentLevel));
    currentLevelText2.setPosition(250, 20);

    scoreText1.setFont(font);
    scoreText1.setString("Score: ");
    scoreText1.setPosition(620, 20);

    scoreText2.setFont(font);
    scoreText2.setString(std::to_string(score));
    scoreText2.setPosition(730, 20);

    timerText.setFont(font);
    timerText.setString(std::to_string(countDownTimer));
    timerText.setPosition(400, 20);

    targetText.setFont(font);
    targetText.setString("Target: ");
    targetText.setPosition(20, 75);


    

    


    /*
    nextLevelText.setFont(font); // roundy rainbows
    nextLevelText.setOutlineColor(sf::Color::Yellow);
    nextLevelText.setOutlineThickness(5);
    nextLevelText.setFillColor(sf::Color::White);
    nextLevelText.setString("Next Level!");
     //nextLevelText.setOrigin(window.getSize().x / 2, window.getSize().y / 2);
    nextLevelText.setCharacterSize(125);
    nextLevelText.setPosition((window.getSize().x - nextLevelText.getLocalBounds().width)/2 , (window.getSize().y - nextLevelText.getLocalBounds().height) /2 - 40  ); // 400 , 300
    */



}

void Game::initVariables()

{
    levelWon = false;
    gameOver = false;
    timeRemaning = true;
    shotFired = false;

}



void Game::displayGameOver()
{
    std::cout << "Game over" << std::endl;
    gameOver = true;
}

void Game::displayNextLevel()
{
    /*
If the level is won figure out way to
- set target bird again
-set vector positions like in initvars
-create vectors
--loop through assign those postions to vectors

targetsprite


*/
    std::cout << "it worked" << std::endl;

    birdVectOne.clear();
    birdVectTwo.clear();

    /*SELECT TARGET BIRD, CREATE VECTORS BASED OFF TARGET BIRD*/

    /*
    * Target bird image of type Bird
    * if brown bird assign targetbirdimage brownbird
    */

    targetBird = BirdType(rand() % 3);

    if (targetBird == BirdType::Brown)
    {
        birdVectOne = createBirdVector(1, 6, 7); // create vects
        birdVectTwo = createBirdVector(1, 7, 6);
        targetBirdImage = brownBird;
        std::cout << "target brown" << std::endl;
    }
    else if (targetBird == BirdType::Blue)
    {
        birdVectOne = createBirdVector(6, 1, 7); // create vects
        birdVectTwo = createBirdVector(7, 1, 6);
        targetBirdImage = blueBird;
        std::cout << " target Blue" << std::endl;
    }
    else if (targetBird == BirdType::Red)
    {
        birdVectOne = createBirdVector(7, 6, 1); // create vects
        birdVectTwo = createBirdVector(6, 7, 1);
        targetBirdImage = redBird;
        std::cout << "target Red" << std::endl;
    }

    //////////////////////////////////////////////////
    /*  ASSIGN POSITIONS FOR VECTORS OF BIRDS   */

    vectOnePos.x = 1950;
    vectOnePos.y = 150;

    vectTwoPos.x = -200;
    vectTwoPos.y = 350;

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
        birdVectTwo[i].getSprite().setScale(-1.75, 1.75); // THIS LINE CAUSING PRBLEMS WITH VECTOR 2 create flipped bird sprite?
        /*I flipped the sprites not taking into consideration their actual positions in the vector*/
        vectTwoPos.x -= 70.f;
    }

    if (currentLevel > 1)
    {
        //display next level next;
    }

    startBirdFlight();





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
            case sf::Event::KeyReleased:
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
        case sf::Keyboard::Up:
            menu.moveUp();
            break;
        case sf::Keyboard::Down:
            menu.moveDown();
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


    if (clock.getElapsedTime().asSeconds() >= 1.f)
    {
        countDownTimer -= 1;
        clock.restart();
        timerText.setString(std::to_string(countDownTimer));
    }

    if (levelWon)
    {
        countDownTimer = 11;
    }
    else if (levelWon == false && countDownTimer < 0)
    {
        gameOver = true;
    }


    //reset the timer
    //if(levelwon)
    // counterDwonTimer = 10;
    // else if levelwon == false && countDownTimer < 0
    // gameover = true;
    targetBirdImage.getSprite().setPosition(150, 70);
    targetBirdImage.getSprite().setScale(1.50, 1.50);
    

    startBirdFlight();


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

  

    //window.draw(birdBloodSprite);
    player->draw(window);
    window.draw(nextLevelText);
    window.draw(currentLevelText1);
    window.draw(currentLevelText2);
    window.draw(scoreText1);
    window.draw(scoreText2);
    window.draw(timerText);
    window.draw(targetText);
    window.draw(targetBirdImage.getSprite());
    menu.draw(window);
    window.display();

}

void Game::startTimer()
{

    /*
    Create timer- start it at 10 seconds
    while(timer > 0)
    {
        if(clock.getElapsedTime.asseconds > 1.f)
        {
            timer -= 1;
            clock.restart
        }
    }


    */

}

void Game::run()
{
    //Add texture here?


    while (window.isOpen())
    {

        handleInputs();

        updateObjects();

        //startTimer();

        if (gameOver)
        {
            displayGameOver();
            return;
        }

        if (levelWon)
        {
            levelWon = false;
            //displayNextLevel();
            //return;
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

/*
If the level is won figure out way to
-set vector positions
-create vectors
--assign those postions to vectors

*/


void Game::playerShoots(const sf::Event& ev)
{

    shotFired = true;
    if (shotFired)
    {
        for (int i = 0; i < birdVectOne.size(); ++i)
        {
            //if (birdVectOOne[i].getSprite().getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y))
            /*
            ev.mouseButton.x >= birdVectOne[i].getSprite().getPosition().x &&
                ev.mouseButton.x <= (birdVectOne[i].getSprite().getPosition().x + birdVectOne[i].getSprite().getGlobalBounds().width)
                && ev.mouseButton.y >= birdVectOne[i].getSprite().getPosition().y &&
                (ev.mouseButton.y <= birdVectOne[i].getSprite().getPosition().y + birdVectOne[i].getSprite().getGlobalBounds().height)
            
            */
            if (birdVectOne[i].getSprite().getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y))
            {

                std::cout << "Hit" << std::endl;

                if (birdVectOne[i].getBirdType() == targetBird)
                {
                    //if we hit the correct bird
                    levelWon = true;
                    ++currentLevel;
                    currentLevelText2.setString(std::to_string(currentLevel));
                    score += 100;
                    scoreText2.setString(std::to_string(score));
                    //birdVectOne.erase(birdVectOne.begin() + i);

                    displayNextLevel();

                }
                else
                {
                    //if we hit the incorrect bird
                    //levelWon = false;
                    //gameOver = true;
                    //birdVectOne.erase(birdVectOne.begin() + i);

                    displayGameOver();
                }

            }
        }



        // For vector 2
        for (int i = 0; i < birdVectTwo.size(); ++i)
        {

            /*
            ev.mouseButton.x >= birdVectTwo[i].getSprite().getPosition().x &&
                ev.mouseButton.x <= (birdVectTwo[i].getSprite().getPosition().x + birdVectTwo[i].getSprite().getGlobalBounds().width)
                && ev.mouseButton.y >= birdVectTwo[i].getSprite().getPosition().y &&
                (ev.mouseButton.y <= birdVectTwo[i].getSprite().getPosition().y + birdVectTwo[i].getSprite().getGlobalBounds().height)
            
            */
            if (birdVectTwo[i].getSprite().getGlobalBounds().contains(ev.mouseButton.x, ev.mouseButton.y))
            {
                std::cout << "hit" << std::endl;
                std::cout << "THIS BIRD IS : " << (int)birdVectTwo[i].getBirdType() << std::endl;

                if (birdVectTwo[i].getBirdType() == targetBird) // THIS DOESNT EQUAL TARGETBIRD?
                {
                    levelWon = true;
                    ++currentLevel;
                    currentLevelText2.setString(std::to_string(currentLevel));
                    score += 100;
                    scoreText2.setString(std::to_string(score));

                    //birdVectTwo.erase(birdVectTwo.begin() + i - 1);


                    displayNextLevel();
                }
                else
                {
                    //birdVectTwo.erase(birdVectTwo.begin() + i - 1);

                    displayGameOver();
                }
            }

        }


    }
}


