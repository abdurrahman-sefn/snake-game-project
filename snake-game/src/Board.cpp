#include "Board.hpp"

#include <stdexcept>

Random Board::_random = Random();

BoardCell Board::_GetRandomCell(int minRow, int maxRow, int minCol, int maxCol)
{
    int row = _random.Next(minRow, maxRow);
    int col = _random.Next(minCol, maxCol);

    return BoardCell(row, col);
}

void Board::FillGridRandomly(std::vector<std::vector<BoardCellState>> &grid, int count, BoardCellState targetState)
{
    for (int i = 0; i < count; ++i)
    {
        BoardCell randomCell = GetRandomCell(grid);
        grid[randomCell.GetRow()][randomCell.GetCol()] = targetState;
    }
}

BoardCell Board::GetRandomCell(const std::vector<std::vector<BoardCellState>> &grid)
{
    return _GetRandomCell(0, grid.size() - 1, 0, grid[0].size());
}

BoardCell Board::GetRandomCell() const
{
    return GetRandomCell(_grid);
}

BoardCell Board::GetRandomCell(BoardCell vertix1, BoardCell vertix2) const
{
    if (!IsValidCell(vertix1) || !IsValidCell(vertix2))
    {
        throw std::out_of_range("Invalid Range!");
    }
    return _GetRandomCell(vertix1.GetRow(), vertix2.GetRow(),
                          vertix1.GetCol(), vertix2.GetCol());
}

std::vector<std::vector<char>> *Board::GetGridToDraw() const
{
    auto grid = new std::vector<std::vector<char>>(CountRows(), std::vector<char>(CountCols()));
    for (int r = 0; r < CountRows(); ++r)
    {
        for (int c = 0; c < CountCols(); ++c)
        {
            (*grid)[r][c] = BoardCellStateToChar(_grid[r][c]);
        }
    }
    return grid;
}

Board::Board(int rows, int cols, char emptyCellRepresentation, char foodCellRepresentation, char obstacleCellRepresentation)
{
    _emptyCellRepresentation = emptyCellRepresentation;
    _foodCellRepresentation = foodCellRepresentation;
    _obstacleCellRepresentation = obstacleCellRepresentation;

    _grid = std::vector<std::vector<BoardCellState>>(rows, std::vector<BoardCellState>(cols, BoardCellState::Free));
    int obstacles = rows * cols / 10;
    FillGridRandomly(_grid, obstacles, BoardCellState::Obstacle);

    int food = rows * cols / 9;
    FillGridRandomly(_grid, obstacles, BoardCellState::Food);
}

int Board::CountRows() const
{
    return _grid.size();
}

int Board::CountCols() const
{
    return _grid[0].size();
}

char Board::BoardCellStateToChar(BoardCellState cellState) const
{
    switch (cellState)
    {
    case BoardCellState::Free:
        return _emptyCellRepresentation;
    case BoardCellState::Food:
        return _foodCellRepresentation;
    case BoardCellState::Obstacle:
        return _obstacleCellRepresentation;
    case BoardCellState::Busy:
    default:
        return '?';
    }
}

bool Board::IsValidCell(BoardCell cell) const
{
    return cell.GetRow() >= 0 && cell.GetRow() < _grid.size() && cell.GetCol() >= 0 && cell.GetCol() < _grid[cell.GetRow()].size();
}

bool Board::IsFreeCell(BoardCell cell) const
{
    return IsValidCell(cell) &&
           (_grid[cell.GetRow()][cell.GetCol()] == BoardCellState::Free || _grid[cell.GetRow()][cell.GetCol()] == BoardCellState::Food);
}

BoardCellState Board::GetCellState(BoardCell cell) const
{
    if (!IsValidCell(cell))
    {
        throw std::out_of_range("Invalid cell");
    }
    return _grid[cell.GetRow()][cell.GetCol()];
}

void Board::SetCell(BoardCell cell, BoardCellState cellState)
{
    _grid[cell.GetRow()][cell.GetCol()] = cellState;
}