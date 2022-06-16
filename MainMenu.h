#ifndef  MAINMENU_H
#define MAINEMENU_H
#define MAX_MAIN_MENU 2
#include "SFML/Graphics.hpp"

class MainMenu
{
	private:
		int mainMenuSelected;
		sf::Font menuFont;
		sf::Text mainMenu[MAX_MAIN_MENU];

	public:
		MainMenu(float width, float height);

		void draw(sf::RenderWindow& window);

		void moveDown();

		void moveUp();

		//function to move selection up
		//function to move selection down

		int mainMenuPressed()
		{
			return mainMenuSelected;
		}

		~MainMenu();

};
#endif // ! MAINMENU_H

