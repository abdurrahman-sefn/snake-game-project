#include <stdexcept>
#include <algorithm>

#include "Snake.hpp"

bool IsOpposedDirections(Direction d1, Direction d2)
{
    switch (d1)
    {
    case Direction::Up:
        return d2 == Direction::Down;
    case Direction::Left:
        return d2 == Direction::Right;
    case Direction::Down:
        return d2 == Direction::Up;
    case Direction::Right:
        return d2 == Direction::Left;

    default:
        throw std::logic_error("Not handled direction");
    }
}

BoardCell Snake::ChooseCellForHead(Board *board)
{
    int rows = board->CountRows();
    int cols = board->CountCols();

    int minRow = rows / 4;
    int maxRow = minRow * 3;

    int minCol = cols / 4;
    int maxCol = minCol * 3;

    BoardCell headCell = board->GetRandomCell(BoardCell(minRow, minCol), BoardCell(maxRow, maxCol));
    board->SetCell(headCell, BoardCellState::Free);
    return headCell;
}

BoardCell Snake::ExtendCell(BoardCell curCell, Board *board)
{
    BoardCell left = curCell.GetNeighborCell(Direction::Left);
    if (board->IsValidCell(left))
    {
        board->SetCell(left, BoardCellState::Free);
    }
    return left;
}

void Snake::Moving(Direction direction)
{
    BoardCell destination = GetHead()->GetNodeCell().GetNeighborCell(direction);

    _lastDirection = direction;
    _lastLeftNode = GetTail()->GetNodeCell();

    for (int idx = _sankeNodes.size() - 1; idx > 0; --idx)
    {
        _sankeNodes[idx]->SetBoardCell(_sankeNodes[idx - 1]->GetNodeCell());
    }

    _sankeNodes[0]->SetBoardCell(destination);
}

Snake::Snake(Board *board, char headNodeRepresentation, char bodyNodeRepresentation)
{
    _headNodeRepresentation = headNodeRepresentation;
    _bodyNodeRepresentation = bodyNodeRepresentation;
    _board = board;
    _lastDirection = Direction::Right;

    BoardCell headLocation = ChooseCellForHead(board);
    SnakeNode *head = new SnakeNode(headLocation, _headNodeRepresentation);

    _sankeNodes.push_back(head);
    _sankeNodes.push_back(new SnakeNode(headLocation = ExtendCell(headLocation, board), _bodyNodeRepresentation));
    _sankeNodes.push_back(new SnakeNode(headLocation = ExtendCell(headLocation, board), _bodyNodeRepresentation));
}

bool Snake::Move()
{
    return Move(_lastDirection);
}

bool Snake::Move(Direction direction)
{
    BoardCell destination = GetHead()->GetNodeCell().GetNeighborCell(direction);
    
    if (IsOpposedDirections(_lastDirection, direction))
    {
        return Move(_lastDirection);
    }

    if (!_board->IsFreeCell(destination))
    {
        return false;
    }
    
    if (std::find_if(_sankeNodes.begin(), _sankeNodes.end(), [destination](SnakeNode *node)
                     { return node->GetNodeCell() == destination; }) == _sankeNodes.end())
    {
        BoardCellState destinationState = _board->GetCellState(destination);
        Moving(direction);
        if (destinationState == BoardCellState::Food)
        {
            _board->SetCell(destination, BoardCellState::Free);
            _sankeNodes.push_back(new SnakeNode(_lastLeftNode, _bodyNodeRepresentation));
        }
        return true;
    }
    return false;
}

SnakeNode *Snake::GetHead() const
{
    return _sankeNodes.front();
}

SnakeNode *Snake::GetTail() const
{
    return _sankeNodes.back();
}

std::vector<std::vector<char>> *Snake::GetGridToDraw() const
{
    auto grid = _board->GetGridToDraw();
    for (auto &node : _sankeNodes)
    {
        (*grid)[node->GetNodeCell().GetRow()][node->GetNodeCell().GetCol()] = node->GetRepresentingChar();
    }
    return grid;
}

Snake::~Snake()
{
    for (int i = 0; i < _sankeNodes.size(); ++i)
    {
        delete _sankeNodes[i];
        _sankeNodes[i] = nullptr;
    }
}