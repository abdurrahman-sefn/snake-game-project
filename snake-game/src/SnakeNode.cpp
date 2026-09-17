#include "SnakeNode.hpp"


SnakeNode::SnakeNode(BoardCell cell, char representedByChar)
{
    _cell = cell;
    _representedByChar = representedByChar;
}

char SnakeNode::GetRepresentingChar() const
{
    return _representedByChar;
}

BoardCell SnakeNode::GetNodeCell() const
{
    return _cell;
}

void SnakeNode::SetBoardCell(BoardCell cell)
{
    _cell = cell;
}