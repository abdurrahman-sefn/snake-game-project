#pragma once

#include "enums/ConsoleKey.hpp"
#include "Snake.hpp"

class IOModule
{
public:
    virtual ConsoleKey ReadKey() = 0;
    virtual void Draw(const Snake* snake) = 0;
};