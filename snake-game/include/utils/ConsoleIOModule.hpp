#pragma once

#include <iostream>
#include <vector>

#include "IOModule.hpp"
#include "Snake.hpp"

class ConsoleIOModule : public IOModule
{
public:
    ConsoleKey ReadKey() override;

    void Draw(const Snake *snake) override;
};