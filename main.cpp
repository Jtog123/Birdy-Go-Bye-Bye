#include <iostream>
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
//#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
//#include "SFML/Network.hpp"


int main()
{
    // create the window

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    //sf::CircleShape circ(100.f, 100.f);
    //circ.setFillColor(sf::Color::Blue);
    sf::Texture texture;
    texture.loadFromFile("testsheet12.png");

    sf::IntRect rect(0, 0, 32, 32);
    sf::Sprite sprite(texture, rect);
    sprite.setScale(3, 3);

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

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