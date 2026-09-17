#pragma once


#include "enums/Direction.hpp"


class BoardCell
{
private:
    int _row;
    int _col;

public:
    BoardCell(int row, int col);
    int GetRow() const;
    int GetCol() const;
    BoardCell GetNeighborCell(Direction direction);
    BoardCell();
    bool operator==(const BoardCell &other) const;
};