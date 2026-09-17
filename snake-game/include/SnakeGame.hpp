#pragma once

#include "Board.hpp"
#include "Snake.hpp"
#include "snake-game-state/ISnakeGameState.hpp"
#include "snake-game-state/SnakeGameStatesPool.hpp"
#include "utils/IOModule.hpp"

class SnakeGame
{
private:
    Board *_board;
    Snake *_snake;
    ISnakeGameState *_gameState;
    SnakeGameStatesPool *_statesPool;
    IOModule *_iOModule;

    void Build();
    void Clean();

public:
    SnakeGame();
    void Run();
    ~SnakeGame();
};
