#pragma once

#include "BoardCell.hpp"

class SnakeNode
{
private:
    BoardCell _cell;
    char _representedByChar;

public:
    SnakeNode(BoardCell cell, char representedByChar);
    BoardCell GetNodeCell() const;
    void SetBoardCell(BoardCell cell);
    char GetRepresentingChar() const;
};