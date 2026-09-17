#include "snake-game/include/SnakeGame.hpp"

int main()
{
    SnakeGame* game = new SnakeGame();
    game->Run();
    delete game;
    return 0;
}