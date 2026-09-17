#include "BoardCell.hpp"

BoardCell::BoardCell(int row, int col) : _row(row), _col(col) {}
BoardCell::BoardCell() : BoardCell(0, 0) {}

bool BoardCell::operator==(const BoardCell &other) const
{
    return GetRow() == other.GetRow() && GetCol() == other.GetCol();
}

int BoardCell::GetRow() const
{
    return _row;
}

int BoardCell::GetCol() const
{
    return _col;
}

BoardCell BoardCell::GetNeighborCell(Direction direction)
{
    int row = _row, col = _col;
    switch (direction)
    {
    case Direction::Right:
        ++col;
        break;
    case Direction::Down:
        ++row;
        break;
    case Direction::Left:
        --col;
        break;
    case Direction::Up:
        --row;
    default:
        break;
    }
    return BoardCell(row, col);
}