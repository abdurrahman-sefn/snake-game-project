#pragma once

#include <vector>
#include <stack>

#include "Board.hpp"
#include "SnakeNode.hpp"
#include "enums/Direction.hpp"

class Snake
{
private:
    Board *_board;
    std::vector<SnakeNode *> _sankeNodes;
    Direction _lastDirection;
    BoardCell _lastLeftNode;
    static BoardCell ChooseCellForHead(Board *board);
    static BoardCell ExtendCell(BoardCell curCell, Board *board);
    void Moving(Direction direction);
    char _headNodeRepresentation;
    char _bodyNodeRepresentation;

public:
    Snake(Board *board, char headNodeRepresentation, char bodyNodeRepresentation);
    bool Move();
    bool Move(Direction direction);
    SnakeNode *GetHead() const;
    SnakeNode *GetTail() const;
    std::vector<std::vector<char>> *GetGridToDraw() const;
    ~Snake();
};