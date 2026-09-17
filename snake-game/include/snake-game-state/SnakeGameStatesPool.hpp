#pragma once

#include "ISnakeGameState.hpp"

class SnakeGameStatesPool
{
    ISnakeGameState *_runningState;
    ISnakeGameState *_pausedState;

public:
    SnakeGameStatesPool();

    ISnakeGameState *GetRunningState();
    ISnakeGameState *GetPausedState();

    ~SnakeGameStatesPool();
};