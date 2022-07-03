#include "Game.h"
#include "Player.h"

int main()
{
    std::srand(time(0)); 
    Game game(800,600);
    game.run();

    return 0;
}