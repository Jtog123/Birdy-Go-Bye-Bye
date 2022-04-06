#include "Game.h"
#include "Player.h"

int main()
{

    //Game game;
    //game.run();
    // 
    // 
    // create the window

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    //sf::CircleShape circ(100.f, 100.f);
    //circ.setFillColor(sf::Color::Blue);
    sf::Texture texture;
    texture.loadFromFile("testsheet12.png");

    float gameSeconds = 5.f;

    sf::IntRect rect(0, 0, 32, 32);
    sf::Sprite sprite(texture, rect);
    sprite.setScale(3, 3);

    sf::Clock clock;


    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }



        std::cout << elapsed.asSeconds() << std::endl;
        if (elapsed.asSeconds() >= 3.f)
        {
            std::cout << "GAME OVER!" << std::endl;
            //clock.restart();  
        }


        /*
        if (clock.getElapsedTime().asSeconds() > .1f)
        {
            if (rect.left == 224)
            {
                rect.left = 0;
            }
            else
            {
                rect.left += 32;
            }
            sprite.setTextureRect(rect);
            clock.restart();
        }
        */


        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        //window.draw(circ);
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}