#include <chrono>
#include <thread>
#include <stdexcept>

#include "snake-game-state/RunningSnakeGameState.hpp"

Direction GetDirectionOfKey(ConsoleKey key)
{
    switch (key)
    {
    case ConsoleKey::Down:
        return Direction::Down;
    case ConsoleKey::Up:
        return Direction::Up;
    case ConsoleKey::Left:
        return Direction::Left;
    case ConsoleKey::Right:
        return Direction::Right;
    default:
        throw std::invalid_argument("Invalid direction Key.");
    }
}

RunningSnakeGameState::RunningSnakeGameState(SnakeGameStatesPool *statesPool)
{
    _statesPool = statesPool;
}

RunningSnakeGameState::~RunningSnakeGameState()
{
    _statesPool = nullptr;
}

ISnakeGameState *RunningSnakeGameState::Run(Snake *snake, IOModule *iOModule)
{
    while (true)
    {
        iOModule->Draw(snake);
        ConsoleKey input = iOModule->ReadKey();
        bool success = false;

        switch (input)
        {
        case ConsoleKey::Pause:
        case ConsoleKey::Escape:
            return _statesPool->GetPausedState();
        case ConsoleKey::None:
            success = snake->Move();
            break;
        default:
            success = snake->Move(GetDirectionOfKey(input));
            break;
        }

        if (success == false)
            return nullptr;
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}