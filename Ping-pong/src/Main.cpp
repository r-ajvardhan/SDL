#include "Game.h"

int main(int argv, char* argc[])
{
    Game game;

    if(game.Init())
    {
        game.gameLoop();
    }

    game.shutDown(); 

    return 0;
}