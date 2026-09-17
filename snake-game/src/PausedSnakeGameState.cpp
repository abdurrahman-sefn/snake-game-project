#include <thread>
#include <chrono>
#include <stdexcept>

#include "snake-game-state/PausedSnakeGameState.hpp"



PausedSnakeGameState::PausedSnakeGameState(SnakeGameStatesPool *statesPool)
{
    _statesPool = statesPool;
}

PausedSnakeGameState::~PausedSnakeGameState()
{
    _statesPool = nullptr;
}

ISnakeGameState *PausedSnakeGameState::Run(Snake *snake, IOModule *iOModule)
{
    while (true)
    {
        ConsoleKey input = iOModule->ReadKey();
        switch (input)
        {
        case ConsoleKey::Escape:
            return nullptr;
        case ConsoleKey::Pause:
            return _statesPool->GetRunningState();

        default:
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
