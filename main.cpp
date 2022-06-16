#include "Game.h"
#include "Player.h"

int main()
{
    std::srand(time(0)); 
    Game game(800,600);
    game.run();

    /*
    create menu and call game.run when play is clicked?
    */
 
    return 0;
}