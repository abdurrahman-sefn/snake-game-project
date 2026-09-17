#pragma once

#include "ISnakeGameState.hpp"
#include "SnakeGameStatesPool.hpp"

class PausedSnakeGameState : public ISnakeGameState
{
    SnakeGameStatesPool *_statesPool;

public:
    PausedSnakeGameState(SnakeGameStatesPool *statesPool);
    ~PausedSnakeGameState() override;
    ISnakeGameState *Run(Snake* snake, IOModule* iOModule) override;
};