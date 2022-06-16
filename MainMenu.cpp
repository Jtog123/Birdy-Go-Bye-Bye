#include"MainMenu.h"
#include<iostream>

using namespace std;

MainMenu::MainMenu(float width, float height)
{
	if (!menuFont.loadFromFile("Fonts/RoundyRainbows.ttf"))
	{
		cout << "Couldnt load menu font!" << endl;
	}
	mainMenu[0].setFont(menuFont);
	mainMenu[0].setString("Play");
	mainMenu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_MAIN_MENU + 1)));

	mainMenu[1].setFont(menuFont);
	mainMenu[1].setString("Quit");
	mainMenu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_MAIN_MENU + 1) * 2));

	mainMenuSelected = 0;
}

void MainMenu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_MAIN_MENU; ++i)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::moveDown()
{
	if (mainMenuSelected + 1 <= MAX_MAIN_MENU)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		++mainMenuSelected;
		if (mainMenuSelected == 2)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
	}
}

void MainMenu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);

		--mainMenuSelected;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 1;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);
	}
}

MainMenu::~MainMenu()
{
}
