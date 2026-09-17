#pragma once

#include <vector>
#include <string>

#include "enums/BoardCellState.hpp"
#include "BoardCell.hpp"
#include "utils/Random.hpp"

class Board
{
private:
    static Random _random;
    std::vector<std::vector<BoardCellState>> _grid;
    static void FillGridRandomly(std::vector<std::vector<BoardCellState>> &grid, int count, BoardCellState targetState);
    static BoardCell _GetRandomCell(int minRow, int maxRow, int minCol, int maxCol);
    static BoardCell GetRandomCell(const std::vector<std::vector<BoardCellState>> &grid);
    char _emptyCellRepresentation;
    char _foodCellRepresentation;
    char _obstacleCellRepresentation;
    char BoardCellStateToChar(BoardCellState cellState) const;

public:
    Board(int rows, int cols, char emptyCellRepresentation, char foodCellRepresentation, char obstacleCellRepresentation);
    
    void SetCell(BoardCell cell, BoardCellState cellState);

    bool IsValidCell(BoardCell cell) const;
    bool IsFreeCell(BoardCell cell) const;
    BoardCellState GetCellState(BoardCell cell) const;
    BoardCell GetRandomCell() const;
    BoardCell GetRandomCell(BoardCell vertex1, BoardCell vertix2) const;
    std::vector<std::vector<char>> *GetGridToDraw() const;
    int CountRows() const;
    int CountCols() const;
};