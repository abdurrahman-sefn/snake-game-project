#include "snake-game-state/SnakeGameStatesPool.hpp"
#include "snake-game-state/PausedSnakeGameState.hpp"
#include "snake-game-state/RunningSnakeGameState.hpp"

SnakeGameStatesPool::SnakeGameStatesPool()
{
    _runningState = nullptr;
    _pausedState = nullptr;
}

SnakeGameStatesPool::~SnakeGameStatesPool()
{
    delete _runningState;
    _runningState = nullptr;

    delete _pausedState;
    _pausedState = nullptr;
}

ISnakeGameState *SnakeGameStatesPool::GetPausedState()
{
    if (_pausedState == nullptr)
        _pausedState = new PausedSnakeGameState(this);

    return _pausedState;
}

ISnakeGameState *SnakeGameStatesPool::GetRunningState()
{
    if (_runningState == nullptr)
        _runningState = new RunningSnakeGameState(this);

    return _runningState;
}