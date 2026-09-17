#pragma once

#include "../Snake.hpp"
#include "../utils/IOModule.hpp"

class ISnakeGameState
{
public:
    virtual ISnakeGameState *Run(Snake *snake, IOModule *iOModule) = 0;
    virtual ~ISnakeGameState();
};