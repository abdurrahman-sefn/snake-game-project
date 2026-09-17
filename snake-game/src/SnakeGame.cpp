#include "SnakeGame.hpp"
#include "utils/ConsoleIOModule.hpp"

SnakeGame::SnakeGame()
{
    _board = nullptr;
    _snake = nullptr;
    _gameState = nullptr;
    _statesPool = nullptr;
    _iOModule = nullptr;
}

void SnakeGame::Clean()
{
    delete _snake;
    _snake = nullptr;

    delete _board;
    _board = nullptr;

    _gameState = nullptr;

    delete _statesPool;
    _statesPool = nullptr;

    delete _iOModule;
    _iOModule = nullptr;
}

SnakeGame::~SnakeGame()
{
    Clean();
}

void SnakeGame::Run()
{
    Build();

    while (_gameState != nullptr)
    {
        _gameState = _gameState->Run(_snake, _iOModule);
    }

    Clean();
}

void SnakeGame::Build()
{
    _board = new Board(10, 30, '.', '+', '#');
    _snake = new Snake(_board, 'o', 'x');
    _statesPool = new SnakeGameStatesPool();
    _gameState = _statesPool->GetRunningState();
    _iOModule = new ConsoleIOModule();
}