#pragma once

#include "ISnakeGameState.hpp"
#include "SnakeGameStatesPool.hpp"


class RunningSnakeGameState : public ISnakeGameState
{
    SnakeGameStatesPool *_statesPool;

public:
    RunningSnakeGameState(SnakeGameStatesPool *statesPool);
    ~RunningSnakeGameState() override;
    ISnakeGameState *Run(Snake *snake, IOModule *iOModule) override;
};